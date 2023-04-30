#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int Item;
typedef struct arv{
	struct arv *esq;
	Item item;
	struct arv *dir;
} *Arv;

Arv arv(Arv e, Item x, Arv d){
	Arv n = (Arv)malloc(sizeof(struct arv));
	n->esq = e;
	n->item = x;
	n->dir = d;
	return n;
}

void exibe(Arv A, int n){
	if(A == NULL) return;
	exibe (A->dir, n+1);
	printf("%*s%d\n", 3*n,"", A->item);
	exibe(A->esq, n+1);
}

Arv completa(int h){
	if(h==0) return NULL;
	return arv (completa(h-1), rand()%100, completa(h-1));
}

Arv balanceada(int n){
    if(n == 0) return NULL;
    if(n == 1) return arv(NULL, rand()%100, NULL);
    
    int m = (n-1)/2;
    Arv esq = balanceada(m);
    Arv dir = balanceada(n-m-1);
    return arv(esq, rand()%100, dir);
}

int main(void){
	srand(time(NULL));
	Arv A = balanceada(9);
	exibe(A, 0);
	return 0;
}