#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>



// struct aindex
// {
   
//     long int adress;
   
// };

// int open_file_index(FILE *pfile,char *nomefile, char *modo);

// // troca nome de estrutura por arquivo
// typedef struct aindex rindex;

// void print_array(char *entrada);

// int main(void)
// {
//     //ponteiro para arquivo
  
//     FILE *findex;

    

//     if(open_file_index(findex,"index.txt","wb") == 1)
//         {
//             long int temp_addres = 0;
//             //cria e preenche um arquivo tipo indexador com o endereço do registro da quantidade  de usuários criados
//            rindex index;
           
//            index.adress = temp_addres;
           
//            printf("\n%ld\n",index.adress);

//            printf("\nvariavel de controle de usuarios criada com sucesso\n");

//            // escreve a estrutura indexadora no arquivo indexador com os dados
//            fwrite(index,sizeof(rindex),1,findex);
           
//            printf("\nvariavel escrita com sucesso\n");
//         }
// }

// void print_array(char *entrada)
// {
//     int i = 0;
//     while( entrada[i] != '\0')
//     {
//         i++;
//         printf("%c",entrada[i-1]);
//     }
// }

// int open_file_index(FILE *pfile,char *nomefile, char *modo)
// {
//     if ((pfile = fopen(nomefile, modo)) == NULL)
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

void print_array(char *entrada);

void conv_str_aray(char *string, char []);

void fillaray(char *aray);

void criate_modul_array(char*string, char *array_saida);

int main (void)
{
    


    char *string = (char*) malloc(sizeof(char));

    printf("digite a string \n");

    fillaray(string);

    print_array(string);

    printf("\nstring preenchida com sucesso \n");

    char *aray;
    criate_modul_array(string,aray);

    printf("array criado com tamanho moudlado com sucesso \n");

    conv_str_aray(string, aray);

    print_array(aray);

}

void conv_str_aray(char *string, char array[])
{

    //cria um contador que será usado no laço.
    int i = 0;

    //cria laço for para preencher o array criado com os caracteres da string.
    for(i = 0; i <= strlen(string); i++)
    {
        array[i] = string[i];
    }
    print_array(array);
 

}


//função para cria arrays
void fillaray(char *aray)
{
    //Recebe imput do usuário para preencher array
    scanf("%s", aray);
}


void print_array(char *entrada)
{
    int i = 0;
    while( entrada[i] != '\0')
    {
       
        printf("%c",entrada[i]);
         i++;
    }
}

void criate_modul_array(char*string, char *array_saida)
{
    char array[strlen(string)];
    array_saida = array;
}