CC=gcc
CFLAGS=

SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c, %.o, $(SRCS))
TARGET = $(patsubst %.c, %, $(SRCS))

all:$(TARGET)
%:%.c
	rm -rf *.dSYM
	rm -rf *~
	indent $<
#	$(CC) -g -m32 -Wall $(CFLAGS) $< -o $@
	$(CC) -g -Wall $(CFLAGS) $< -o $@
	rm -f *.BAK >&/dev/null
clean:
	rm -f $(TARGET) *~
