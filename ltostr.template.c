#include <stdlib.h>
#include <assert.h>

long /* length of resulting string */
NAME (
				char *str,          /* output string */
				long limit,         /* space in output string */
				TYPE val,           /* value to be converted */
				unsigned base,      /* conversion base       */
				EXTRA_ARGS)
{
	INIT;

	assert(base <= 36);      /* 0-9a-z only gives us 36 numerals! */
	long offset = 0;
	ENSURE_POSITIVE;
	for(;;) {
		if(limit == offset) return -1;
		REDUCE;
		str[offset++] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[(int)REM];
		
		TERMINATION;
	}

#ifdef REVERSE
#undef REVERSE
	long i;
	long bottom = negative ? 1 : 0;
	long top = negative ? offset : offset-1;
	for(i=bottom;i<(top+1)>>1;++i) {
		char temp = str[i];
		str[i] = str[top-i];
		str[top-i] = temp;
	}
#endif
	return offset;
}
