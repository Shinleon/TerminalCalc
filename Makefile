CC=g++
CXXFLAGS=-Wall -Wpedantic
CXXVERSION=-std=c++17
INCFLAGS=-lncurses -lpanel
TARGET=main.a

.PHONY: all
all: $(TARGET) 

$(TARGET): main.cxx 
	$(CC) $(CXXFLAGS) $(CXXVERSION) $^ -o $(TARGET) $(INCFLAGS)

movingBox.a: movingBox.cxx
	$(CC) $(CXXFLAGS) $(CXXVERSION) $^ -o $@ $(INCFLAGS)

textfile.a: textfile.cxx
	$(CC) $(CXXFLAGS) $(CXXVERSION) $^ -o $@ $(INCFLAGS)

.PHONY: clean
clean: 
	rm -rf *.a
