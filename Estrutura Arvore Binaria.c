#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define E 0
#define D 1
#define R -1

typedef struct NO{
	int dado;
	struct NO *esquerda;
	struct NO *direita;
	struct NO *pai;
}NO;
typedef struct arvore{
	NO *raiz;
}arvore;

arvore a;

void inicio_arvore(arvore arv);
void No(NO* no,int valor);
void insere_arvore(int valor);
void preOrdem(NO* raiz);

void inicio_arvore(arvore arv){
	arv.raiz = NULL;
}
void No(NO* no,int valor){
	if(!no){
		printf("Falha na alocacao.\n");
		return;
	}
	no->pai = NULL;
	no->esquerda = NULL;
	no->direita = NULL;
	no->dado = valor;
}
void insere_arvore(int valor){
	NO* corrente = a.raiz;
	NO* pai;
	NO* novo = (NO*) malloc(sizeof(NO));
	No(novo, valor);
	printf("Foi inserido no %d. \n", novo->dado);
	
	if(corrente == NULL){
		a.raiz = novo;
		printf("No inserido na raiz. \n");
		return;
	}
	while(corrente){
		pai = corrente;
		if(novo->dado < corrente->dado){
			corrente = corrente->esquerda;
			if(!corrente){
				printf("No inserido na sub-arvore esquerda do no %d. \n",pai->dado);
				pai->esquerda = novo;
				return;
			}
		} 
		else{
			corrente = corrente->direita;
			if(!corrente){
				printf("No inserido na sub-arvore direita do no %d. \n",pai->dado);
				pai->direita = novo;
				return;
			}       
		}
	}
}
void preOrdem(NO* raiz){
	if(raiz){
		printf("%d \t", raiz->dado);
		preOrdem(raiz->esquerda);
		preOrdem(raiz->direita);
	}
}

int main(){
	inicio_arvore(a);
	insere_arvore(2);
	insere_arvore(1);
	insere_arvore(0);
	insere_arvore(4);
	insere_arvore(6);
	insere_arvore(7);
	insere_arvore(8);
	insere_arvore(6);
	insere_arvore(5);
	
	printf("\nBusca em Pre-Ordem: \n");
	preOrdem(a.raiz);
}
