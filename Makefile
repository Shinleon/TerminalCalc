CC=g++
CXXFLAGS=-Wall -Wpedantic
CXXVERSION=-std=c++17
INCFLAGS=-lncurses
TARGET=main.a

.PHONY: all
all: $(TARGET)

$(TARGET): main.cxx
	$(CC) $(CXXFLAGS) $(CXXVERSION) $^ -o $(TARGET) $(INCFLAGS)

.PHONY: clean
clean: 
	rm -rf *.a
