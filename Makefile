CXX=g++
CXXFLAGS= -c -Wall
SOURCES= main.cpp stack_utils.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=Stack

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@

.cpp.o:
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	@rm -f *.o
	@rm -f Stack
	@echo '.o files are cleaned'
