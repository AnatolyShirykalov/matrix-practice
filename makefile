CC=g++
CFLAGS=-c
LDFLAGS=
SOURCES=matrix.cpp test.cpp 
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=out

all: $(SOURCES) $(EXECUTABLE)
	rm -rf *.o 	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
	

.c.o:
	$(CC) $(CFLAGS) $< -o $@ 

clean:
	rm -rf *.o 
