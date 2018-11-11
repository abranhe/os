PREFIX ?= /usr/local

SRC = cli.c deps/os.c/os.c

OBJ_SRC = $(SRC:.c=.o)

CFLAGS = -D_GNU_SOURCE -std=c99 -I deps/os.c/

LFLAGS = -Wall -Wno-format-y2k -W -Wstrict-prototypes \
	-Wpointer-arith -Wreturn-type -Wcast-qual -Wwrite-strings -Wswitch \
	-Wshadow -Wcast-align -Wbad-function-cast -Wchar-subscripts -Winline \
	-Wnested-externs -Wredundant-decls

os: $(OBJ_SRC)
	$(CC) $(OBJ_SRC) -o $@

.SUFFIXES: .c .o
.c.o:
	$(CC) $< $(CFLAGS) $(LFLAGS) -c -o $@

install: os
	cp -f os $(PREFIX)/bin/os

uninstall:
	rm -f $(PREFIX)/bin/os

run-test: os
	bash ./test.sh

clean:
	rm -f os *.o deps/**/*.o *.gc{ov,da,no}

.PHONY: clean run-test install uninstall
