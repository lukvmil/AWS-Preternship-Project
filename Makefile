PP := g++

FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic # -Werror 
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS) 

INC := include
SRC := src
OBJ := obj
EXE := exe

all: GraphTest FileSystemTest

GraphTestObjs := $(OBJ)/GraphTest.o
GraphTest: $(GraphTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/GraphTest $(GraphTestObjs)
	$(EXE)/./GraphTest

$(OBJ)/GraphTest.o: $(SRC)/GraphTest.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/GraphTest.cpp -o $@

FileSystemTestObjs := $(OBJ)/FileSystemTest.o
FileSystemTest: $(FileSystemTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/FileSystemTest $(FileSystemTestObjs)
	$(EXE)/./FileSystemTest

$(OBJ)/FileSystemTest.o: $(SRC)/FileSystemTest.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/FileSystemTest.cpp -o $@

TreeTestObjs := $(OBJ)/TreeTest.o
TreeTest: $(TreeTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/TreeTest $(TreeTestObjs)
	$(EXE)/./TreeTest

$(OBJ)/TreeTest.o: $(SRC)/TreeTest.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/TreeTest.cpp -o $@

initialize: 
	mkdir $(OBJ) $(EXE)

clean:
	rm -rf *.o $(OBJ)/* $(EXE)/*
