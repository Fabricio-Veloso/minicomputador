#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main( void)
{
    printf("Digite o que voce deseja colocar no aray\n");


    char *aray = (char*) malloc(sizeof(char));
    scanf("%s", aray);
    int contador = 0;

    while ( aray[contador] != '\0')
    {
        printf("%c", aray[contador]);
        contador++;
    }
    

    return 0;
}