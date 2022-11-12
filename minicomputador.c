#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*

dentro desse programa haverão as opções de usar:
uma interface para selecionar entre as funções
 calcurladora
 agenda de lembretes
 editor de texto
 lista de contatos 
jogo de campo minado

Primeiro vamos fazer o menu/interface do usuário para selecionar entre as funcções:
 */
/*void MenuInicial(void);*/

//função para checar se o arquivo root já existe
int rootCheck(void);

//função para criar senha
char* criarSenha(char *retorno);

//função para nome de usuário
void criarUserName(char *entry);

//função para mosrar arrays na tela
void printarray(char *arrayPointer);

//função para comprar arrays
int check_arrays(char array1[], char array2[]);

//função para criar usuário
void criar_usuario(void);

//fução para criar arrays
char* cria_arrays(char*);

//função para decisão de usuário de sim ou não
int simnao(void);


// início da função main
int main(void)
{
    //variável para token do usuário atual.
    int usuarioToken;
    //ponteiro para estrutura FILE
    FILE *rootFile;
    //cria variável para escolha do usuário
    int choiceUser = 0;
    //se o programa não encontrar o arquivo de usuário root, pergunta ao usuário se ele deseja criar um novo.
    if(rootCheck() == 0)
    {
        printf("\n Voce esta executando este programa em uma maquina nova?\n(0) para Nao\n(1) para sim\n");
        choiceUser = simnao();
        
        //se o usuário  decidir não criar um novo arquivo, uma mensagem sobre o possível problema é mostrada.
        if (choiceUser == 0)
        {
            printf("Algum erro deve ter ocorrido ao tentar acessar o arquivo root\nO programa nao pode funionar corretamente sem o arquivo root e sera terminado.\n");
        }
            //cria arquivo root
            //testa se aquivo root pode ser criado
        if (choiceUser == 1)
        {
            if ((rootFile = fopen("root.txt", "w")) == NULL)
            {
                printf("houve algum erro ao criar o arquivo de usuário root.\n");
            }
            else
            {
                //chama a função "root cration para criar o novo usuário root"
                criar_usuario();
            }
        }
        
    }   
    //caso o arquivo root tenha sido encontrado o usuário deve fazer o login.
    if( rootCheck() == 1)
    {
         //chama função de realizar login.
    }
    
    return 0; 
}

int simnao(void)
{
    int escolha = 0;
    scanf("%d",escolha);
    return escolha;
}
//função para comparar arrays.
int check_arrays(char array1[], char array2[])
{
   
    int contador = 0;
    while ((array1[contador] != '\n') && (array2[contador] != '\n'))
    {
        contador++;
    }
        
}

//função para printar arrays
void printarray(char *arraypointer)
{
    int i = 0;
    while( arraypointer[i] != '\0')
    {
        i++;
        printf("%c",arraypointer[i-1]);
    }
}

char* cria_arrays(char*saida)
{
    char *aray = (char*) malloc(sizeof(char));
    scanf("%s", aray);
    int contador = 0;

    while ( aray[contador] != '\0')
    {
        printf("%c", aray[contador]);
        contador++;
    }
    saida = aray;

}


int rootCheck(void)
{
    //função para checar se já existe um usuário administradorou root, caso ele ainda não exista, será criado.
     
     //variável para escolha do usuário.
     
    
    //ponteiro para abrir arquivo
    FILE *rootFile;
    
    //se arquivo não puder ser aberto, perguntar ao usuário o que ele deseja fazer.
    if ( ( rootFile = fopen("root.txt", "r")) == NULL){  
    
        printf("O arquivo de usuario root nao foi encontrado");
        fclose(rootFile);
        return 0;
    }
    else
    {
        printf("Aquivo Root encontrado");
        return 1;
    }
}

void criar_usuario(void)
{
    //ponteiros para retornar senha e usuário.
    char *senhaR;
    char *userR;

    //chama as respectivas funções para a criação de usuáro e senha root.
    criarUserName(userR);
    criarSenha(senhaR);
    printarray(userR);
    printarray(senhaR);
    
}
    
    


char* criarSenha(char *retorno)
{
    //endereço para senha ser retornada da função de criararrays
    char *entrada1;
    char *entrada2;

    //mensagem para usuário inserir a senha
    printf("Digite a senha\n");

    //chama a função criar arays para fazer a senha
    cria_arrays(entrada1);
    
    //mensagem para o usuário digitar a senha novamente
    printf("Digite a senha novamente\n");

    // chama a função de criar arays novamente 
    cria_arrays(entrada2);

    // Loop que compara as senhas, caso elas sejam diferentes pede ao usuário para reescreve-las
    while(check_arrays(entrada1,entrada2) == 0)
    {
        printf("A senha precisa ser igual a digitada anterioremente\n");
        printf("Digite a senha\n");
        cria_arrays(entrada1);
        printf("Digite a senha novamente\n");
        cria_arrays(entrada2);
    }
    retorno = entrada1 ;
   
}

void criarUserName(char *Entry)
{
    //declara variáveis
    char *entrada1;

    //mensagem para usuário inserir o nome de usuário
    printf("Digite o nome de usuário desejado\n");

    //chama a função criar arays para fazer o nome de usuário
    cria_arrays(entrada1);
    
    //mensagem para o usuário confirmar o nome de usuário
    printf("O nome de usuário que você digitou é: \n");
    printarray(entrada1);
    printf("\n");
    printf("Você deseja reescreve-lo?");
    while (simnao() == 0)
    {
        criarUserName(entrada1);
    }
    Entry = entrada1;
}
/*void MenuInicial(void)

{
   ;
    printf("Ola, seja bem vindo ao programa de computador de Fabraccho\nDigite seu nome de usuário 0 para entrar como um convidado.\nUser:");
    while ( getchar() != '\n')
    {
    
    }

   

}
*/