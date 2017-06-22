CC=gcc
CFLAGS=-I../include/
LDFLAGS=-lm -fopenmp
RM=rm -f


DEPS=$(wildcard ../util/*.c)
DEPS_OBJS=$(DEPS:%.c=%.o)

SRCS=$(wildcard *.c)
OBJS=$(SRCS:%.c=%.o)
TARGETS=$(OBJS:%.o=%)

all: clean $(TARGETS)

$(TARGETS) : $(DEPS)
	$(CC) $(CFLAGS) $(SRCS) $< -o $@ $(LDFLAGS)
 
clean:
	$(RM) $(TARGETS)
