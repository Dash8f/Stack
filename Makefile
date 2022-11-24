CXX=g++
CXXFLAGS= -c -Wall
SOURCES= cmp_funcs.cpp main.cpp str_funcs.cpp WTF_funcs.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=Onegin

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@

.cpp.o:
	$(CXX) $(CXXFLAGS) $< -o $@
