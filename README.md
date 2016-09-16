This is just my embellishment on the ltostr that Thad Smith III made and released into public domain, because I hate having to `#include <stdio.h>` just to format an integer, and why can’t we format floating point numbers in hexadecimal?

So, that’s what this does. Requires m4 to build, because I also hate not being able to look at the intermediary code to see what went wrong, and erasing all tabulature and cramming everything on one line actually doesn’t make things easier to debug. I’m talking to you, CPP.

Basically:
`$ make`

...and it’ll build a test program. You can copy ltostr.o to wherever you want to use it, or ltostr.c (which is generated), and the m4 requirement goes away. Basically, the ltostr function Thad Smith thought up is awesome, and I wrote a version of it for (fractional) floating point numbers which was almost identical, except with some types and operations swapped around. Only three hours later and ltostr was turned into a template, for m4 macros to substitute stuff around. Wait, I mean four hours. Dammit did I really just spend 4 hours on nothing but formatting numbers as strings?

example output:
```
$ ./test_ltostr
hokay ltostr: 123456789 == 123456789
negative: -123456789 == -123456789
even digits: 12345678 == 12345678
hex: DEADBEEF == DEADBEEF
negative hex: -DEADBEEF == -DEADBEEF
double: 424.00500 == 424.00500
negative double: -424.00500 == -424.00500
hexdouble: 123.ABC == 123.ABC
nointeger: 0.FDF == 0.FDF
negative nointeger: 0.FDF == -0.FDF
```
