#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct no {
		Item item;
		struct no *prox;
} *Lista;

Lista no(Item x, Lista p) {
	Lista n = (Lista)malloc(sizeof(struct no));
	n->item = x;
	n->prox = p;
	return n;
}

/*
Basicamente adicionamos os cochetes no inicio e no final 
e uma verificacao com IF adicional para verificar se chegou no final
*/
void exibe(Lista L) {
	printf("[");
	while( L != NULL ) {
		printf("%d",L->item);
		L = L->prox;
		if(L!=NULL){printf(",");}
	}
	printf("]\n");
}

int main(void) {
		Lista I = no(3,no(1,no(5,NULL)));
		exibe(I);
		return 0;
}