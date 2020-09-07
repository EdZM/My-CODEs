COMPILER=g++

OP=shurables
MAIN_NAME=main
MAIN_OBJ=main.o
OBJ1=matrix.o
OBJ2=dfs.o
OBJ3=bfs.o
OBJ4=a.o
OBJ5=a_star.o

OBJECTS= $(OBJ1) $(OBJ2) $(OBJ3)  $(OBJ5)

MAINCFILE=main.cpp
CFILE1=matrix.cpp
CFILE2=dfs.cpp
CFILE3=bfs.cpp
CFILE4=a.cpp
CFILE5=a_star.cpp

HFILE1=matrix.hpp
HFILE2=dfs.hpp
HFILE3=bfs.hpp
HFILE4=a.hpp
HFILE5=a_star.hpp

HEADER_FILES= $(HFILE1) $(HFILE2) $(HFILE3) $(HFILE4) $(HFILE5)

TEST_FILE=tests/test1.txt


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

$(OBJ3): $(CFILE3) $(HFILE3)
	$(COMPILER) -c $(CFILE3) -o $(OBJ3)

$(OBJ4): $(CFILE4) $(HFILE4)
	$(COMPILER) -c $(CFILE4) -o $(OBJ4)

$(OBJ5): $(CFILE5) $(HFILE5)
	$(COMPILER) -c $(CFILE5) -o $(OBJ5)

clean:
	@rm -f *.o $(MAIN_NAME)
