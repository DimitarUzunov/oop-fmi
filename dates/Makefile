CC = g++
CFLAGS = -Wall -g

SRCS = main.cpp date.cpp
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
