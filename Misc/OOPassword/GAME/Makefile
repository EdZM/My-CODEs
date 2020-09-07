zipname := OOPassword
ifdef name
	zipname = $(name)
endif
all: compile run

compile:
	@g++ *.cpp -o game -O3

run: game
	@./game

cmpg: clean
	@gcc -o game *.c -g -Wall

clean:
	@rm *.o *.zip game -f

debug: clean cmpg
	@valgrind -v --track-origins=yes --leak-check=full ./game

zip:
	@zip -r $(zipname).zip *
	@echo sucess
