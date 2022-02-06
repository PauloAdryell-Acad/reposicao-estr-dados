#include

typedef struct Pilha {
    int topo;
    int capacidade;
    float *prox;
} Pilha;

void inicializa( struct Pilha *p, int capacidade ){
   p->topo = -1;
   p->capacidade = capacidade;
   p->prox = (float*) malloc (capa * sizeof(float));
}

void adiciona ( struct Pilha *p, float v){

	p->topo++;
	p->prox [p->topo] = v;

}

float exclui ( struct Pilha *p ){

   float aux = p->prox [p->topo];
   p->topo--;
   return aux;

}

int main(){

	struct Pilha minhapilha;
	int capacidade, op;
	float valor;

	printf( "\nCapacidade da pilha? " );
	scanf( "%d", &capacidade );

	inicializa (&minhapilha, capacidade);
	while( 1 ){
		printf("\n1- adicionar \n");
		printf("2- excluir \n");
		printf("3- Mostrar \n");
		printf("4- sair\n");
		printf("\nopcao: ");
		scanf("%d", &op);
		switch (op){
			case 1:
				if(minhapilha->topo == minhapilha->capacidade - 1)
					printf("\nPILHA CHEIA! \n");
				else {
					printf("\nVALOR? ");
					scanf("%f", &valor);
					adiciona &minhapilha, valor);
				}
				break;
			case 2:
				if (minhapilha->topo == minhapilha->capacidade)
					printf( "\nPILHA VAZIA! \n" );
				else{
					valor = exclui(&minhapilha);
					printf ("\n%.1f DESEMPILHADO!\n", valor);
				}
				break;
			case 3:
				if (minhapilha->topo == minhapilha->capacidade)
					printf("\nPILHA VAZIA!\n");
				else {
					valor = minhapilha->prox[minhapilha->topo];
					printf ( "\nTOPO: %.1f\n", valor );
				}
				break;
			case 4:
				exit(0);
			default: printf( "\nOPCAO INVALIDA! \n" );
		}
	}

}
