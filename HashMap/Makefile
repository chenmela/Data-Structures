TARGET = hashmapTester
CFLAGS = -Wall -Wextra -DDEBUG -g -pedantic -std=c++14
SOURCE = HashMap.h hashmapTester.cpp

all: $(TARGET)

$(TARGET): $(TARGET).o
	g++ $(TARGET).o -o $(TARGET)

$(TARGET).o: $(TARGET).cpp HashMap.h
	g++ $(CFLAGS) -c $(TARGET).cpp -o $(TARGET).o

run: all
	./$(TARGET)

checkmem: all
	valgrind ./$(TARGET)

clean:
	rm *.o $(TARGET)
