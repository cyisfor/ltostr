m4_divert(`-1')
m4_include(`c.m4')
m4_divert{[]}m4_dnl
/*
**  LTOSTR.C -- routine and example program to convert a long int to
**  the specified numeric base, from 2 to 36.
**
**  Written by Thad Smith III, Boulder, CO. USA  9/06/91 
**  and contributed to the Public Domain.
*/

#include <stdlib.h>
#include <assert.h>
#include <math.h>

m4_divert({[-1]})
m4_define({[INIT]},{[ldiv_t r           /* result of val / base */]})
m4_define({[REM]}, {[r.rem]})
m4_define({[REDUCE]}, {[r = ldiv (r.quot,base)]})
m4_define({[TERMINATION]}, {[if(r.quot == 0) break]})
m4_define({[NAME]}, {[_signed_ltostr]})
m4_define({[TYPE]}, {[long]})
m4_define({[EXTRA_ARGS]},{[char negative]})
m4_define({[ENSURE_POSITIVE]},
{[if(negative) {
		if(limit == offset) return -1;
		str[offset++] = '-';
	}
	// sign already separated previously
	r.quot = val;
	]})
m4_divert{[]}m4_dnl
#define REVERSE
m4_include({[ltostr.template.c]})

long /* length of resulting string */
ltostr (
				char *str,          /* output string */
				long limit,         /* space in output string */
				long val,           /* value to be converted */
				unsigned base)      /* conversion base       */
{
	char negative = val < 0;
	if(negative) val = -val;
	return _signed_ltostr(str,limit,val,base,negative);
}
/* floating point you can use ltostr for the integral part, and for the
	 fractional part, you can multiply by base and cast to int repeatedly
	 until you get bored.
	 */

m4_divert({[-1]})
m4_define({[INIT]}, {[double frac = val;]})
m4_define({[ABS]}, {[fabs($1)]})
m4_define({[QUOT]}, {[frac]})
m4_define({[REM]}, {[rem]})
m4_define({[REDUCE]}, {[frac = frac * base;
int rem = fmod(frac,base);
frac -= rem;]})
m4_define({[TERMINATION]}, {[if(--precision == 0) break;]})
m4_define({[NAME]}, {[_fracdtostr]})
m4_define({[TYPE]}, {[double]})
m4_define({[EXTRA_ARGS]},{[int precision]})
m4_define({[ENSURE_POSITIVE]},{[/*be always positive*/]})
m4_divert{[]}m4_dnl
#undef REVERSE
m4_include({[ltostr.template.c]})

long dtostr(
						char *str,          /* output string */
						long limit,         /* space in output string */
						double val,           /* value to be converted */
						unsigned base,      /* conversion base       */
						int precision)   /* how many decimal points to go */
{
	/* we have to round at the beginning
		 because calculating the string "19.99999" and then realizing
		 that we need to round up... */
	double smallest = pow(base,-precision);
	val = round(val / smallest) * smallest;
	char negative = val < 0;
	if(negative) val = -val;
	double ipart;
	val = modf(val,&ipart);
	long offset = _signed_ltostr(str,limit,ipart,base,negative);
	if(offset == limit) return -1;
	str[offset++] = '.';
	return offset + _fracdtostr(str + offset, limit - offset,
															val, base, precision);
}
	
						
