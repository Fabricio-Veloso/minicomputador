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
void criarSenha(char *retorno);

//função para criar nome de usuário
void criarUserName(char *entry);

//função para mosrar arrays na tela
void print_array(char *entrada);

//função para comprar arrays
int check_arrays(char *array1, char *array2);

//função para criar usuário
void criar_usuario(FILE *rootfile); 

//fução para criar arrays
void fillaray(char *saida);

//função para decisão de usuário de sim ou não
int input(void);


// início da função main
int main(void)
{
    //variável para token do usuário atual.
    int usuarioToken;
    //ponteiro para estrutura FILE
    FILE *rootFile;

    //variável para escolha do usuário
    int choice;

    //se o programa não encontrar o arquivo de usuário root, pergunta ao usuário se ele deseja criar um novo.
    if(rootCheck() == 0)
    {
        printf("\nVoce esta executando este programa em uma maquina nova?\n(0) para Nao\n(1) para sim\n");
        choice = input();
        
        //se o usuário  decidir não criar um novo arquivo, uma mensagem sobre o possível problema é mostrada.
        if (choice == 0)
        {
            printf("Algum erro deve ter ocorrido ao tentar acessar o arquivo root\nO programa nao pode funionar corretamente sem o arquivo root e sera terminado.\n");
        }
            
        if (choice == 1)
        {
            //cria arquivo root
            //testa se aquivo root pode ser criado
            if ((rootFile = fopen("root.txt", "wb+")) == NULL)
            {
                printf("houve algum erro ao criar o arquivo de usuário root.\n");
            }
            else
            {
                //chama a função "criar usuário para criar o usuário root"
                criar_usuario(rootFile);
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
//função para receber input da escolha do usuário
int input(void)
{
    //cria variável inteira
    int escolha = 0;
    //recebe imput do usuário para
    scanf("%d",&escolha);
    return escolha;
    
}

//função para comparar arrays.
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

//função para printar arrays
void print_array(char *entrada)
{
    int i = 0;
    while( entrada[i] != '\0')
    {
        i++;
        printf("%c",entrada[i-1]);
    }
}

//função para cria arrays
void fillaray(char *aray)
{
    //Recebe imput do usuário para preencher array
    scanf("%s", aray);
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
        fclose(rootFile);
    }
}

void criar_usuario(FILE *rootfile)
{
    int last_T_user = 0;
    //ponteiros para retornar senha e usuário.
    char *userR = (char*) malloc(sizeof(char));
    char *senhaR = (char*) malloc(sizeof(char));

    //chama as respectivas funções para a criação de usuáro e senha.
    criarUserName(userR);
    criarSenha(senhaR);

    struct user
    {
        int token;
        char *user_name;
        char *senha;
    };
    
    typedef struct user usuario;

    
    if(last_T_user = 0)
    {
        usuario root;
        root.token = 999;
        root.user_name = userR;
        root.senha = senhaR;
        fwrite(&root,sizeof(struct user),1,rootfile);
    }
    else
    {
        usuario comum;
        comum.token = (last_T_user + 1);
        comum.user_name = userR;
        comum.senha = senhaR;
        fwrite(&comum,sizeof(struct user),1,rootfile);
        usuario *pcomum = comum.senha;
        pcomum = comum.token;
        pcomum = comum.user_name;
        fwrite(pcomum,sizeof(usuario),1,rootfile);
    }
    
}
    
    


void criarSenha(char *retorno)
{
    //endereço para senha ser retornada da função de criararrays
    char *teste = (char*) malloc(sizeof(char));
    

    //mensagem para usuário inserir a senha
    printf("Digite a senha\n");

    //chama a função criar arays para fazer a senha
    fillaray(teste);
    
    //mensagem para o usuário digitar a senha novamente
    printf("Digite a senha novamente\n");

    // chama a função de criar arays novamente 
    fillaray(retorno);

    // Loop que compara as senhas, caso elas sejam diferentes pede ao usuário para reescreve-las
    while(check_arrays(teste,retorno) == 0)
    {
        printf("A senha precisa ser igual a digitada anterioremente\n");
        printf("Digite a senha\n");
        fillaray(teste);
        printf("Digite a senha novamente\n");
        fillaray(retorno);
    }
    
   
}

void criarUserName(char *aray)
{
    //declara variável que a escolha do usuário ficara guardada
    int choice = 1;
  
  //loop para o usuário preencher o nome de usuário
    while (choice == 1)
    {
        //mensagem para usuário inserir o nome de usuário
        printf("Digite o nome de usuario desejado\n");

        //chama a função criar arays para fazer o nome de usuário
        fillaray(aray);

        //mensagem para o usuário confirmar o nome de usuário
        printf("O nome de usuario que voce digitou e: \n");

        //mostra o nome digitado
        print_array(aray);

        //Caso o usuário deseje ele pode reescrever o nome
        printf("\nVoce deseja reescreve-lo?\nDgite (1) para sim e (0) para nao\n ");
        choice = input();
    }
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