CC = g++
CFLAGS = -Wall -g

SRCS = main.cpp static_stack.cpp dynamic_stack.cpp linked_stack.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = main

.PHONY: clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) *.o *~ $(TARGET)
