#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    //ponteiro para arquivo
    FILE *arquivo_root;
    FILE *arquivo_index;
    printf("1");
    struct archive_index
    {
        long int adress;
        char *file_name;
    };
    //troca nome de estrutura por arquivo
    typedef struct archive_index arquivo;

    //estrutura de usuário
    struct user
    {
        int token;
        char *user_name;
        char *senha;
    };
    //troca nome da estrutura por txt
    typedef struct user usuario;

    struct txt
    {
        char *txt;
        char *name; 
    };
    //trocar nome da estrutura para usuário
    typedef struct txt txt;

    txt papel;
    papel.name = "primeiro arquivo de texto";
    papel.txt = "produção textual de teste";
    
    usuario teste;
    teste.senha = "senha teste";
    teste.token = 1;
    teste.user_name = "Fabricio";

    long int adress_a;
    long int adress_b;

    arquivo primeiro_arquivo;
    arquivo segundo_arquivo;
   printf("2");
    
    
    if((arquivo_root = fopen("teste.txt","wb")) == NULL )
    {
        printf("O arquivo não pode ser aberto");
    }
    else
    {
        adress_a = ftell(arquivo_root);
        fwrite(&teste,sizeof(usuario),1,arquivo_root);

        adress_b = ftell(arquivo_root);
        fwrite(&papel,sizeof(txt),1,arquivo_root);
        fclose(arquivo_root);
    }
    printf("3");
    if((arquivo_index = fopen("teste.txt","wb")) == NULL )
    {
        printf("O arquivo não pode ser aberto");
    }
    else
    {
        primeiro_arquivo.adress = adress_a;
        primeiro_arquivo.file_name = "Fabrício";
        segundo_arquivo.adress = adress_b;
        segundo_arquivo.file_name = "primeiro texto de fabricio";
        fwrite(&primeiro_arquivo,sizeof(arquivo),1,arquivo_index);
        fwrite(&segundo_arquivo,sizeof(arquivo),1,arquivo_index);
        fclose(arquivo_index);

    }
    printf("4");
    if((arquivo_index = fopen("teste.txt","wb")) == NULL )
    {
        printf("O arquivo não pode ser aberto");
    }
    
    else
    {
        while (fread())
        {
        fseek(arquivo_index,sizeof(arquivo),SEEK_SET);
        } 

        fread(&primeiro_arquivo,sizeof(arquivo),1,arquivo_index);
        printf("%ld",primeiro_arquivo.adress);
        fclose(arquivo_index);
    }   
    printf("5");



    }

    


