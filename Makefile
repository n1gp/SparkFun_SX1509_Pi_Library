#
# libsx1509.so Makefile (Linux)
#
CC=gcc
LINK=g++
OPTIONS=-g -fPIC -O3
#OPTIONS=-g -fPIC

LIBS=-lwiringPi -lpthread

COMPILE=$(CC) $(INCLUDES)

PROGRAM=libsx1509.so

SOURCES=SparkFunSX1509.cpp

HEADERS=SparkFunSX1509_C.h

OBJS=SparkFunSX1509.o \
SparkFunSX1509_C.o

.PHONY: all demo clean

all: $(PROGRAM) $(HEADERS) $(SOURCES)

$(PROGRAM): $(OBJS)
	$(LINK) -shared -z noexecstack -o $(PROGRAM) $(OBJS) $(LIBS)

demo: $(PROGRAM)
	test -s /usr/local/lib/$(PROGRAM) || { echo "sudo make install first, Exiting..."; exit 1; }
	$(LINK) demo.c -lwiringPi -lsx1509 -lpthread -o $@

.cpp.o:
	$(COMPILE) $(OPTIONS) -c -o $@ $<

install: $(PROGRAM)
	cp $(PROGRAM) /usr/local/lib
	cp $(HEADERS) /usr/local/include
	ldconfig

clean:
	-rm -f *.o $(PROGRAM) demo 

