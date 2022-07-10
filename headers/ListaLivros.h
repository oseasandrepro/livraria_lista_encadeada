#ifndef	LISTA_LIVRO_H
#define	LISTA_LIVRO_H

typedef struct lista	ListaLivros;
typedef struct no	Livro;

struct no{
	int codigo;
	char titulo[80];
	char autor[80];
	char editora[40];
	int emprestado;
	struct no* prox;
};
struct lista{
	Livro* prim;
	int tamanho;
};

ListaLivros* criarListaLivros(void);	//NULL para erro
int cadastrarLivro(ListaLivros*, int, char*, char*, char* );		//1 para sucesso e, 0 para erro
int removerLivro(ListaLivros* , int );			//1 para sucesso e, 0 para erro
int QuantidadeLivros(ListaLivros* );	//quantidade para sucesso e, -1 para erro
void imprimirListaLivros(ListaLivros* );
int apagarListaLivros(ListaLivros** );		//1 para sucesso e, 0 para erro
Livro* buscarElemento(ListaLivros* , int);
int buscarVizinhos(ListaLivros* , int , Livro** , Livro**);
int emprestarLivro(ListaLivros* , int );	//1 para sucesso e, 0 para erro
int devolverLivro(ListaLivros* , int );		//1 para sucesso e, 0 para erro

#endif
