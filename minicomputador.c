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
struct qUser
{
    char *name;
    int quantity;
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
    char *username;
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
typedef struct qUser quantity;

// troca nome de estrutura por arquivo
typedef struct aindex rindex;

// trocar nome da estrutura para usuário
typedef struct user usuario;

// troca nome da estrutura por txt.
typedef struct txt txt;

    //funções de indexação leitura, abertua e escrita de arquivos

//para a escrita de arquivos do tipo quantidade de usuários
long int adapted_fwrite_quantity( quantity variavel,FILE *file_arquivo);

//função para chegar a exeistência dos arquivos rot e index e relizar suas aberturas realizr um teste de escrita e leitura
int archivecheck(FILE *root, FILE *index);

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

        //Funções de login

//função para checar seo arquivo root ja existe
int archivecheck(FILE *root, FILE *index);

//Função para realizar login
void login (FILE *pindex, FILE *prootfile,int user_token);

//função para criar usuário
void criar_usuario(FILE *rootfile, FILE *index);  

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
int checkArrays(char *array1, char *array2);

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
    if(archivecheck(rootFile,fIndex) == 0)
    {
        printf("\no programa esta sendo executado em uma maquina nova\nE preciso criar um usuario com provilegios de administrador");

        //chama função para criar usuário
         criar_usuario(rootFile,fIndex);
    
    }   
    
    //caso o arquivo root tenha sido encontrado o usuário deve fazer o login.
    if( archivecheck(rootFile,fIndex) == 1)
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
int checkArrays(char *array1, char *array2)
{
    printf("\nEntrou na funcao de checar arrays");
    if (strcmp(array1,array2) == 0)
    {
        printf("A comparacao de strings mostra que ambas sao iguais com retorno (1)");
        return 1;
    }
    else
    {
        printf("\nFuncao check arrays retornou diferença ou  (0) com sucesso");
        return 0;
    }

        
       
        
    
        
        
}

//função para printar arrays
void print_array(char *entrada)
{
    printf("\nEntrou na funcao print arrays");
    
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
    conv_str_aray(string,array);
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



int archivecheck(FILE *fRoot, FILE *findex)
{

    //define variável para recebimento de endereço temporário do arquivo root
    long int tempadress;

    //se root pode ser aberto em modo leitura, diz que ele foi encontrado
    if ((fRoot = fopen("root.txt","rb")) == NULL)
    {
        
        printf("\nArquivo root nao foi encontrado");

        //cria e abre o arquivo root em modo de escrita
        if ((fRoot = fopen("root.txt","wb+")) == NULL)
        {
            printf("\nArquivo root nao pode aberto no modo escrita ");
        }
        else
        {
            printf("\nArquivo root foi criado e aberto no modo escrita ");

            //cria a variável de quantidade de usuários 
            quantity quantUsuarios;

            //preenche seu membro de quantidade com 0
            quantUsuarios.quantity = 0;

            //cria variável temporária para receber endereço de root com fetell
            long int iftempAddres;

            //variável temporária recebe endereço atual de root
            tempadress = ftell(fRoot);

            //fwrite escreve a variável de quantidade de usuários em root
            fwrite(&quantUsuarios,sizeof(quantity),1,fRoot);


        }
        
    }

    else
    {
        printf("\nArquivo root encontrado");
    }
    
    //se index puder ser aberto em modo leitura, diz que ele foi encontrado
    if ((findex = fopen("index.txt","rb+")) == NULL)
    {
        printf("\nArquivo index nao foi encontrado");
        
        if ((findex = fopen("index.txt","wb+")) == NULL)
        {
            printf("\nArquivo indexador não pode ser aberto no modo de escrita binária +");
        }

        else
        {
             printf("\nArquivo index foi criado e aberto no modo escrita binaria + ");

            //declara variável do tipo index
            rindex index;

            //preenche o campo indereço da variável ndex com o endereço temporário retonado pela função ftell
            index.adress = tempadress;

            //preenche o campo namefile da vaiável index com nome
            char *nome = (char*) malloc(sizeof(char));
            printf("\nDigite o nome para ser colocado no arquivo que contem a quantidade de usuarios registrados no sistema\n");
            fillstring(nome);
            index.filename = nome;
            
            //escreve a variável index no arquivo indexador
            fwrite(&index,sizeof(rindex),1,findex);

            //chama função de buscar arquivos indexadores pelo nome
            //variável de dendereço temporário recebe endereço retornado pela função 
            tempadress = Achrindex(nome,findex);

            //variável de exemplo para ser lido pela função fread
            quantity exemple;

            //posiciona ponteiro do arquivo root no endereço retornado pela função
            fseek(fRoot,tempadress,SEEK_SET);

            //tenta ler a variável que contém aquntidade de usuários
            fread(&exemple,sizeof(quantity),1,fRoot);

            printf("A quantidade de usuarios registrada e %d",exemple.quantity);

            //fecha os arquivo root e index
            fclose(fRoot);
            fclose(findex);

            return 0;
        }
        
    }
    else
    {
        printf("\nArquivo index encontrado");

        //fecha os arquivo root e index
        fclose(fRoot);
        fclose(findex);

        return 1;
    }

}

void login (FILE *pindex, FILE *prootfile,int user_token)
{
    //prompt
    printf("\n\nPara realizar o login Digite o nome de usuario\n");

    //alocação de memória para string
    char *name = (char*) malloc(sizeof(char));

    //chamada de função para usuário preencher a string
    fillstring(name);
    print_array(name);

    //prompt
    printf("\n\nNome recebido com sucesso");

    //Criação de variável temporária para receber endereço de memória
    long int temp_addres;

    //criação de variável para ser usada com sentinela em loop
    int status = 0;

    //enquanto o valor sentinela não for modificado
    while (status == 0)
    {
        printf("\n\nentrou no loop com sentinela status");

        //endereço temporário deve receber o endereço retornado pela função achar-index
        temp_addres = Achrindex(name,pindex); 
        if (temp_addres  == -1 )
        {
            printf("\n\nNao foi encontrado um login com este nome de usuario");
            printf("\n\nDigite um nome de usuario valido\n");
            fillstring(name);
        }
        else
        {
            printf("\n\nNome de usuario encontrado");
            status++;
        
        }
    }
    
    //modulação de status para servir como contador
    status = 3;
   
   //estrutura de exemplo criada para ser usada na função fread
    usuario exemple;

    if ((prootfile = fopen("root.txt","ab+")) == NULL)
    {
        printf("\nNao foi possível abrir o arquivo root no modo de adicao +");
    }
    else
    {
        //fseek transloca ponteiro para endereço retornado pela função achar index que foi guardada na vairável de endereço temporario
        fseek(prootfile,temp_addres,SEEK_SET);


        printf("\n\ntranslacao para o endereco temporario realizada com sucesso");

        // lê a variável encontrada no arquivo
        fread(&exemple,sizeof(usuario),1,prootfile);
        printf("\n\nLeitura da variavel usuario realizada");


        //alocação de memória para string
        char *senha = (char*) malloc(sizeof(char));

        //chamada de função para usuário preencher a string
        fillstring(senha);
        print_array(senha);

        //enquanto a função de comparação de arrays não receber uma senha igual á que foi registrada
        while (checkArrays(name,exemple.senha) == 0)
        {
            //mensagemq que mostra que a sena está errada
            printf("\n\nsenha incorreta");

            //atualiza contador de  acoro com a quantidade de tentativas restantes
            status--;

            //informa quantas tentativas reatntes o usuário ainda tem
            printf("\n\nvocê tem mais %d tentativas\nCaso você erre asenha mais 2 vezes, todos os arquivos serão apagados",status);

            fillstring(senha);

            //se o contador zerar, a função de corromper arquivos é chamada
            if (status == 0);
            {
                //chama a função de corromper arquivos
            }
        
        }

        //Informa ao usuário que o login foi efetuado com sucesso
        printf("\n\n Login efeituado com sucesso");
        user_token = exemple.token;
    }
    fclose(prootfile);
    fclose(pindex);
}

//função para criar nome e senha e registralos nos arquivos de registro e indexador
void criar_usuario(FILE *rootfile, FILE *fIndex)
{
    //checa se a abertura do arquivo root em leitua e escrita pode ser feita
    if ((rootfile = fopen("root.txt","ab+")) == NULL)
    {
        printf("O arquivo root não pode ser aberto no modo de leitura e escrita");
    }
    else
    {
        printf("\nAbertura do arquivo root realizada com sucesso");
    }
    
   
   //se a abertura do rquivo indexador no modo de leitura não poder ser realizada
     if ((fIndex = fopen("index.txt","ab+")) == NULL)
    {
        printf("Arquivo index nao pôde ser aberto no modo de adição e leitura binaria+");
    }
    else
    {
        //ponteiros para retornar senha e usuário.
        char *userR = (char*) malloc(sizeof(char));
        char *senhaR = (char*) malloc(sizeof(char));

        //chama as respectivas funções para a criação de usuáro e senha.
        criarUserName(userR);
        criarSenha(senhaR);
        
        //variável para gurdar endereço temporário
        long int tempaddres;

        char *arquivoquant = (char*) malloc(sizeof(char));
        printf("Digite qual o nome do arquivo que contera a quantidade de usuarios registrados\n");
        fillstring(arquivoquant);


        //recebe endereço retornado pela função que buscou o arquivo que contem a quntidade de usuários registrada
        tempaddres = Achrindex(arquivoquant,fIndex);

        //transloca ponteiro para edereço retornado pela função que foi guardado na variável temporária
        fseek(rootfile,tempaddres,SEEK_SET);

        //cria variável de exemplo para ser usada por fread
        quantity exemple;

        //lê variável para adiquirrir quantidade ed suuários já registrados
        fread(&exemple.quantity,sizeof(quantity),1,rootfile);

        //se a quantidade de usuários criada for 0
        if(exemple.quantity == 0)
        {
            printf("A quantidade de usuarios registrada e %d",exemple.quantity);

            //cria uma estrutura de usuário para o primeiro usuário (root)
            usuario root;

            //preenche seu token com 999
            root.token = 999;

            //converte a string de userR para o campo username da estrutura criada
            root.username = userR;

            //converte a string de userR para o campo senha da estrutura criada
            root.senha = senhaR;

                //alternativa de uso de função para caso não funcione a escrita com ponteiros
            //conv_str_aray(userR, root.user_name);
            //conv_str_aray(senhaR,root.senha);

           // Uma variável temporária recebe o endereço da atual posição de escrita em rootfile
            long int temp_addres = ftell(rootfile);
           
            //escreve o registro de usuário root em root_file
            fwrite(&root,sizeof(usuario),1,rootfile);

                //verssão alternativa de escrita que não deve ser usada caso escrita de ponteiros pela função fwrite não funcione
            //long int temp_addres = adapted_fwrite_user(root,rootfile);
            
            //cria variável do tipo indexador e a preenche com nome e o endereço do registro de usuário root no arquivo root
            rindex index;
            index.filename = userR;
            //conv_str_aray("usuario_root",index.filename);
            index.adress = temp_addres;

            //escreve  a variável no arquivo indexador
            fwrite(&index,sizeof(rindex),1,fIndex);
            //adapted_fwrite_index(index,fIndex);
            
        
        }

        //se algum usuário ja tenha sido criado cria um usuário comum
        else
        {
            usuario comum;
            comum.token = (exemple.quantity + 1);

            // estrutura de usuário comum recebe nome e senha de userR e senhaR
            comum.username = userR;
            comum.senha = senhaR;

                    //modo diferente de pasar falores caso não possa ser feita escrita por ponteiro
            // conv_str_aray(userR,comum.username);
            // conv_str_aray(senhaR,comum.senha );


            long int temp_addres = ftell(rootfile);


            fwrite(&comum,sizeof(usuario),1, rootfile);
             
            //cria variável do tipo d eregistro indexador
            rindex index;

            //o campo de endereço da variável recebe endereço guardado da variável temporária
            index.adress = tempaddres;

            //campo de nome de arquivo recebe nome guardado por UserR
            //conv_str_aray(userR,index.filename);
            index.filename = userR;

            //escreve variável no arquivo indexador
            fwrite(&index,sizeof(rindex),1,fIndex);
            
        }
    }
    fclose(fIndex);
    fclose(rootfile);
    
}

//função para criar senha
void criarSenha(char *retorno)
{
    //endereço para senha ser retornada da função de criararrays
    char *teste = (char*) malloc(sizeof(char));
    

    //mensagem para usuário inserir a senha
    printf("\n\nDigite a senha desejada\n");

    //chama a função criar arays para fazer a senha
    fillstring(teste);
    
    //mensagem para o usuário digitar a senha novamente
    printf("\n\nDigite a senha novamente\n");

    // chama a função de criar arays novamente 
    fillstring(retorno);

    // Loop que compara as senhas, caso elas sejam diferentes pede ao usuário para reescreve-las
   while(checkArrays(teste,retorno) == 0)
    {
        printf("\nA senha precisa ser igual a digitada anterioremente\n");
        printf("\nDigite a senha desejada\n");
        fillstring(teste);
        printf("\nDigite a senha novamente\n");
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
        printf("\n\nDigite o nome de usuario desejado\n");

        //chama a função criar arays para fazer o nome de usuário
        fillstring(aray);

        //mensagem para o usuário confirmar o nome de usuário
        printf("\n\nO nome de usuario que voce digitou e: ");

        //mostra o nome digitado
        print_array(aray);

        //Caso o usuário deseje ele pode reescrever o nome
        printf("\n\nVoce deseja reescreve-lo?\nDgite (1) para sim e (0) para nao\n ");
        choice = input();
    }
}



//função que busca registros de arquivos indexadore por nome e retorna endereço no arquivo root
long int Achrindex(char *nomearquivo, FILE *pfile)
{
     if ((pfile = fopen("index.txt","rb")) == NULL)
    {
        printf("Houve um problema ao abrir o arquivo indexador no mode de leitura binaria");
    }
    else
    {
        
        printf("\n\nentrou na funcao achindex");

        printf("\n\ncricou a variavel de exemplo");
        rindex exemple;
        
        printf("\no nome do arquivo e %s",nomearquivo);
        rewind(pfile);

        printf("\n\nresetou o ponteiro");
        fseek(pfile, 0 ,SEEK_SET);

        while((fread(&exemple,sizeof(rindex),1,pfile)) == 1)
        {
            printf("\n\nentrou no loop de leitura\n");

            printf("\no nome de exemple depois de lido e %s ",exemple.filename);

            long int retorno;

            //int cont = 0;
           

            retorno = exemple.adress;
            char *temp = (char*) malloc(sizeof(char));
            temp = exemple.filename;
            printf("\no valor retornado pela variavel exemple.addres e %ld",retorno);

            int i = checkArrays(temp,nomearquivo);

            if(  i == 1)
            {
                fclose(pfile);
                return retorno;
            }

            else
            {
                if (fseek(pfile,sizeof(rindex),SEEK_CUR) == 0)
                {
                    printf("\nfuncao fseek funcionou corretamente");
                }
            }

           
        }

        printf("\n saiu do loop de leitura\n");

        fclose(pfile);

        return -1;
    }
    
}



/*void MenuInicial(void)

{
   ;
    printf("\n\nOla, seja bem vindo ao programa de computador de Fabraccho\nDigite seu nome de usuário 0 para entrar como um convidado.\nUser:");
    while ( getchar() != '\n')
    {
    
    }

   

}
*/