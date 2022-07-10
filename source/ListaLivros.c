#include "ListaLivros.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


ListaLivros* criarListaLivros(void)
{
	ListaLivros* novaLista = (ListaLivros*)malloc(sizeof(ListaLivros));
	
	novaLista->prim = NULL;
	novaLista->tamanho = 0;
	
	return novaLista;
}

int cadastrarLivro(ListaLivros* l, int codigo, char* titulo, char* autor, char* editora)
{
	if( l == NULL)
		return 0;
		
	Livro* ant = NULL;
	Livro* p = l->prim;
	
	while( p != NULL && (p->codigo < codigo) )
	{
		ant = p;
		p = p->prox;
	}
	Livro* novoLivro = (Livro*)malloc(sizeof(Livro));
	
	if(novoLivro == NULL)
		return 0;
	
	novoLivro->codigo = codigo;
	strcpy(novoLivro->titulo, titulo);
	strcpy(novoLivro->autor, autor);
	strcpy(novoLivro->editora, editora);
	novoLivro->emprestado = 0;
	novoLivro->prox = NULL;
	
	if( ant == NULL)
	{
		novoLivro->prox = l->prim;
		l->prim = novoLivro;
	}
	else
	{
		novoLivro->prox = ant->prox;
		ant->prox = novoLivro;
	}
	l->tamanho = l->tamanho + 1;
	
	return 1;
	
}

int removerLivro(ListaLivros* l, int codigo)
{
	if( l == NULL)
		return 0;

	Livro* ant = NULL;
	Livro* p = l->prim;
	
	while( p != NULL && (p->codigo != codigo) ){
		ant = p;
		p = p->prox;
	}
	
	if( p != NULL )
	{	ant->prox = p->prox;
		free(p);
		l->tamanho = l->tamanho - 1;
		return 1;
	}
	
	return 0; //nenhum livro com o código informado
}

int QuantidadeLivros(ListaLivros* l)
{
	if(l==NULL)
		return -1;
		
	return l->tamanho;
}

void imprimirListaLivros(ListaLivros* l)
{
	if( l != NULL)
	{
		for( Livro* p = l->prim; p != NULL; p = p->prox)
		{
			printf("=========================================\n");
			printf("Codigo:	%d\n", p->codigo);
			printf("Titulo:	%s\n", p->titulo);
			printf("Autor:	%s\n", p->autor);
			printf("Editora:	%s\n", p->editora);
			printf("Emprestado: %s\n", p->emprestado==1?"Sim":"Nao" );
			printf("=========================================\n");
		}
	}
}

int apagarListaLivros(ListaLivros** l)
{
	if( l==NULL)
		return 0;
		
	Livro* p = (*l)->prim;
	while(p != NULL )
	{
		Livro* t = p->prox;
		free(p);
		p = t;
	}
	
	free( (*l) );
	*l = NULL;
	
	return 1;
}

Livro* buscarElemento(ListaLivros* l, int codigo)
{

	if( l == NULL)
		return NULL;
	Livro* p = l->prim;
	
	while( (p != NULL) && (p->codigo != codigo) )
		p = p->prox;
	
	return p;
}

int buscarVizinhos(ListaLivros* l, int codigo, Livro** anterior, Livro** posterior)
{
	if( l == NULL)
		return 0;
	
	Livro* ant = NULL;
	Livro* p = l->prim;
	
	while( p != NULL && (p->codigo != codigo) )
	{
		ant = p;
		p = p->prox;
	}
	
	*anterior = ant;
	*posterior = p->prox;
	
	return 1;
	
}

int emprestarLivro(ListaLivros* l, int codigo)
{
	if( l == NULL)
		return 0;
	
	Livro* ant = NULL;
	Livro* p = l->prim;
	
	while( p != NULL && (p->codigo != codigo) )
	{
		ant = p;
		p = p->prox;
	}
	
	if( p == NULL)
		return 0;
		
	p->emprestado = 1;
	
	return 1;
	
}

int devolverLivro(ListaLivros* l, int codigo)
{
	if( l == NULL)
		return 0;
	
	Livro* ant = NULL;
	Livro* p = l->prim;
	
	while( p != NULL && (p->codigo != codigo) )
	{
		ant = p;
		p = p->prox;
	}
	
	if( p == NULL)
		return 0;
		
	p->emprestado = 0;
	return 1;
}
