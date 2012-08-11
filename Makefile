# makefile

CC = gcc 

linked_list_test: main.o linked_list.o
	$(CC) main.o linked_list.o -o linked_list_test
linked_list.o: linked_list.c
	$(CC) -c -g linked_list.c -o linked_list.o
main.o: main.c
	$(CC) -c -g main.c -o main.o

clean:
	rm *.o
