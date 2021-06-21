include config.mk

SRC = array.c ft.c line.c runtime.c
OBJ = ${SRC:.c=.o}
CFLAGS = ""

all: options com ind ui

options:
	@echo com build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"

.c.o:
	${CC} -c ${CFLAGS} $<

${OBJ}: config.h ft.h array.h runtime.h config.mk

config.h:
	cp config.def.h $@

com: ${OBJ}
	${CC} -o $@ com.c ${OBJ} ${LDFLAGS}

ind: ${OBJ}
	${CC} -o $@ ind.c ${OBJ} ${LDFLAGS}

ui: ${OBJ}
	${CC} -o $@ ui.c ${OBJ} ${LDFLAGS}

clean:
	rm -f com ind com.o ind.o ui.o ${OBJ}

install: all
	mkdir -p ${BINDIR}

	cp -f com ${BINDIR}
	chmod 755 ${BINDIR}/com

	cp -f ind ${BINDIR}/a+
	chmod 755 ${BINDIR}/a+

	cp -f ui ${BINDIR}/a-
	chmod 755 ${BINDIR}/a-

uninstall:
	rm -f ${BINDIR}/com

.PHONY: all options clean install uninstall
