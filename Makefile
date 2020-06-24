CC      	?= gcc
LIBS     	= -lm
CFLAGS  += -pedantic -Wall -Wextra -Os
LDFLAGS += -s $(LIBS)

PREFIX 		  ?= /usr/local
BINPREFIX 	= $(PREFIX)/bin

SRC = bryte.c
OBJ = $(SRC:.c=.o)

all: bryte

$(OBJ): $(SRC) Makefile

.c.o:
	$(CC) $(CFLAGS) -DVERSION=\"$(VERSION)\" -c -o $@ $<

bryte: $(OBJ)
		$(CC) -o $@(OBJ) $(LDFLAGS)

install:
		install -D -m 4755 backlight $(DESTDIR)$(BINPREFIX)/bryte

uninstall:
		rm -rf $(DESTDIR)$(BINPREFIX)/bryte

clean:
		rm -rf $(OBJ) bryte

.PHONY: all clean install uninstall
