all: list.c
	gcc -o list.exe list.c

main.o: list.c
	gcc list.c list.c

clean:
	rm *.o
	rm *~

run: all
	./list.exe

