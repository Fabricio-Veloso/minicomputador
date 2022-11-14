#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_array(char *aray);

void cria_arrays(char *aray)
{
    //cria  um ponteiro que aponta para endereço com tamanho de char
    ;

    //Recebe imput do usuário para preencher array
    scanf("%s", aray);
    int i = 0;
    while( aray[i] != '\0')
    {
        i++;
        printf("%c",aray[i-1]);
    }
   printf(" fim da funcao print arays\n");

    //endereço de retorno recebe array criado
    
    i = 0;
    while( aray[i] != '\0')
    {
        i++;
        printf("%c",aray[i-1]);
    }
    printf("segundo fim da funcao print arays\n");
}

int main (void)
{
    char *aray = (char*) malloc(sizeof(char));
    cria_arrays(aray);
    int i = 0;
    while( aray[i] != '\0')
    {
        i++;
        printf("%c",aray[i-1]);
    }
    printf(" fim da funcao print arays em main\n");
    print_array(aray);
    return 0;
}

void print_array(char *entrada)
{
    
    int i = 0;
    while( entrada[i] != '\0')
    {
        i++;
        printf("%c",entrada[i-1]);
    }

}
