CC=gcc
CFLAGS=-I../util/
RM=rm -f

NP=4 # padrão, chamar com NP=<num> no bash para mudar

HF=hostfile # padrão, chamar com HF=<arquivo-hostfile> para mudar

DEPS=$(wildcard ../util/*.c)
DEPS_OBJS=$(DEPS:%.c=%.o)

SRCS=$(wildcard *.c)
OBJS=$(SRCS:%.c=%.o)
TARGETS=$(OBJS:%.o=%)

all: clean $(TARGETS)

$(TARGETS) : $(DEPS)
 
clean:
	$(RM) $(TARGETS)
