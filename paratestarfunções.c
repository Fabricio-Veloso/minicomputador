#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>








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






int adaptative_fwrite_txt( txt variavel,FILE *file_arquivo)
{

   fwrite(&variavel,sizeof(txt),1,file_arquivo);
}



        

