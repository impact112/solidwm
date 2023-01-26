
# solidwm make configuration

VERSION = 0.2.4

PREFIX = /usr/local

# libraries

INCS = `pkg-config --cflags xft x11 xinerama xcb xcb-res x11-xcb xrender imlib2 pango pangoxft`
LIBS = `pkg-config --libs xft x11 xinerama xcb xcb-res x11-xcb xrender imlib2 pango pangoxft`

# FreeBSD (uncomment)

#X11INC = /usr/local/include
#X11LIB = /usr/local/lib
#FREETYPEINC = /usr/local/include/freetype2
#FREETYPEINC = ${X11INC}/freetype2

# C flags

CPPFLAGS = -D_DEFAULT_SOURCE -D_BSD_SOURCE -D_POSIX_C_SOURCE=200809L -DVERSION=\"${VERSION}\" ${XINERAMAFLAGS}
CFLAGS   = -std=c99 -pedantic -Wall -Wno-unused-function -Wno-deprecated-declarations -O2 ${INCS} ${CPPFLAGS}
LDFLAGS  = ${LIBS}

# compiler and linker

CC = cc
