CC      = gcc
CFLAGS  = -Wall -Wextra -std=c99

TARGET  = editor
SRCS    = main.c canvas.c shapes.c objects.c
OBJS    = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
