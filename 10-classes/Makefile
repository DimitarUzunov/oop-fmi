CC = g++
CFLAGS = -Wall -g

SRCS = main.cpp guitar.cpp person.cpp song.cpp album.cpp playlist.cpp polygon.cpp dog.cpp train.cpp book.cpp circle.cpp
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
