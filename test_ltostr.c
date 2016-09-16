#include "ltostr.h"
#include <unistd.h>

#define LL(a) a,(sizeof(a)-1)
int main(int argc, char *argv[])
{
	char buf[0x1000];
	write(1,LL("hokay ltostr: 123456789 == "));
	write(1,buf,ltostr(buf,0x1000,123456789,10));
	write(1,LL("\nnegative: -123456789 == "));
	write(1,buf,ltostr(buf,0x1000,-123456789,10));
	write(1,LL("\neven digits: 12345678 == "));
	write(1,buf,ltostr(buf,0x1000,12345678,10));
	write(1,LL("\nhex: DEADBEEF == "));
	write(1,buf,ltostr(buf,0x1000,0xDEADBEEF,0x10));
	write(1,LL("\nnegative hex: -DEADBEEF == "));
	write(1,buf,ltostr(buf,0x1000,-0xDEADBEEFL,0x10));
	write(1,LL("\ndouble: 424.00500 == "));
	write(1,buf,dtostr(buf,0x1000,424.005,10,5));
	write(1,LL("\nnegative double: -424.00500 == "));
	write(1,buf,dtostr(buf,0x1000,-424.005,10,5));
	write(1,LL("\nhexdouble: 123.ABC == "));
	write(1,buf,dtostr(buf,0x1000,
										 0x123 + (double)0xABC / 0x1000,
										 0x10,
										 3));
	write(1,LL("\nnointeger: 0.FDF == "));
	write(1,buf,dtostr(buf,0x1000,
										 (double)0xFDF / 0x1000,
										 0x10,
										 3));
	write(1,LL("\nnegative nointeger: 0.FDF == "));
	write(1,buf,dtostr(buf,0x1000,
										 (double)-0xFDF / 0x1000,
										 0x10,
										 3));
	write(1,LL("\n"));
	return 0;
}
