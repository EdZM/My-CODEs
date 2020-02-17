COMPILER=g++

OP=3
MAIN_NAME=main
MAIN_OBJ=main.o
OBJ1=matrix.o
OBJ2=searches.o

OBJECTS= $(OBJ1) $(OBJ2)

MAINCFILE=main.cpp
CFILE1=matrix.cpp
CFILE2=searches.cpp

HFILE1=matrix.hpp
HFILE2=searches.hpp

HEADER_FILES= $(HFILE1) $(HFILE2)

TEST_FILE=../mazes/maze150_150-1.txt


all: compile run

compile: main

run: compile
	./main $(OP)

test: compile run_test clean 

run_test: compile 
	./main $(OP) < $(TEST_FILE)

main: $(MAIN_OBJ) $(OBJECTS) 
	$(COMPILER) $(MAIN_OBJ) $(OBJECTS) -o $(MAIN_NAME)


$(MAIN_OBJ): $(MAINCFILE) $(HEADER_FILES)
	$(COMPILER) -c $(MAINCFILE) -o $(MAIN_OBJ)

$(OBJ1): $(CFILE1) $(HFILE1)
	$(COMPILER) -c $(CFILE1) -o $(OBJ1)

$(OBJ2): $(CFILE2) $(HFILE2)
	$(COMPILER) -c $(CFILE2) -o $(OBJ2)

clean:
	@rm -f *.o $(MAIN_NAME)
