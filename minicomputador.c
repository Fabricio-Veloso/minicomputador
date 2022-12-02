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
    char *filename;
    long int adress;
   
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
int open_file_root(FILE *pfile,char *nome_file, char *modo);

//função para bucar estruturas index no registro de arquivos indexadores por nome
long int Achrindex(char *nomearquivo, FILE *pfile);

//função para abrir o arquivo indexador
int open_file_index(FILE *, char *, char *);

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

//função para criar usuário
void criar_usuario(FILE *rootfile, FILE *index);  

//função para checar se o arquivo root já existe
int rootCheck(void);

//função para criar senha
void criarSenha(char *retorno);

//função para criar nome de usuário
void criarUserName(char *entry);


        //Funções para arrays

//função para converter string em aray de char
char*  conv_str_aray(char *string);

//função para mosrar arrays na tela
void print_array(char *entrada);

//função para comprar arrays
int check_arrays(char *array1, char *array2);

//fução para criar arrays
void fillaray(char *saida);

//função para decisão de usuário de sim ou não
int input(void);


// início da função main
int main(void)
{
    //variável para token do usuário atual.
    int usuarioToken;
    //ponteiros para estrutura FILE
    FILE *rootFile;
    FILE *f_index;

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
            if ((rootFile = fopen("root.txt", "wb")) == NULL)
            {
                printf("houve algum erro ao criar o arquivo de usuário root.\n");
            }
            else
            {
                //chama a função "criar usuário para criar o usuário root"
                criar_usuario(rootFile,f_index);
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

char*  conv_str_aray(char *string)
{
    //Cria o array com tanho iguál ao da string.
    char convertaray[strlen(string)];

    //cria um contador que será usado no laço.
    int i = 0;

    //cria laço for para preencher o array criado com os caracteres da string.
    for(i = 0; i <= strlen(string); i++)
    {
        convertaray[i] = string[1];
    }
    print_array(convertaray);
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

//função para criar nome e senha e registralos nos arquivos de registro e indexador
void criar_usuario(FILE *rootfile, FILE *f_index)
{
    //caso não exista um registro de quantidade de usuários ja criada cria uma variável apropriada para receber o valor atual 0.
        user_quantity quantidade_usuarios;

    //cria variável para alocar quantidade de usuários criados
    int last_T_user;
   
   //se a abertura do rquivo indexador no modo de leitura não poder ser realizada
    if(open_file_index(f_index,"index.txt","rb") == 0)
     {
        printf("\nCriando arquivo indexador\n");
        
        //preenche a variável que guarada aquantidade de usuário com 0
        quantidade_usuarios.user_quantity = 0;

        //escreve a váriavel no arquivo root e guarda o endereço dela em uma variável temporária
        long int temp_addres = adapted_fwrite_quantity(quantidade_usuarios,rootfile);

        //fecha arquivo root
        fclose(rootfile);
        

        //abre o arquivo indexador no modo de escrita binária pela primeira vez
        if(open_file_index(f_index,"index.txt","wb") == 1)
        {
            //cria e preenche um arquivo tipo indexador com o endereço do registro da quantidade  de usuários criados
           rindex index;
           index.filename = "quantidade_de_usuarios_registrados";
           index.adress = temp_addres;
           print_array(index.filename);
           printf("\n%ld\n",index.adress);

           printf("\nvariavel de controle de usuarios criada com sucesso\n");

           // escreve a estrutura indexadora no arquivo indexador com os dados
           fwrite(&index,sizeof(rindex),1,f_index);
           
           printf("\nvariavel escrita com sucesso\n");
        }
     }

    //se a abertura do arquivo indexador puder ser realizada
    else if (open_file_index(f_index,"index.txt","rb+") == 1)
    {
        //busca a estrutura que contem a quantidade de usuários criada e guarda endereço dela no arquivo root em variável temporária
        long int temp_addres = Achrindex("quantidade_de_usuarios_registrados",f_index);

        //fecha arquivo indexador
        fclose(f_index);

        //se o arquivo root puder ser aberto
        if(open_file_root(rootfile,"root.txt", "rb+") == 1)
        {
            //antes de ler  é preciso dar um fseek para colocar  o ponteiro no local apropriado para a leitura
            fseek(rootfile,temp_addres,SEEK_SET);
            // lê a variável que contem a quatidade de usuários já criada com o endereço retornado pela função achrindex
            fread(&quantidade_usuarios,sizeof(user_quantity),1,rootfile);
            last_T_user = quantidade_usuarios.user_quantity;
            fclose(rootfile);
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
        root.user_name = userR;
        root.senha = senhaR;

        //escreve o registro de usuário root em root_file
        long int temp_addres = adapted_fwrite_user(root,rootfile);

        //fecha root_file
        fclose(rootfile);

        //se o arquivo indexador puder ser aberto
        if(open_file_index(f_index,"index.txt","rb+"))
        {
            //cria variável do tipo indexador e a preenche com nome e o endereço do registro de usuário root no arquivo root
            rindex index;
            index.filename = "usuario_root";
            index.adress = temp_addres;

            //escreve  a variável no arquivo indexador
            adapted_fwrite_index(index,f_index);
        }
        
    }

    //se algum usuário ja tenha sido criado cria um usuário comum
    else
    {
        usuario comum;
        comum.token = (last_T_user + 1);
        comum.user_name = userR;
        comum.senha = senhaR;
        long int temp_addres = adapted_fwrite_user(comum,rootfile);
        fclose(rootfile);
        if (open_file_index(f_index,"index.txt", "rb+") == 1)
        {   
            rindex index;
            index.adress = temp_addres;
            index.filename = userR;
            adapted_fwrite_index(index,f_index);
        }

    }
    
}

//função para abrir o arquivo indexador    
int open_file_index(FILE *pfile,char *nome_file, char *modo)
{
    if ((pfile = fopen(nome_file, modo)) == NULL)
        {
            printf("\nNao foi possivel abrir o arquivo indexador pela funcao adaptada\n");
            return 0;
        }
    else
    {
        printf("\nArquivo indexador aberto com sucesso\n");
        return 1;
    }
}   

//função para abrir o arquivo root  
int open_file_root(FILE *pfile,char *nome_file, char *modo)
{
    if ((pfile = fopen(nome_file, modo)) == NULL)
        {
            printf("Não foi possível abrir o arquivo root pela função adaptada");
            return 0;
        }
    else
    {
        return 1;
    }
}   

//função para criar senha
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

//função para criar nome de usuário
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
    if(open_file_index(pfile,"index.txt","rb") == 1)
    {
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
    }   
}

int adaptative_fwrite_txt( txt variavel,FILE *file_arquivo)
{

   fwrite(&variavel,sizeof(txt),1,file_arquivo);
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