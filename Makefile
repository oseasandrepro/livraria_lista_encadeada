P2: main.o ListaLivros.o
	gcc -Wall -g main.o ListaLivros.o -o Biblioteca

main.o: main.c
	gcc -c main.c -o main.o
	
lista.o: ListaLivros.c
	gcc -c ListaLivros.c -o ListaLivros.o
	
clean:
	rm main.o ListaLivros.o Biblioteca
