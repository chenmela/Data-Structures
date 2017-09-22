TARGET = queue
CFLAGS = -Wall -Wextra -DDEBUG -g -pedantic -std=c++14
SOURCE = Queue.h QueueNode.h queue.cpp

all: $(TARGET)

$(TARGET): Queue.h QueueNode.h $(TARGET).o
	g++ $(TARGET).o -o $(TARGET)

$(TARGET).o: $(TARGET).cpp
	g++ $(CFLAGS) -c $(TARGET).cpp -o $(TARGET).o

run: all
	./$(TARGET)

checkmem: all
	valgrind ./$(TARGET)

clean:
	-rm *.o $(TARGET)
