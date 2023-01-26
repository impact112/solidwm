# solidwm
# See LICENSE file for copyright and license details.

include config.mk

SRC = drw.c solidwm.c util.c
OBJ = ${SRC:.c=.o}

all: options solidwm

options:
	@echo solidwm build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"

.c.o:
	${CC} -c ${CFLAGS} $<

${OBJ}: config.mk config.h

config.h:
	cp config.def.h $@

solidwm: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}

clean:
	rm -f solidwm ${OBJ}

install: all
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f solidwm ${DESTDIR}${PREFIX}/bin
	cp -f solidwmc ${DESTDIR}${PREFIX}/bin
	mkdir -p /usr/share/xsessions
	cp -f xsessions/* /usr/share/xsessions
	chmod 755 ${DESTDIR}${PREFIX}/bin/solidwm
	chmod 755 ${DESTDIR}${PREFIX}/bin/solidwmc
	mkdir -p ~/.config/solidwm/default
	cp -rn examples/profile/* ~/.config/solidwm/default

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/solidwm
	rm -f ${DESTDIR}${PREFIX}/bin/solidwmc
	rm -f /usr/share/xsessions/solidwm.desktop

.PHONY: all options clean install uninstall
