long /* length of resulting string */
ltostr (
				char *str,          /* output string */
				long limit,         /* space in output string */
				long val,           /* value to be converted */
				unsigned base);      /* conversion base       */

long
dtostr(
			 char *str,          /* output string */
			 long limit,         /* space in output string */
			 double val,           /* value to be converted */
			 unsigned base,      /* conversion base       */
			 int precision);   /* how many decimal points to go */
