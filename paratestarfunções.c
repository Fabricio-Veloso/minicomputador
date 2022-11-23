#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>


//estrutura de arquivo indexador
struct archive_index
{
    char *file_name;
    long int adress;
   struct archive_index *next;
};

//estrutura de usuário
struct user
{
    int token;
    char *user_name;
    char *senha;
};

//estrutura de texto
struct txt
{
    char *txt;
    char *name; 
};

// troca nome de estrutura por arquivo
typedef struct archive_index a_index;

// trocar nome da estrutura para usuário
typedef struct user usuario;

// troca nome da estrutura por txt.
typedef struct txt txt;

// Função fwrite adaptada para arquivos idexadores.
int adaptative_fwrite_index(a_index variavel, FILE *file);

// função fwrite para arquivos de usuário.
int adaptative_fwrite_user(usuario variavel, FILE *file_arquivo);

// Função fwrite adaptada para textos.
int adaptative_fwrite_txt(txt variavel, FILE *file_arquivo);

// função para encontrar arquivos indexadores por nome
long int Acha_index(char *nomearquivo, FILE *pfile);

// função para checar arrays.
int check_arrays(char *array1, char *array2);

//printa arrays
void print_array(char *entrada);

int main(void)
{
    //ponteiro para arquivo
    FILE *arquivo_root;
    FILE *arquivo_index;
    printf("\np1\n");

    //cria um arquivo do tipo txt(texto) e o prenche com arays de char
    txt arquivo_de_texto;
    arquivo_de_texto.name = "primeiro arquivo de texto";
    arquivo_de_texto.txt = "produção textual de teste";
    
     //cria um arquivo do tipo usuário e o prenche com dados de usuário
    usuario usuario_teste;
    usuario_teste.senha = "senha teste";
    usuario_teste.token = 1;
    usuario_teste.user_name = "Fabricio";

//cria variáveis para receber indereços que são colocados no arquivo indexador 
    long int adress_a;
    long int adress_b;

//cri adois arquivos do tipo indexador
    a_index primeiro_arquivo;
    a_index segundo_arquivo;
    printf("\np2\n");
    
    // caso não consiga abrir o arquivo de teste retona mensagem, abre aquivo de teste
    if((arquivo_root = fopen("teste_index.txt","wb")) == NULL )
    {
        printf("O arquivo não pode ser aberto");
    }
    else
    {
        //usa afunção fteel para armazenar endereço aonde serão escritos os dados e então os escreve no arquivo teste
        adress_a = ftell(arquivo_root);
        fwrite(&usuario_teste,sizeof(usuario),1,arquivo_root);
       

        adress_b = ftell(arquivo_root);
        fwrite(&arquivo_de_texto,sizeof(txt),1,arquivo_root);
        

        //após preencher fecha arquivo
        fclose(arquivo_root);
    
    }
    printf("\np3\n");

    //abre arquivo indexador para gravar nome e endereço dos arquivos tipo indexador que se referem ao arquivos escritos no arquivo teste.
    if((arquivo_index = fopen("teste_index.txt","wb")) == NULL )
    {
        printf("O arquivo não pode ser aberto");
    }
    else
    {
        //preenche os arquivos com nome e endereço coletados
        primeiro_arquivo.adress = adress_a;
        printf(" endereco salvo do primeiro arquivo e :%ld\n",primeiro_arquivo.adress);
        primeiro_arquivo.file_name = "Fabricio";
        segundo_arquivo.adress = adress_b;
        printf(" endereco salvo do segundo arquivo e :%ld\n",segundo_arquivo.adress);
        segundo_arquivo.file_name = "primeiro texto de fabricio";
        primeiro_arquivo.next = &segundo_arquivo;
        segundo_arquivo.next = NULL;
        //chama as funções de escrita para escreve-los no arquivo indexador
        adaptative_fwrite_index(primeiro_arquivo,arquivo_index);
        printf("\np3,5\n");
        adaptative_fwrite_index(segundo_arquivo,arquivo_index);

        //printf de teste
        printf("\np3,6\n");
        
        char *nome_teste = "primeiro texto de fabricio";
        printf("\np3,7\n");
        //fechar arquivo indexador
        fclose(arquivo_index);
        printf("\np300\n");
        
        printf(" o endereco achado pela funcao  de procurar por nome index e :%ld",Acha_index(nome_teste,arquivo_index));  
        
        
    }
    printf("\np5\n");
}


//função para checar arrays
int check_arrays(char *array1, char *array2)
{
    //variável contator para loop
    int i = 0;
    int cont2 = 0;
    while( array1[i] != '\0' || array2[i] != '\0')
    {
        if (array1[i] != array2[i]) 
        {
            return 0;
        }
        i++;
        
    }
    return 1;
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

long int Acha_index(char *nomearquivo, FILE *pfile)
{
   
    a_index exemple;
    //criando função para abrir arquivo indexador, buscar o desejado pelo nome e retornar endereço 
    if((pfile = fopen("teste_index.txt","rb")) == NULL )
    {
        printf("O arquivo não pode ser aberto");
    }

    else
    {
        printf("\np3,8\n");
        while (!feof(pfile))
        {
            long int retorno;
            int cont = 0;
            printf("\np20\n");
            (fread(&exemple.file_name,sizeof(a_index),1,pfile));
            retorno = exemple.adress;
            print_array(exemple.file_name);

            printf("\n");

            
            printf(" a variavel retorno de o valor %ld",retorno);
            
            printf("\np3,9\n");
            if(check_arrays(exemple.file_name,nomearquivo) == 1)
            {
                printf("\np4\n");
                printf(" o endereco do arquivo depois da funcao check rrays foi : %ld",exemple.adress);
                return retorno;
            }
           else
           {
            cont++;
            printf("\np5,1\n");
            fseek(pfile,cont*sizeof(a_index),SEEK_SET);
           }
        }
        fclose(pfile);
    }   
    printf("\np6\n");
}

int adaptative_fwrite_index( a_index variavel,FILE *file_arquivo)
{

   fwrite(&variavel,sizeof(a_index),1,file_arquivo);
}

int adaptative_fwrite_txt( txt variavel,FILE *file_arquivo)
{

   fwrite(&variavel,sizeof(txt),1,file_arquivo);
}

int adaptative_fwrite_user( usuario variavel,FILE *file_arquivo)
{

   fwrite(&variavel,sizeof(usuario),1,file_arquivo);
}

        

