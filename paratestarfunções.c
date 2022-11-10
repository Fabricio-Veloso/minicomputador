#include <stdio.h>

char * criararay(void);
void printAray(char *aray);

//cabeçalho para função que adiciona caractere


typedef struct corda {
            char letra;
            struct corda *prox;
        } no;

int addletra(no *comeco, char letra);

int main(void)
{
    char nomeusuario = criararay;
    
    return 0;
}

void printAray(char *aray)
{
    int i = 0;
    while( aray[i] != '\0')
    {
        i++;
        printf("%c",aray[i-1]);
    }
}

char * criararay(void)
{
    //cria variável para guardar letra a ser adicionada na lista
    char slot;

    //cria um ponteiro do tipo de estrutura de nó chamado começo, começo aponta para NULL
    no *comeco = NULL;
    //começo apontará para endereço com as especificações da estrutura 
    comeco = (no*) malloc(sizeof(no));
    //o o lccal do endereço  de começo receberá 'a'
    comeco->letra = scanf("%c",slot);
    //O campo prox de da variável começo, apontará para null
    comeco->prox = NULL;
    if( addletra(comeco) == 1)
    {
        
    }
    
}

int addletra(no *comeco) 
    {
        char slot;
        no *atual = comeco;
        while (atual->prox != NULL) 
        {
            atual = atual->prox;
        }

        /* now we can add a new variable */
        atual->prox = (no*) malloc(sizeof(no));
        scanf("%c",slot);
        if (slot == "\n")
        {
            return 1;
        }
        else
        {
        atual->prox->letra = slot;
        atual->prox->prox = NULL;
        }
    }