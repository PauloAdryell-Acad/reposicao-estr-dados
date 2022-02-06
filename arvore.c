struct No
{
    int num;
    struct No *left;
    struct No *right;
};
typedef struct No No;

void inicializa(No **pRaiz)
{
    *pRaiz = NULL;
}

void adiciona(No **pRaiz, int numb)
{
	if (*pRaiz == NULL)
	{
	      *pRaiz=(No *)malloc(sizeof (No));
	      (*pRaiz)->left=NULL;
	      (*pRaiz)->right=NULL;
	      (*pRaiz)->num=numb;
	}
	else
        {
		if (numb < ((*pRaiz)->num))
		{
			adiciona(&((*pRaiz)->left), numb);
		}
		else
		{
			adiciona(&((*pRaiz)->right), numb);
		}
	}
}

No *BigRight(No **no)
{
    if((*no)->right != NULL)
    {
       return BigRight(&(*no)->right);
    }
    else
    {
       No *aux = *no;

       if((*no)->left != NULL)
        {
          *no = (*no)->left;
        }
        else
        {
            *no = NULL;
            return aux;
        }
    }

}

No *SmallLeft(No **no)
{
    if((*no)->left != NULL)
    {
       return MenorEsquerda(&(*no)->left);
    }
    else
    {
        No *aux = *no;
        if((*no)->right != NULL)
        {
          *no = (*no)->right;
        }
        else
        {
          *no = NULL;
        }
        return aux;
    }
}

void exclui(No **pRaiz, int num){
    if(*pRaiz == NULL){
       printf("Numero nao existe na arvore!");
       getch();
       return;
    }
    if(num < (*pRaiz)->num)
       exclui(&(*pRaiz)->left, num);
    else
       if(num > (*pRaiz)->num)
          exclui(&(*pRaiz)->right, num);
       else{
          No *pAux = *pRaiz;
          if (((*pRaiz)->left == NULL) && ((*pRaiz)->right == NULL)){         // se nao houver filhos...
                free(pAux);
                (*pRaiz) = NULL;
               }
          else{
             if ((*pRaiz)->left == NULL){
                (*pRaiz) = (*pRaiz)->right;
                pAux->right = NULL;
                free(pAux); pAux = NULL;
                }
             else{
                if ((*pRaiz)->right == NULL){
                    (*pRaiz) = (*pRaiz)->left;
                    pAux->left = NULL;
                    free(pAux); pAux = NULL;
                    }
                else{
                   pAux = MaiorDireita(&(*pRaiz)->left);
                   pAux->left = (*pRaiz)->left;
                   pAux->right = (*pRaiz)->right;
                   (*pRaiz)->left = (*pRaiz)->right = NULL;
                   free((*pRaiz));  *pRaiz = pAux;  pAux = NULL;
                   }
                }
             }
          }
}

int contarNos(No *pRaiz){
   if(pRaiz == NULL)
        return 0;
   else
        return 1 + contarNos(pRaiz->left) + contarNos(pRaiz->right);
}

int maior(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}



int altura(No *pRaiz){
   if((pRaiz == NULL) || (pRaiz->left == NULL && pRaiz->right == NULL))
       return 0;
   else
       return 1 + maior(altura(pRaiz->left), altura(pRaiz->right));
}
