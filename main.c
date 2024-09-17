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
//------------------------------------------------------------------------------------------------------------------
int validarLogin(struct Bibliotecario bibliotecarios[], int numBibliotecarios){
    char nome[30], senha[20];
    int i;

    printf("##Login##\n");
    printf("Nome: ");
    scanf(" %[^\n]s", nome);
    printf("Senha: ");
    scanf(" %[^\n]s", senha);

    for(i = 0;i < numBibliotecarios;i++){
        //Strcmp está comparando as string da struct bibliotecário e a de login.
        if(strcmp (bibliotecarios[i].nome,nome) == 0 && strcmp(bibliotecarios[i].senha,senha)==0){
            printf("**Login realizadop com sucesso**\n");
            return 1;// retorna 1 se o login estiver correto
        }

    }
    printf("**Nome ou Senha invalida,**.\nEnter para voltar");
    getchar();
    getchar();
    return 0;// retorna 0 se o login estiver errado
    //Estrutura para validar login.
    system("cls");
}
//----------------------------------------------------------------------------------------------------------------
void exibirLivros(struct Livro livros[],int numLivros){

    if(numLivros == 0){
        printf("Nenhum livro cadastrado\n");
        return;
    }

    printf("\n###Livros cadastrados###\n");
    // int i = 0: significa que o contador i em 0, indica que o primeiro livro está na posição 0 do array.
    for(int i = 0;i < numLivros;i++){
        printf("%d.%s-%s(%s)\n",i+1,livros[i].nome,livros[i].autor,livros[i].disponivel ?"Disponivel":"Reservado");
    }
    printf("\n\n**Aperte enter para voltar**");
    getchar();
    getchar();
    system("cls");

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
//---------------------------------------------------------------------------------------------------------------------
void excluirLivros(struct Livro livros[],int *numLivros){
    int escolha;

    if(numLivros == 0){
        printf("Nenhum livro cadastrado.\n");
        return;
    }
    exibirLivros(livros, &numLivros);
    printf("Digite o numero do livro quedeseja excluir: ");
    scanf("%d",&escolha);

    if(escolha < 1 || escolha > *numLivros){
        printf("Opcao invalida.\n");
    }
    //remove o livro e ajusta o array.
    for(int i = escolha -1;i < *numLivros - 1;i++){
        (livros[i]=livros[i+1]); //move todos os livros uma posição para traz no array.
    }
    (*numLivros)--;// Diminui o numero de livros.
    printf("\n**livro excluido com sucesso**\n");
}
void exibirMenu(struct Livro livros[],int *numLivros,struct Usuario usuarios[],int *numUsuarios,struct Bibliotecario bibliotecarios[],int *numBibliotecarios){
    int sub_menu,exclu_menu;
    do {
        printf("\n***Escolha uma opcao***\n");
        printf("Lista de livros[1]\n");
        printf("Lista de usuarios[2]\n");
        printf("Lista de bibliotecarios[3]\n");
        printf("Excluir livros/usuarios/bibliotecarios[4]\n");
        printf("Devolucao de livros[5]\n");
        printf("Bloqueio de usuario[6]\n");
        printf("Relatorios[7]\n");
        printf("voltar[0]\n");
        scanf("%d", &sub_menu);
        system("cls");

        switch (sub_menu) {
            case 1:
                // exibirLivros(livros, numLivros);
               exibirLivros(livros,*numLivros);
                break;
            case 2:
                // exibirUsuarios(usuarios, numUsuarios);
                printf("Exibir usuários...\n");
                break;
            case 3:
                // exibirBibliotecarios(bibliotecarios, numBibliotecarios);
                printf("Exibir bibliotecários...\n");
                break;
            case 4:
                do {
                    printf("Excluir Livros[1]\n");
                    printf("Excluir usuarios[2]\n");
                    printf("Excluir Bibliotecario[3]\n");
                    printf("voltar[0]\n");
                    scanf("%d", &exclu_menu);
                    system("cls");

                    switch (exclu_menu) {
                        case 1:
                            // excluirLivros(livros, numLivros);
                            printf("Excluir livros...\n");
                            break;
                        case 2:
                            // excluirUsuarios(usuarios, numUsuarios);
                            printf("Excluir usuários...\n");
                            break;
                        case 3:
                            // excluirBibliotecario(bibliotecarios, numBibliotecarios);
                            printf("Excluir bibliotecário...\n");
                            break;
                        case 0:
                            break;
                        default:
                            printf("Opcao invalida!\n");
                            break;
                    }
                } while (exclu_menu != 0);
                break;
            case 5:
                // Implementar devolução de livros
                printf("Devolução de livros...\n");
                break;
            case 6:
                // Implementar bloqueio de usuário
                printf("Bloqueio de usuário...\n");
                break;
            case 7:
                // Implementar relatórios
                printf("Relatórios...\n");
                break;
            case 0:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }

    } while (sub_menu != 0);
}






int main(){

    struct Usuario usuarios[max_usuarios];
    struct Bibliotecario bibliotecarios[max_bibliotecarios];
    struct Livro livros[max_livros];

    int numUsuarios = 0, numBibliotecarios = 0, numLivros = 0;
    int opcao;
    memset(livros, 0, sizeof(livros));

    do{

        printf("\n####Bem vindo###\n");
        printf("Cadastrar Bibliotecario[1]\n");
        printf("Cadastrar Usuario[2]\n");
        printf("Cadastrar Livro[3]\n");
        printf("Login[4]\n");
        printf("sair[0]\n");
        scanf("%d", &opcao);
        system("cls");

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
              if(validarLogin(bibliotecarios, numBibliotecarios)){
                exibirMenu(livros,&numLivros,usuarios,&numUsuarios,bibliotecarios,&numBibliotecarios);
              }

            case 0:
                printf("saindo...");
                system("cls");
                break;
            default:
            printf("opcao invalida");
        }
    }while(opcao != 0);




  return 0;
}
