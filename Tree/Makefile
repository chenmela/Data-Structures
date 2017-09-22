TARGET = tree
CFLAGS = -Wall -Wextra -DDEBUG -g -pedantic -std=c++14
SOURCE = Tree.h tree.cpp
all: $(TARGET)

$(TARGET): Tree.h $(TARGET).o
	g++ $(TARGET).o -o $(TARGET)

$(TARGET).o: $(TARGET).cpp
	g++ $(CFLAGS) -c $(TARGET).cpp -o $(TARGET).o

run: all
	./$(TARGET)

checkmem: all
	valgrind ./$(TARGET)

clean:
	-rm *.o $(TARGET)
