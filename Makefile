CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=program.cpp functions.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=labone

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
