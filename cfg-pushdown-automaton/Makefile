CC = g++
CFLAGS = -Wall -g

SRCS = main.cpp dynamic_array.cpp linked_list.cpp linked_stack.cpp cfg.cpp production.cpp pda.cpp state.cpp transition.cpp
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
