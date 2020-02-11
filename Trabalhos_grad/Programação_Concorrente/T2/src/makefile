COMPILER=gcc

MAIN_NAME=students

MAIN_OBJ=students.o
OBJ_FILE=matrix.o

MAIN_C_FILE=studentspar.c
C_FILE=matrix.c

H_FILE=matrix.h

TEST_FILE=input.in


all: compile 

compile: main

main: $(MAIN_OBJ) $(OBJ_FILE)
	$(COMPILER) $(MAIN_OBJ) $(OBJ_FILE) -o $(MAIN_NAME) -fopenmp

$(MAIN_OBJ): $(MAIN_C_FILE)
	$(COMPILER) -c $(MAIN_C_FILE) -o $(MAIN_OBJ) -fopenmp

$(OBJ_FILE): $(C_FILE) $(H_FILE)
	$(COMPILER) -c $(C_FILE) -o $(OBJ_FILE)

run: compile
	./$(MAIN_NAME)	

run_test: compile
	./$(MAIN_NAME) < $(TEST_FILE)

clean:
	@rm -f *.o $(MAIN_NAME)	