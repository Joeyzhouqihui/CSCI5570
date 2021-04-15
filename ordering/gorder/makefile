CC      = g++
SOURCES = main.cpp Util.cpp Graph.cpp UnitHeap.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE=Gorder

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE) : $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o : 
	$(CC) $(CPPFLAGS) $< -o $@

clean:
	rm -f *.o

