name = prog

$(name): main.o io.o
	gcc -o $(name) main.o io.o
	./$(name)

io.o: io.h io.c
	gcc -c io.c

main.o:  main.c main.h
	gcc -c main.c

clear:
	rm *.o
	rm $(name)

remove: clear
	rm registry