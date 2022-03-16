all:
	gcc -o trab3 -g -Wall main.c best_fit.c worst_fit.c
clean:
	rm -f *.o trab3
