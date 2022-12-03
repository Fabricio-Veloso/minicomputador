#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

int open_file_index(FILE *pfile,char *nome_file, char *modo);

int main(void)
{
    FILE *index;
    if ((index = fopen("testeindex.txt", "wb")) == NULL)
    {
        printf("não foi possivel abrir o arquivo");
    }
    
    int a = 1;
    fwrite(&a,sizeof(int),1,index);
    rewind(index);
    printf("finalizado");

}

// int open_file_index(FILE *pfile,char *nome_file, char *modo)
// {
//     if ((pfile = fopen(nome_file, modo)) == NULL)
//         {
//             printf("\nNao foi possivel abrir o arquivo indexador pela funcao adaptada\n");
//             return 0;
//         }
//     else
//     {
//         printf("\nArquivo indexador aberto com sucesso\n");
//         return 1;
//     }
// }   