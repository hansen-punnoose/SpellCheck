CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp spellchecker.cpp bloom_filter.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=spell-check

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
