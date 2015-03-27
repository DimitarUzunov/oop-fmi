CC = g++
CFLAGS = -Wall -g

SRCS = main.cpp guitar.cpp person.cpp song.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = main

.PHONY: depend clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) *.o *~ $(TARGET)

depend: $(SRC)
	makedepend $^
