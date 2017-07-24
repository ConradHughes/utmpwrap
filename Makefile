CFLAGS:=-pedantic -Wall -DUTEMPTER_DEBUG=1
LDFLAGS:=-lutempter

utmp_wrap: utmp_wrap.c

clean:
	rm -f utmp_wrap utmp_wrap.o *~
