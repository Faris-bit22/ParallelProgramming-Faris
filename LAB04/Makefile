CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = vector_demo
SOURCES = main.c vector.c

all: $(TARGET)

$(TARGET): $(SOURCES) vector.h
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all run clean