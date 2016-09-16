LDFLAGS=-lm
CFLAGS=-g
test_ltostr: test_ltostr.o ltostr.o

ltostr.o: ltostr.c

ltostr.c: ltostr.m4.c ltostr.template.c
	m4 -P -I . ltostr.m4.c > $@.temp
	mv $@.temp $@

test_ltostr.o: ltostr.h
.PHONY: all
