COMPILER=mpicc

MAIN_NAME=students

MAIN_OBJ=students.o
OBJ_FILE0=matrix.o
OBJ_FILE1=metrics.o
OBJ_FILE2=sort.o
OBJECTS= $(MAIN_OBJ) $(OBJ_FILE0) $(OBJ_FILE1) $(OBJ_FILE2)

MAIN_C_FILE=studentspar.c
C_FILE0=matrix.c
C_FILE1=metrics.c
C_FILE2=sort.c

H_FILE0=matrix.h
H_FILE1=metrics.h
H_FILE2=sort.h

PROCS=8
LIBS= -lm
TEST_FILE=input.in


all: compile 

compile: main

main: $(OBJECTS)
	$(COMPILER) $(OBJECTS) -o $(MAIN_NAME) $(LIBS)

$(MAIN_OBJ): $(MAIN_C_FILE)
	$(COMPILER) -c $(MAIN_C_FILE) -o $(MAIN_OBJ) $(LIBS) 

$(OBJ_FILE0): $(C_FILE0) $(H_FILE0)
	$(COMPILER) -c $(C_FILE0) -o $(OBJ_FILE0)

$(OBJ_FILE1): $(C_FILE1) $(H_FILE1)
	$(COMPILER) -c $(C_FILE1) -o $(OBJ_FILE1)	

$(OBJ_FILE2): $(C_FILE2) $(H_FILE2)
	$(COMPILER) -c $(C_FILE2) -o $(OBJ_FILE2) 

run: compile
	mpirun -np $(PROCS) ./$(MAIN_NAME)	

run_test: compile
	mpirun -np $(PROCS) ./$(MAIN_NAME) < $(TEST_FILE) 

clean:
	@rm -f *.o $(MAIN_NAME)	
