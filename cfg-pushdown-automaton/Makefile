CC = g++
CFLAGS = -Wall -g

SRCS = dynamic_array.cpp linked_list.cpp linked_stack.cpp production.cpp state.cpp transition.cpp cfg.cpp pda.cpp main.cpp
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
