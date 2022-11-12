#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//estrutura de nó
 struct corda {
    char letra;
    struct corda *prox;
};

typedef struct corda no;

char* listencad(char *s);

void printAray(char *aray);

char * montararay(no *comeco, char *retorno);

//início da main
int main(void)
{

    //nome de usuário final ao fim da função
    char *username = listencad(username);
    printf("teste1");
    
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

char* listencad(char *saida)
{

    //cria variável para guardar letra a ser adicionada na lista
    char slot;

    //Cria variável para interromper o loop
    int stop = 0;

    //cria um ponteiro do tipo de estrutura de nó chamado começo, começo aponta para NULL
    no *comeco = NULL;

    //começo apontará para endereço com as especificações da estrutura 
    comeco = (no*) malloc(sizeof(no));

    //o o local do endereço  de começo receberá uma letra digitada pelo usuário
    comeco->letra = scanf("%c",slot);

    //O campo prox de da variável começo, apontará para null
    comeco->prox = NULL;

    no *atual = comeco;
    // loop para adicionar novos caracteres na lista.
    while (stop != 1)
    {
   
        while (atual->prox != NULL) 
        {
            atual = atual->prox;
        }

        // Adciona letra no último ponteiro da lista
        atual->prox = (no*) malloc(sizeof(no));
        scanf("%c",slot);
        if (slot == '\n')
        {
            stop = 1;
        }
        else
        {
        atual->prox->letra = slot;
        atual->prox->prox = NULL;
        }
    }
    //cria aray de retorno
    char *retorno;
    // ao terminar de preencher a lista, uma função para montar o aray é chamada.
    montararay(comeco, retorno);
    
}


    
        
    

//função para receber listas encadeadas e montar arays
char * montararay(no *comeco, char *retorno)
{
    //cria ponteiro para percorrer a lista
    no *atual = comeco; 

    //cria variável para contar caracteres que estão lan lista
    int contador = 0;

    //loop para contar a quantidade de caracteres
    while (atual != NULL)
    {
        atual = atual-> prox;
        contador++;
    }

    // aray que será devolvido é criado com o tamaho adequado
    char arayderetorno[contador];
    
    //ponteiroa tual recebe o endereço inicial novamente
    atual = comeco;

    //contador recebe zero para ser reutilizado
    contador = 0;

    //loop para preencher o aray
     while (atual != NULL)
    {
        atual = atual-> prox;
        contador++;
        arayderetorno[contador] = atual->letra;
    }

    // retorna aray montado
    retorno = arayderetorno;


}