#include "ListaLivros.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	ListaLivros* minhaLista = criarListaLivros();
	Livro livroNovo;
	Livro* livrox;
	Livro* ant;
	Livro* post;
	int op;
	
	do{
		printf("1 - Cadastrar Livro\n");
		printf("2 - Remover Livro\n");
		printf("3 - Quantidade de Livros\n");
		printf("4 - Imprimir Lista de Livros\n");
		printf("5 - Apagar Lista de Livros\n");
		printf("6 - Buscar Elemento\n");
		printf("7 - Emprestar Livro\n");
		printf("8 - Devolver Livro\n");
		printf("0 - Sair\n");
		printf(":");
		scanf("%d%*c", &op);
		
		switch(op)
		{
			case 0:
			break;
			case 1:
				if( minhaLista==NULL)
					minhaLista = criarListaLivros();
					
				printf("codigo:");
				scanf("%d%*c", &livroNovo.codigo);
				printf("Titulo:");
				scanf("%79[^\n]%*c", livroNovo.titulo);
				printf("Autor:");
				scanf("%79[^\n]%*c", livroNovo.autor);
				printf("Editora:");
				scanf("%39[^\n]%*c", livroNovo.editora);
				
				if( cadastrarLivro(minhaLista, livroNovo.codigo, livroNovo.titulo, 
								livroNovo.autor, livroNovo.editora) )
					printf("*** sucesso ao cadastrar ***\n");
				else
					printf("*** Erro ao cadastrar ***\n");
				
			break;
			
			case 2:
				printf("Codigo do livro a remover: ");
				scanf("%d", &livroNovo.codigo);
				if( removerLivro(minhaLista , livroNovo.codigo) )
					printf("*** Sucecco ao remover ***\n");
				else
					printf("*** Erro ao remover ***\n");
				
				
			break;
			
			case 3:
				printf("Total de Livros: %d\n", QuantidadeLivros(minhaLista ) );	
			break;
			
			case 4:
				imprimirListaLivros(minhaLista);
			break;
			
			case 5:
				if( apagarListaLivros(&minhaLista) )
					printf("*** Lista apagada com sucesso ***\n");
				else
					printf("*** Erro ao apagar lista ***\n");
			break;
			
			case 6:
				printf("Codigo do livro a buscar:");
				scanf("%d", &livroNovo.codigo);
				livrox = buscarElemento(minhaLista , livroNovo.codigo);
				if( livrox != NULL )
					printf("codigo de buca: %d, titulo: %s\n", livrox->codigo, livrox->titulo);
				if( buscarVizinhos(minhaLista, 7 , &ant, &post) )
					printf("Anterior: %s, Posterior: %s\n", ant->titulo, post->titulo);
				else
					printf("*** Erro ao buscar vizinhos ***\n");
			break;
				
			case 7:
				printf("Codigo do livro a Emprestar:");
				scanf("%d", &livroNovo.codigo);
				if ( emprestarLivro(minhaLista , livroNovo.codigo) )
					printf("*** Sucesso ao emprestar ***\n");
				else
					printf("*** Erro ao emprestar ***\n");
			case 8:
				printf("Codigo do livro a Devolver:");
				scanf("%d", &livroNovo.codigo);
				if( devolverLivro(minhaLista, livroNovo.codigo) )
					printf("*** Devolucao feita com sucesso ***\n");
				else
					printf("*** Erro ao devolver ***\n");
			break;
			default:
				printf("Opcao Invalida\n");
		}
	}while(op>0);
	
	return 0;
}
