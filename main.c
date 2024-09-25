#include <stdio.h>//Utilizada nesse PGM pelo printf()/scanf().
#include <string.h>//Utilizada para strcmp/strcpy.
#include <stdlib.h>// talvez um uso de exit (ainda n em uso).
//..................................................................................................................................................................
#define max_usuarios 10
#define max_bibliotecarios 5
#define max_livros 10
#define max_emprestimos 10
// Define está definindo o maximo de usuarios,bibliotecarios e livros que podem ser cadastrados.
//..................................................................................................................................................................
struct Usuario{
    char nome[30];
    char RA[8];
    int idade;
};
// Estrutura para armazenar dados dos usuários.
struct Bibliotecario{
    char nome[30];
    char senha[20];
    char cod_b[10];

};
// Estrutura para armazenar dados dos bibliotecários.
struct Livro{
    char nome[30];
    char autor[30];
    char cod_li[10];
    int disponivel;
};
// Estrutura para armazenar dados dos livros.
struct Emprestimo{
   char cod_li[10];
   char RA[8];
};
//Estrutura para armazenar usuário a livro emprestado.
//..................................................................................................................................................................
void atualizarBibliotecario(struct Bibliotecario bibliotecarios[],int numBibliotecarios){
   char cod_b[10];

   printf("\nDigite o codigo do bibliotecario a ser atualizado: ");
   scanf(" %[^\n]s", &cod_b);
   getchar();

    for(int i= 0;i < numBibliotecarios;i++){
        if(strcmp(bibliotecarios[i].cod_b,cod_b)== 0){
            printf("\n*Bibliotecario encontrado*\n");
            printf("\nDigite o novo nome do Bibliotecarios: ");
            scanf(" %[^\n]s", &bibliotecarios[i].nome);
            getchar();

            printf("\nDigite nova a senha: ");
            scanf(" %[^\n]s", &bibliotecarios[i].senha);
           

            printf("\nDigite novo codigo de cadastro: ");
            scanf(" %[^\n]s", &bibliotecarios[i].cod_b);
            
            printf("\n**Bibliotecario atualizado sucesso**\n *Enter para voltar*");
            getchar();
            getchar();
            system("cls");
            return;
            
        }
    }
    printf("\n Bibliotecario com o codigo %s nao encontrado. \n", cod_b);
    getchar();
}//Estrutura para atualização de cadastro de bibliotecarios.
//...................................................................................................................................................................
void atualizarUsuario(struct Usuario usuarios[],int numUsuarios){
    char cod_u[10];

    printf("Digite o codigo do usuario a ser atualizado : ");
    scanf( " %[^\n]s", &cod_u);
    getchar();

    for(int i = 0;i < numUsuarios;i++){
        if(strcmp(usuarios[i].RA,cod_u)==0){
            printf("\n**Usuario encontrado**\n");
            printf("\nDigite novo nome de usuario:");
            scanf(" %[^\n]s", &usuarios[i].nome);

            printf("Digite novo RA: ");
            scanf(" %[^\n]s", &usuarios[i].RA);

            printf("Digite nova idade: ");
            scanf("%d", &usuarios[i].idade);

            printf("\n** Usuario atualizado com sucesso**\n *Enter para voltar*");
            getchar();
            getchar();
            system("cls");
            return;
        }
    }
    printf("\n Usuario com RA %s nao encontrado.\n",cod_u);
    getchar();
}//Estrutura para atualização de cadastro de usuario.
//...................................................................................................................................................................
void atualizarLivro(struct Livro livros[],int numLivros){
    char cod_l[10];

    printf("\nDigite o codigo do livro a ser atualizado: ");
    scanf(" %[^\n]s", &cod_l);
    getchar();

    for(int i = 0;i < numLivros;i++){
        if(strcmp(livros[i].cod_li,cod_l)==0){
        printf("\n**livro encontrado**\n\n");
        printf("Digite novo nome do livro: ");
        scanf(" %[^\n]s", &livros[i].nome);
        printf("\nDigite novo nome de autor: ");
        scanf(" %[^\n]", &livros[i].autor);
        printf("\nDigite novo codigo do livro: ");
        scanf(" %[^\n]s", &livros[i].cod_li);

        printf("\n**Livro atualizado com sucesso**\n *Enter para voltar*");
        getchar();
        getchar();
        system("cls");
        return;
        }
    }
    printf("\n Livro com codigo %s nao encontrado.",cod_l);
    getchar();
}// Estrutura para atualizar cadastro de livros.
//...................................................................................................................................................................
void emprestarLivro(struct Usuario usuarios[],int numUsuarios,struct Livro livros[],int numLivros,struct Emprestimo emprestimos[],int *numEmprestimos){
    char cod_li[10],RA[8];
    int livroInd = -1,usuarioInd = -1;// variavel indice criada para comparar se existe ou não usuario e livro.

    printf("\nDigite o codigo do livro que deseja emprestar: ");
    scanf(" %[^\n]s", &cod_li);

    for(int i = 0;i < numLivros;i++){
        if(strcmp(livros[i].cod_li,cod_li)== 0){
            livroInd = i;
            break;//comando para procurar o livro,e o strcmp para verificar se o cod do livro bate com o cod digitado.
        }
    }
    if(livroInd == -1){
        printf("\nLivro nao encontrado.\n");
        return;
    }
    if(livros[livroInd].disponivel == 0){
        printf("\nLivro ja foi emprestado.\n");
        return;
    }
    printf("\nDigite o RA so usuario a quem o livro vai ser emprestado: ");
    scanf(" %[^\n]s", &RA);

    for(int i = 0;i < numUsuarios;i++){
        if(strcmp(usuarios[i].RA,RA)== 0){
            usuarioInd = i; 
            break;
        }
    }
    if(usuarioInd == -1){
        printf("\nUsuario nao encontrado.\n");
        return;
    }
    livros[livroInd].disponivel = 0;
    //Empresta o livro e marca como emprestado

    strcpy(emprestimos[*numEmprestimos].cod_li, livros[livroInd].cod_li);
    strcpy(emprestimos[*numEmprestimos].RA, usuarios[usuarioInd].RA);
    (*numEmprestimos)++;
    //registra o emprestimo.
    printf("\nLivro '%s' foi emprestado para o usuario '%s'.\n ",livros[livroInd].nome,usuarios[usuarioInd].nome);
    getchar();
    getchar();
    system("cls");
}//Estrutura para vincular livro emprestado a usuario.

//..................................................................................................................................................................

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
    getchar();
    getchar();
    system("cls");
}//Estrutura para cadastro de Usuário.
//..................................................................................................................................................................

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
    printf("Digite o codigo de resgistro do Bibliotecario: ");
    scanf(" %[^\n]s", &bibliotecarios[*numBibliotecarios].cod_b);
    (*numBibliotecarios)++;
    printf("\n**bibliotecario cadastrado com sucesso**\n");
    getchar();
    getchar();
    system("cls");
}//Estrutura para cadastro de Bibliotecário.
//..................................................................................................................................................................

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
    printf("codigo: ");
    scanf(" %[^\n]s", &livros[*numLivros].cod_li);
    livros[*numLivros].disponivel = 1;
    (*numLivros)++;
    printf("\n**livro cadrastado com sucesso**\n");
    getchar();
    getchar();
    system("cls");
}//Estrutura para cadastro de Livros.
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
    getchar();//para pausar o progama para n ir para procima tela direto
    getchar();
    return 0;// retorna 0 se o login estiver errado
    system("cls");
}//Estrutura para validar login.
//----------------------------------------------------------------------------------------------------------------
void exibirLivros(struct Livro livros[],int numLivros){

    if(numLivros == 0){
        printf("Nenhum livro cadastrado\n");
        return;
    }

    printf("\n###Livros cadastrados###\n");
    // int i = 0: significa que o contador i em 0, indica que o primeiro livro está na posição 0 do array.
    for(int i = 0;i < numLivros;i++){
        printf("%d. %s - (Autor) %s - codigo *%s* (%s)\n",i+1,livros[i].nome,livros[i].autor,livros[i].cod_li,livros[i].disponivel ?"Disponivel":"Reservado");
    }
    printf("\n\n**Aperte enter para voltar**");
    getchar();
    getchar();
    system("cls");

}//Estrutura para exibir livros cadastrados.
//..................................................................................................................................................................
void exibirUsuarios(struct Usuario usuarios[],int numUsuarios){
    
    if(numUsuarios == 0){
        printf("\nNenhum usuario cadastrado\n");
        return;
    }
    
    printf("\n###Usuarios cadastrados###\n");
    for(int i = 0;i < numUsuarios;i++){
        printf("%d. %s - %d anos-RA %s\n",i+1,usuarios[i].nome,usuarios[i].idade,usuarios[i].RA);
    }
    printf("\n\n**Aperte enter para voltar**");
    getchar();
    getchar();
    system("cls");
}//Estrutura para exibir usuarios cadastrados.
//..................................................................................................................................................................
void exibirBibliotecarios(struct Bibliotecario bibliotecarios[],int numBibliotecarios){
   
   if(numBibliotecarios== 0){
        printf("\nNenhum bibliotecario cadastrado\n");
        return;
    }
   
    printf("\n###Bibliotecarios cadastrados###\n");
    for(int i=0;i <numBibliotecarios;i++){
        printf("%d. %s - codigo %s\n",i+1,bibliotecarios[i].nome,bibliotecarios[i].cod_b);
    }
    printf("\n\n**Aperte enter para voltar**");
    getchar();
    getchar();
    system("cls");
}//Estrutura para exibir bibliotecarios cadrastrados.
//---------------------------------------------------------------------------------------------------------------------
void excluirLivros(struct Livro livros[],int *numLivros){
    int escolha;

    if(*numLivros == 0){
        printf("Nenhum livro cadastrado.\n");
        return;
    }
    exibirLivros(livros, *numLivros);
    printf("Digite o numero do livro que deseja excluir: ");
    scanf("%d",&escolha);

    if(escolha < 1 || escolha > *numLivros){
        printf("Opcao invalida.\n");
        return;
    }
    //remove o livro e ajusta o array.
    for(int i = escolha -1;i < *numLivros - 1;i++){
        (livros[i]=livros[i+1]); //move todos os livros uma posição para traz no array.
    }
    (*numLivros)--;// Diminui o numero de livros.
    printf("\n**livro excluido com sucesso**\n");
}//Estrutura para excluir livros.
//..................................................................................................................................................................
void excluirUsuarios(struct Usuario usuarios[],int *numUsuarios){
    int escolha;

    if(*numUsuarios == 0){
        printf("Nenhum usuario cadastrado.\n");
        return;
    }
    exibirUsuarios(usuarios,*numUsuarios);
    printf("Digite o numero do usuario que deseja excluir: ");
    scanf("%d",&escolha);

    if(escolha < 1 || escolha > *numUsuarios){
        printf("opcao invalida.\n");
        return;
    }
    for(int i = escolha -1;i < *numUsuarios -1;i++){
        (usuarios[i]=usuarios[i+1]);
    }
    (*numUsuarios)--;
}//Estrutura para excluir usuarios.
//..................................................................................................................................................................
void excluirBibliotecarios(struct Bibliotecario bibliotecarios[],int *numBibliotecarios){
    int escolha;

    if(*numBibliotecarios == 0){
        printf("Nenhum bibliotecario cadastrado.\n");
        return;
    }
    exibirBibliotecarios(bibliotecarios,*numBibliotecarios);
    printf("Digite o numero do bibliotecario que deseja excluir: ");
    scanf("%d",&escolha);

    if(escolha < 1 || escolha > *numBibliotecarios){
        printf("opcao invalida.\n");
        return;
    }
    for(int i = escolha -1;i < *numBibliotecarios -1;i++){
        (bibliotecarios[i]=bibliotecarios[i+1]);
    }
    (*numBibliotecarios)--;
}//Estrutura para excluir bibliotecario.
//..................................................................................................................................................................
void exibirMenu(struct Livro livros[],int *numLivros,struct Usuario usuarios[],int *numUsuarios,struct Bibliotecario bibliotecarios[],int *numBibliotecarios,struct Emprestimo emprestimos[],int *numEmprestimos){
    int sub_menu,exclu_menu,atz_menu;
    do {
        printf("\n***Escolha uma opcao***\n");
        printf("Lista de livros[1]\n");
        printf("Lista de usuarios[2]\n");
        printf("Lista de bibliotecarios[3]\n");
        printf("Excluir livros/usuarios/bibliotecarios[4]\n");
        printf("Emprestimo de livros[5]\n");
        printf("Atualizacao de dados[6]\n");
        printf("Relatorios[7]\n");
        printf("voltar[0]\n");
        scanf("%d", &sub_menu);
        system("cls");
//Looping de DO-While para sub menu.
        switch (sub_menu) {
            case 1:
                // exibirLivros.
               exibirLivros(livros,*numLivros);
                break;
            case 2:
                // exibirUsuarios.
                exibirUsuarios(usuarios,*numUsuarios);
                break;
            case 3:
                // exibirBibliotecarios.
                exibirBibliotecarios(bibliotecarios,*numBibliotecarios);
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
                            // excluirLivros.
                            excluirLivros(livros,numLivros);
                            break;
                        case 2:
                            // excluirUsuarios.
                            excluirUsuarios(usuarios,numUsuarios);
                            break;
                        case 3:
                            // excluirBibliotecario.
                            excluirBibliotecarios(bibliotecarios,numBibliotecarios);
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
                //emprestimo de livros.
                emprestarLivro(usuarios,*numUsuarios,livros,*numLivros, emprestimos,numEmprestimos);
                break;
            case 6:
                // atualizar dados
                
                do{
                    printf("\n[1] Atualizacao de bibliotecarios\n");
                    printf("[2] Atualizacao de usuarios\n");
                    printf("[3] Atualizacao de livros\n");
                    printf("[0] Para voltar\n");
                    scanf("%d", &atz_menu);
                    system("cls");

                    switch(atz_menu) {
                        case 1:
                            atualizarBibliotecario(bibliotecarios,*numBibliotecarios);
                            break;
                        case 2:
                            atualizarUsuario(usuarios,*numUsuarios);
                            break;
                        case 3:
                            atualizarLivro(livros,*numLivros);
                            break;
                        case 0:
                            printf("\n**voltando**\n");
                            break;
                            default:
                            printf("\n**opcao invalida**\n");
                            break;

                    }
                }while(atz_menu != 0);
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
}//Estrutura criada para chamar um sub-menu
//..................................................................................................................................................................


int main(){

    struct Usuario usuarios[max_usuarios];
    struct Bibliotecario bibliotecarios[max_bibliotecarios];
    struct Livro livros[max_livros];
    struct Emprestimo emprestimos[max_emprestimos];
//As structs acima estão sendo vinculada a quantidade maxima que podem ser cadastradas.
    int numUsuarios = 0, numBibliotecarios = 0, numLivros = 0, numEmprestimos = 0;
    //variavies acima criada para identificar que o numero de usuarios,livros,bibliotecarios,emprestimos comecem com 0 para n pegar lixo de memória.
    int opcao;
    memset(livros, 0, sizeof(livros));//limpesa de lixo de memória

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
                exibirMenu(livros,&numLivros,usuarios,&numUsuarios,bibliotecarios,&numBibliotecarios,emprestimos,&numEmprestimos);
              }

            case 0:
                printf("saindo...");
                system("cls");
                break;
            default:
            printf("opcao invalida");
        }
    }while(opcao != 0);
//Estrutura do menu principal.
//..................................................................................................................................................................

  return 0;
}
