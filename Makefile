main:sudoku.c common.o sudoku.o
	gcc -o sudoku common.o sudoku.o
link.o:common.h common.c
	gcc -c common.c
main.o:common.h
	gcc -c sudoku.c
clean:
	rm -rf common.o sudoku.o
