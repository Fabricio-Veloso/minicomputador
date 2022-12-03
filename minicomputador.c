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


void MenuInicial(void);*/



            //Estruturas

//estrutura para quantidade de usuários
struct inf_q_user
{
    int user_quantity;
};

//estrutura de arquivo indexador
struct aindex
{
    char filename[30];
    long int adress;
};

//estrutura de usuário
struct user
{
    int token;
    char user_name[25];
    char senha[16];
};

//estrutura de texto
struct txt
{
    char *txt;
    char *name; 
};

    //Typedef's para as estruturas

//troca nome de estrutura por quantidade de usuários
typedef struct inf_q_user user_quantity;

// troca nome de estrutura por arquivo
typedef struct aindex rindex;

// trocar nome da estrutura para usuário
typedef struct user usuario;

// troca nome da estrutura por txt.
typedef struct txt txt;

    //funções de indexação leitura, abertua e escrita de arquivos

//para a escrita de arquivos do tipo quantidade de usuários
long int adapted_fwrite_quantity( user_quantity variavel,FILE *file_arquivo);

//função para abrir o arquivo root   


//função para bucar estruturas index no registro de arquivos indexadores por nome
long int Achrindex(char *nomearquivo, FILE *pfile);

//função adaptada para escrita de arquivos do tipo txt
int adaptative_fwrite_txt( txt variavel,FILE *file_arquivo);

// Função fwrite adaptada para arquivos idexadores.
int adapted_fwrite_index(rindex variavel, FILE *pfile);

// função fwrite para arquivos de usuário.
long int adapted_fwrite_user(usuario variavel, FILE *pfile);

// Função fwrite adaptada para textos.
long int adapted_fwrite_txt(txt variavel, FILE *pfile);

// função para encontrar arquivos indexadores por nome
long int Achrindex(char *nomearquivo, FILE *pfile);

        //Funções de login

//Função para realizar login
void login (FILE *pindex, FILE *prootfile,int user_token);

//função para criar usuário
void criar_usuario(FILE *rootfile, FILE *index);  

//função para checar se o arquivo root já existe
int rootCheck(void);

//função para criar senha
void criarSenha(char *retorno);

//função para criar nome de usuário
void criarUserName(char *entry);


        //Funções para arrays

void conv_str_aray(char *string, char *array);

//função para criar um array adaptado ao tamanho de uma string.
void criate_modular_array(char*string, char *array_saida);

//função para mosrar arrays na tela
void print_array(char *entrada);

//função para comprar arrays
int check_arrays(char *array1, char *array2);

//fução para criar arrays
void fillstring(char *saida);

//função para decisão de usuário de sim ou não
int input(void);


// início da função main
int main(void)
{
    //variável para token do usuário atual.
    int usuarioToken;
    //ponteiros para estrutura FILE
    FILE *rootFile;
    FILE *fIndex;

    //variável para escolha do usuário
    int choice;

    //se o programa não encontrar o arquivo de usuário root, pergunta ao usuário se ele deseja criar um novo.
    if(rootCheck() == 0)
    {
        printf("\nVoce esta executando este programa em uma maquina nova?\n(0) para Nao\n(1) para sim");
        choice = input();
        
        //se o usuário  decidir não criar um novo arquivo, uma mensagem sobre o possível problema é mostrada.
        if (choice == 0)
        {
            printf("\nAlgum erro deve ter ocorrido ao tentar acessar o arquivo root\nO programa nao pode funionar corretamente sem o arquivo root e sera terminado.");
        }
            
        if (choice == 1)
        {
            //cria arquivo root
            //testa se aquivo root pode ser criado
            if ((rootFile = fopen("root.txt", "wb")) == NULL)
            {
                printf("\nhouve algum erro ao criar o arquivo de usuário root.");
            }
            else
            {
                //chama a função "criar usuário para criar o usuário root"
                criar_usuario(rootFile,fIndex);
            }
        }
        
    }   
    //caso o arquivo root tenha sido encontrado o usuário deve fazer o login.
    if( rootCheck() == 1)
    {
         login(fIndex,rootFile,usuarioToken);
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
void fillstring(char *aray)
{
    //Recebe imput do usuário para preencher array
    scanf("%s", aray);
}

//função para criar array modulado para o tamanho da string de entrada
void criate_modular_array(char*string, char *array_saida)
{
    char array[strlen(string)];
    array_saida = array;
}

//função para converter string malloc em array
void conv_str_aray(char *string, char *array)
{
    //cria um contador que será usado no laço.
    int i = 0;

    //cria laço for para preencher o array criado com os caracteres da string.
    for(i = 0; i <= strlen(string); i++)
    {
        array[i] = string[i];
    }
}

//função para checar se o arquivo root foi criado
int rootCheck(void)
{
    //função para checar se já existe um usuário administradorou root, caso ele ainda não exista, será criado.
     
     //variável para escolha do usuário.
     
    
    //ponteiro para abrir arquivo
    FILE *rootFile;
    
    //se arquivo não puder ser aberto, perguntar ao usuário o que ele deseja fazer.
    if ( ( rootFile = fopen("root.txt", "rb+")) == NULL){  
    
        printf("\nO arquivo de usuario root nao foi encontrado");
       
        return 0;
    }
    else
    {
        printf("\nAquivo Root encontrado");
        return 1;
        
    }
}

void login (FILE *pindex, FILE *prootfile,int user_token)
{
    printf("\nPara realizar o login Digite o nome de usuario");
    char *name = (char*) malloc(sizeof(char));
    fillstring(name);
    printf("\nNome recebido com sucesso");
    long int temp_addres;
    int status = 0;
    while (status == 0)
    {
        printf("entrou no loop");
        if ((temp_addres = Achrindex(name,pindex)) == 1)
        {
            printf("\nNão foi encontrado um login com este nome de usuario");
            printf("\nDigite um nome de usuario valido");
            fillstring(name);
        }
        else
        {
            printf("\nNome de usuario encontrado");
            status++;
        
        }
    }
    
    status = 3;
   
    usuario exemple;
    fseek(prootfile,temp_addres,SEEK_SET);
    printf("\ntranslacao para o endereco temporario realizada com sucesso");
    fread(&exemple,sizeof(rindex),1,prootfile);
    printf("\nLeitura da variavel usuario realizada");
    while (check_arrays(name,exemple.senha) == 0)
    {
       printf("\nsenha incorreta");
       status--;
       printf("\nvocê tem mais %d tentativas\nCaso você erre asenha mais 2 vezes, todos os arquivos serão apagados",status);
       if (status == 0);
       {
        //chama a função de corromper arquivos
       }
       
    }
    printf("\n Login efeituado com sucesso");
    user_token = exemple.token;
    
   
        
   
}

//função para criar nome e senha e registralos nos arquivos de registro e indexador
void criar_usuario(FILE *rootfile, FILE *fIndex)
{
    //caso não exista um registro de quantidade de usuários ja criada cria uma variável apropriada para receber o valor atual 0.
        user_quantity quantidade_usuarios;

    //cria variável para alocar quantidade de usuários criados
    int last_T_user;
   
   //se a abertura do rquivo indexador no modo de leitura não poder ser realizada
     if ((fIndex = fopen("index.txt", "rb")) == NULL)
    {
        printf("\nCaso o arquivo indexador ainda nao exista, ele será criado agora.\nCaso ele ja exista, houve algum erro no processo de abertuta do arquivo indexador.");
    
        printf("\nCriando arquivo indexador");
        
        //preenche a variável que guarada aquantidade de usuário com 0
        quantidade_usuarios.user_quantity = 0;

        //escreve a váriavel no arquivo root e guarda o endereço dela em uma variável temporária
        long int temp_addres = adapted_fwrite_quantity(quantidade_usuarios,rootfile);


        //abre o arquivo indexador no modo de escrita binária pela primeira vez
         if ((fIndex = fopen("index.txt", "wb")) == NULL)
        {
            printf("\nhouve algum erro ao abrir o arquivo idexador no modo de escrita");
        }
        else
        {
            //cria e preenche um arquivo tipo indexador com o endereço do registro da quantidade  de usuários criados
           rindex index;
           conv_str_aray("controle_quant_usuarios",index.filename);
           index.adress = temp_addres;
           print_array(index.filename);
           printf("\n%ld\n",index.adress);

           printf("\nvariavel de controle de usuarios criada com sucesso");

           // escreve a estrutura indexadora no arquivo indexador com os dados
           if (fwrite(&index,sizeof(rindex),1,fIndex) != 1)
           {
                printf("\nNão foi possivel escrever no arquivo indexador");
           }
           else
           {
                printf("\nregistro indexador escrito com sucesso");
           }
           
           
        }
        fclose(fIndex);
        fclose(rootfile);
    }

    //se a abertura do arquivo indexador puder ser realizada
    else if ((fIndex = fopen("index.txt", "rb+")) == NULL)
        {
            printf("\nhouve algum erro ao abrir o arquivo idexador no modo rb+");
        }
        else
        {
            //busca a estrutura que contem a quantidade de usuários criada e guarda endereço dela no arquivo root em variável temporária
            long int temp_addres = Achrindex("quantidade_de_usuarios_registrados",fIndex);

            //se o arquivo root puder ser aberto
            if((rootfile = fopen("root.txt","rb+")) == NULL)
            {
                //antes de ler  é preciso dar um fseek para colocar  o ponteiro no local apropriado para a leitura
                fseek(rootfile,temp_addres,SEEK_SET);
                // lê a variável que contem a quatidade de usuários já criada com o endereço retornado pela função achrindex
                fread(&quantidade_usuarios,sizeof(user_quantity),1,rootfile);
                last_T_user = quantidade_usuarios.user_quantity;
                printf("\nA quantidade de usuarios registrada no sistema e : %d",quantidade_usuarios.user_quantity);
            }
        }
    
    
    //ponteiros para retornar senha e usuário.
    char *userR = (char*) malloc(sizeof(char));
    char *senhaR = (char*) malloc(sizeof(char));

    //chama as respectivas funções para a criação de usuáro e senha.
    criarUserName(userR);
    criarSenha(senhaR);

    //se a quantidade de usuários criada for 0
    if(last_T_user == 0)
    {
        //cria uma estrutura de usuário para o primeiro usuário (root)
        usuario root;
        root.token = 999;
        conv_str_aray(userR, root.user_name);
        conv_str_aray(senhaR,root.senha);

        //escreve o registro de usuário root em root_file
        long int temp_addres = adapted_fwrite_user(root,rootfile);
        
        //cria variável do tipo indexador e a preenche com nome e o endereço do registro de usuário root no arquivo root
        rindex index;
        conv_str_aray("usuario_root",index.filename);
        index.adress = temp_addres;

        //escreve  a variável no arquivo indexador
        adapted_fwrite_index(index,fIndex);
        
    
    }

    //se algum usuário ja tenha sido criado cria um usuário comum
    else
    {
        usuario comum;
        comum.token = (last_T_user + 1);
        conv_str_aray(userR,comum.user_name);
        conv_str_aray(senhaR,comum.senha );
        long int temp_addres = adapted_fwrite_user(comum,rootfile);
        fclose(fIndex);

        if ((fIndex =fopen("index.txt", "rb+")) == NULL)
        {   
            rindex index;
            index.adress = temp_addres;
            conv_str_aray(userR,index.filename);
            adapted_fwrite_index(index,fIndex);
        }

    }
    
}

//função para criar senha
void criarSenha(char *retorno)
{
    //endereço para senha ser retornada da função de criararrays
    char *teste = (char*) malloc(sizeof(char));
    

    //mensagem para usuário inserir a senha
    printf("\nDigite a senha");

    //chama a função criar arays para fazer a senha
    fillstring(teste);
    
    //mensagem para o usuário digitar a senha novamente
    printf("\nDigite a senha novamente");

    // chama a função de criar arays novamente 
    fillstring(retorno);

    // Loop que compara as senhas, caso elas sejam diferentes pede ao usuário para reescreve-las
    while(check_arrays(teste,retorno) == 0)
    {
        printf("\nA senha precisa ser igual a digitada anterioremente");
        printf("\nDigite a senha");
        fillstring(teste);
        printf("\nDigite a senha novamente");
        fillstring(retorno);
    }
    
   
}

//função para criar nome de usuário
void criarUserName(char *aray)
{
    //declara variável que a escolha do usuário ficara guardada
    int choice = 1;
  
  //loop para o usuário preencher o nome de usuário
    while (choice == 1)
    {
        //mensagem para usuário inserir o nome de usuário
        printf("\nDigite o nome de usuario desejado");

        //chama a função criar arays para fazer o nome de usuário
        fillstring(aray);

        //mensagem para o usuário confirmar o nome de usuário
        printf("\nO nome de usuario que voce digitou e: ");

        //mostra o nome digitado
        print_array(aray);

        //Caso o usuário deseje ele pode reescrever o nome
        printf("\nVoce deseja reescreve-lo?\nDgite (1) para sim e (0) para nao\n ");
        choice = input();
    }
}

//função de fwrite adaptada para o tipo de estrutura usuário
long int adapted_fwrite_user( usuario variavel,FILE *file_arquivo)
{
    long int return_addres = ftell(file_arquivo);
    fwrite(&variavel,sizeof(usuario),1,file_arquivo);
    return return_addres;
}

//função de fwrite adaptada para o tipo de estrutura de registro indexador
int adapted_fwrite_index( rindex variavel,FILE *file_arquivo)
{

   fwrite(&variavel,sizeof(rindex),1,file_arquivo);
}

//função de fwrite adaptada para o tipo de estrutura quantidade de usuário
long int adapted_fwrite_quantity( user_quantity variavel,FILE *file_arquivo)
{
    long int return_addres = ftell(file_arquivo);
    fwrite(&variavel,sizeof(user_quantity),1,file_arquivo);
    return return_addres;
}

//função que busca registros de arquivos indexadore por nome e retorna endereço no arquivo root
long int Achrindex(char *nomearquivo, FILE *pfile)
{
   
    rindex exemple;
    
    while (!feof(pfile))
    {
        long int retorno;
        int cont = 0;
        
        (fread(&exemple.filename,sizeof(rindex),1,pfile));
        retorno = exemple.adress;
        
        if(check_arrays(exemple.filename,nomearquivo) == 1)
        {
            fclose(pfile);
            return retorno;
        }

        else
        {
        cont++;
        fseek(pfile,cont*sizeof(rindex),SEEK_SET);
        }
    }
    return 0;
}

int adaptative_fwrite_txt( txt variavel,FILE *file_arquivo)
{

   fwrite(&variavel,sizeof(txt),1,file_arquivo);
}

/*void MenuInicial(void)

{
   ;
    printf("\nOla, seja bem vindo ao programa de computador de Fabraccho\nDigite seu nome de usuário 0 para entrar como um convidado.\nUser:");
    while ( getchar() != '\n')
    {
    
    }

   

}
*/