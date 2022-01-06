all: far

far: main.c
	gcc -g -o $@ main.c

install: main.c
	gcc -g -o far main.c
	cp far /usr/bin
	chown root:root /usr/bin/far
	chmod +x /usr/bin/far

clean:
	-rm far






