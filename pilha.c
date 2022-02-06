#include

typedef *No{
    int id;
    char name;
    int priority;
    int wait;
} No;

typedef struct Pilha {
    int topo;
    int capacidade;
    No *prox;
} Pilha;


void inicializa( struct Pilha *p, int capacidade ){
   p->topo = -1;
   p->capacidade = capacidade;
   p->prox = (float*) malloc (capacidade * sizeof(float));
}

void adiciona ( struct Pilha *p, No *processo){
	p->topo++;
	p->prox [p->topo] = processo;
}

void exclui(struct Pilha *p){
   float aux = p->prox [p->topo];
   p->topo--;
   return;
}

int main(){

	struct Pilha minhapilha;
	int capacidade, op;
	No processo;

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
					processo->id = 1;
					processo->name = "a";
					processo->priority = 1;
					processo->wait = 1;

					adiciona (&minhapilha, processo);
				}
				break;

			case 2:
				if (minhapilha->topo == minhapilha->capacidade)
					printf( "\nPILHA VAZIA! \n" );

				else{
					exclui(&minhapilha);
					printf ("\nlimpo!\n");
				}

				break;

			case 3:
				if (minhapilha->topo == minhapilha->capacidade)
					printf("\nPILHA VAZIA!\n");

				else {
					processo = minhapilha->prox[minhapilha->topo];
					printf ( "\nTOPO: %.1f\n", processo );
				}

				break;
			case 4:
				exit(0);
			default: printf( "\nOPCAO INVALIDA! \n" );
		}
	}

}
