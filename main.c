#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max_usuarios 10
#define max_bibliotecarios 5
#define max_livros 10
// Define está definindo o maximo de usuarios,bibliotecarios e livros que podem ser cadastrados.
struct Usuario{
    char nome[30];
    char RA[8];
    int idade;
};
// Estrutura para armazenar dados dos usuários.
struct Bibliotecario{
    char nome[30];
    char senha[20];

};
// Estrutura para armazenar dados dos bibliotecários.

struct Livro{
    char nome[30];
    char autor[30];
    int disponivel;
};
// Estrutura para armazenar dados dos livros.
void cadastrarUsuario(struct Usuario usuarios[],int *numUsuarios){
    if(*numUsuarios >= max_usuarios){
        printf("***Limite de usuarios atingido***\n");
        return;
    }
    printf("###Cadastro de usuarios###\n");
    printf("Digite o nome: ");
    scanf(" %[^\n]s", &usuarios[*numUsuarios].nome);
    printf("Digite o RA: ");
    scanf(" %[^\n]s", &usuarios[*numUsuarios].RA);
    printf("Digite a idade: ");
    scanf("%d", &usuarios[*numUsuarios].idade);
    (*numUsuarios)++;
    printf("**Usuario cadastrado com sucesso**\n");
    system("cls");
}
//Estrutura para cadastro de Usuário.
void cadastrarBibliotecario(struct Bibliotecario bibliotecarios[],int *numBibliotecarios){
    if(*numBibliotecarios >= max_bibliotecarios){
        printf("***Limite de bibliotecarios atingido\n***");
        return;
    }
    printf("\n###Cadastro de bibliotecarios###\n");
    printf("digite o nome: ");
    scanf(" %[^\n]s", &bibliotecarios[*numBibliotecarios].nome);
    printf("digite a senha: ");
    scanf(" %[^\n]s", &bibliotecarios[*numBibliotecarios].senha);
    (*numBibliotecarios)++;
    printf("\n**bibliotecario cadastrado com sucesso**\n");
    system("cls");
}
//Estrutura para cadastro de Bibliotecário.
void cadastrarLivro(struct Livro livros[],int *numLivros){
    if(*numLivros >= max_livros){
        printf("\n***Limite de livros atingido***\n");
        return;
    }
    printf("###Cadastro de livros###\n");
    printf("Nome do livro: ");
    scanf(" %[^\n]s", &livros[*numLivros].nome);
    printf("Autor: ");
    scanf(" %[^\n]s", &livros[*numLivros].autor);
    livros[*numLivros].disponivel = 1;
    (*numLivros)++;
    printf("\n**livro cadrastado com sucesso**\n");
    system("cls");
}
//Estrutura para cadastro de Livros.
int validarLogin(struct Bibliotecario bibliotecarios[], int numBibliotecarios){
    char nome[30], senha[20];
    int i;

    printf("##Login##\n");
    printf("Nome: ");
    scanf(" %[^\n]s", &nome);
    printf("Senha: ");
    scanf(" %[^\n]s", &senha);

    for(i = 0;i < numBibliotecarios;i++){
        //Strcmp está comparando as string da struct bibliotecário e a de login.
        if(strcmp (bibliotecarios[i].nome,nome) == 0 && strcmp(bibliotecarios[i].senha,senha)==0){
            printf("**Login realizadop com sucesso**\n");
            return 1;// retorna 1 se o login estiver correto
        }
    }
    printf("**Nome ou Senha invalida**.\n");
    return 0;// retorna 0 se o login estiver errado
}
void exibirLivros(struct Livro livros[],int numLivros){
    printf("\n###Livros cadastrados###\n");
    // int i = 0: significa que o contador i em 0, indica que o primeiro livro está na posição 0 do array.
    for(int i = 0;i < numLivros;i++){
        printf("%d.%s-%s(%s)",i+1,livros[i].nome,livros[i].autor,livros[i].disponivel ?"Disponivel":"Reservado");
    }
}
void exibirUsuarios(struct Usuario usuarios[],int numUsuarios){
    printf("\n###Usuarios cadastrados###\n");
    for(int i = 0;i < numUsuarios;i++){
        printf("%d.%s-%danos-RA%s",i+1,usuarios[i].nome,usuarios[i].idade,usuarios[i].RA);
    }
}
void exibirBibliotecarios(struct Bibliotecario bibliotecarios[],int numBibliotecarios){
    printf("\n###Bibliotecarios cadastrados###\n");
    for(int i=0;i <numBibliotecarios;i++){
        printf("%d.%s",i+1,bibliotecarios[i].nome);
    }
    //do exibir livros até exibir bibliotecarios são as Estruturas para chamar a lista
}





int main(){

    struct Usuario usuarios[max_usuarios];
    struct Bibliotecario bibliotecarios[max_bibliotecarios];
    struct Livro livros[max_livros];

    int numUsuarios = 0, numBibliotecarios = 0, numLivros = 0;
    int opcao;

    do{

        printf("\n####Bem vindo###\n");
        printf("Cadastrar Bibliotecario[1]\n");
        printf("Cadastrar Usuario[2]\n");
        printf("Cadastrar Livro[3]\n");
        printf("Login[4]\n");
        printf("sair[0]\n");
        scanf("%d", &opcao);
        
        switch(opcao){
            case 1:
                cadastrarBibliotecario(bibliotecarios, &numBibliotecarios);
                break;
            case 2:
                cadastrarUsuario(usuarios, &numUsuarios);
                break;
            case 3:
                cadastrarLivro(livros, &numLivros);
                break;
            case 4:
                validarLogin(bibliotecarios, numBibliotecarios);

                printf("oi");
                break;
            case 0:
                printf("saindo...");
                break;
            default:
            printf("opcao invalida");
        }
    }while(opcao != 0);




  return 0;
}