#include <stdio.h>//Utilizada nesse PGM pelo printf()/scanf().
#include <string.h>//Utilizada para strcmp/strcpy.
#include <stdlib.h>// talvez um uso de exit (ainda n em uso).
//..................................................................................................................................................................
#define max_usuarios 10
#define max_bibliotecarios 5
#define max_livros 10
#define max_emprestimos 10
#define max_admins 10
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
struct Admin{
    char nome[30];
    char senha[20];
};//Estrutura para admin.(já sera pré-definido) 
//..................................................................................................................................................................
void atualizarBibliotecario(struct Bibliotecario bibliotecarios[],int *numBibliotecarios){
   char cod_b[10];
   printf("\n###Bibliotecarios cadastrados###\n");
    for(int j=0;j < *numBibliotecarios;j++){
        printf("%d. Bibliotecario: %s - Codigo: %s\n",j+1,bibliotecarios[j].nome,bibliotecarios[j].cod_b);
    }

   printf("\nDigite o codigo do bibliotecario a ser atualizado: ");
   scanf(" %[^\n]s", &cod_b);
   getchar();

    for(int i= 0;i < *numBibliotecarios;i++){
        if(strcmp(bibliotecarios[i].cod_b,cod_b)== 0){
            printf("\n*Bibliotecario encontrado*\n");
            printf("\nDigite o novo nome do Bibliotecarios: ");
            scanf(" %[^\n]s", &bibliotecarios[i].nome);
            getchar();

            printf("\nDigite nova a senha: ");
            scanf(" %[^\n]s", &bibliotecarios[i].senha);
                      
            printf("\n**Bibliotecario atualizado sucesso**\n\n *Enter para voltar*");
            getchar();
            getchar();
            system("cls");
            return; 
        }
                       
    }
    printf("\n Bibliotecario com o codigo %s nao encontrado. \n\n aperte Enter. \n", cod_b);
    getchar();
}//Estrutura para atualização de cadastro de bibliotecarios.
//...................................................................................................................................................................
void atualizarUsuario(struct Usuario usuarios[],int *numUsuarios){
    char cod_u[10];

    printf("\n###Usuarios cadastrados###\n");
    for(int j = 0;j < *numUsuarios;j++){
        printf("%d. Nome: %s - Idade: %d - RA: %s\n",j+1,usuarios[j].nome,usuarios[j].idade,usuarios[j].RA);
    }

    printf("Digite o RA do usuario a ser atualizado : ");
    scanf( " %[^\n]s", &cod_u);
    getchar();

    for(int i = 0;i < *numUsuarios;i++){
        if(strcmp(usuarios[i].RA,cod_u)==0){
            printf("\n**Usuario encontrado**\n");
            printf("\nDigite novo nome de usuario:");
            scanf(" %[^\n]s", &usuarios[i].nome);

            printf("Digite nova idade: ");
            scanf("%d", &usuarios[i].idade);

            printf("\n** Usuario atualizado com sucesso**\n\n *Enter para voltar*");
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
void atualizarLivro(struct Livro livros[],int *numLivros){
    char cod_l[10];
    
    printf("\n###Livros cadastrados###\n");
    for(int j = 0;j < *numLivros;j++){
        printf("%d. Livro: %s - (Autor): %s - codigo: *%s* (%s)\n",j+1,livros[j].nome,livros[j].autor,livros[j].cod_li,livros[j].disponivel ?"Disponivel":"Reservado");
    }

    printf("\nDigite o codigo do livro a ser atualizado: ");
    scanf(" %[^\n]s", &cod_l);
    getchar();

    for(int i = 0;i < *numLivros;i++){
        if(strcmp(livros[i].cod_li,cod_l)==0){
        printf("\n**livro encontrado**\n\n");
        printf("Digite novo nome do livro: ");
        scanf(" %[^\n]s", &livros[i].nome);
        printf("\nDigite novo nome de autor: ");
        scanf(" %[^\n]", &livros[i].autor);
       
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
void emprestarLivro(struct Usuario usuarios[],int *numUsuarios,struct Livro livros[],int *numLivros,struct Emprestimo emprestimos[],int *numEmprestimos){
    char cod_li[10],RA[8];
    int livroInd = -1,usuarioInd = -1;// variavel indice criada para comparar se existe ou não usuario e livro.
    printf("\n###Livros cadastrados###\n");
    for(int j = 0;j < *numLivros;j++){
        printf("%d. Livro: %s - (Autor): %s - codigo: *%s* (%s)\n",j+1,livros[j].nome,livros[j].autor,livros[j].cod_li,livros[j].disponivel ?"Disponivel":"Reservado");
    }

    printf("\nDigite o codigo do livro que deseja emprestar: ");
    scanf(" %[^\n]s", &cod_li);

    for(int i = 0;i < *numLivros;i++){
        if(strcmp(livros[i].cod_li,cod_li)== 0){
            livroInd = i;
            break;//comando para procurar o livro,e o strcmp para verificar se o cod do livro bate com o cod digitado.
        }
    }
    if(livroInd == -1){
        printf("\nLivro nao encontrado.\n");
        getchar();
        return;
    }
    if(livros[livroInd].disponivel == 0){
        printf("\nLivro ja foi emprestado.\n");
        getchar();
        return;
    }
    printf("\n###Usuarios cadastrados###\n");
    for(int j = 0;j < *numUsuarios;j++){
        printf("%d. Nome: %s - Idade: %d - RA: %s\n",j+1,usuarios[j].nome,usuarios[j].idade,usuarios[j].RA);
    }
    printf("\nDigite o RA do usuario a quem o livro vai ser emprestado: ");
    scanf(" %[^\n]s", &RA);

    for(int i = 0;i < *numUsuarios;i++){
        if(strcmp(usuarios[i].RA,RA)== 0){
            usuarioInd = i; 
            break;
        }
    }
    if(usuarioInd == -1){
        printf("\nUsuario nao encontrado.\n");
        getchar();
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
    int RAduplicado;
    if(*numUsuarios >= max_usuarios){
        printf("***Limite de usuarios atingido***\n");
        return;
    }
    printf("###Cadastro de usuarios###\n");
    printf("Digite o nome: ");
    scanf(" %[^\n]s", &usuarios[*numUsuarios].nome);
     do{
         RAduplicado = 0;   
        printf("Digite o RA: ");  
        scanf(" %[^\n]s", &usuarios[*numUsuarios].RA);
        for(int i = 0;i< *numUsuarios;i++){
             if(strcmp(usuarios[i].RA,usuarios[*numUsuarios].RA)==0){
                printf("\n Senha RA ja cadastrado, digite outro. \n");
                RAduplicado = 1;
                break;
             }
        }    
    }while(RAduplicado);  
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
   int codigoduplicado;
    if(*numBibliotecarios >= max_bibliotecarios){
        printf("***Limite de bibliotecarios atingido\n***");
        return;
    }
    printf("\n###Cadastro de bibliotecarios###\n");
    printf("digite o nome: ");
    scanf(" %[^\n]s", &bibliotecarios[*numBibliotecarios].nome);
    printf("digite a senha: ");
    scanf(" %[^\n]s", &bibliotecarios[*numBibliotecarios].senha);
    do{
        codigoduplicado = 0;//variavel criada para verificar se o codigo ja existe ou nao.
    printf("Digite o codigo de resgistro do Bibliotecario: ");
    scanf(" %[^\n]s", &bibliotecarios[*numBibliotecarios].cod_b);

    for(int i = 0;i < *numBibliotecarios;i++){//for procura o bibliotecario e comprara se ele tem o msm codigo, com strcmp que compara strings.
        if(strcmp(bibliotecarios[i].cod_b,bibliotecarios[*numBibliotecarios].cod_b)== 0){
            printf("\n**Codigo ja cadastrado, digite um codigo valido**\n ");
            codigoduplicado = 1;
            break;
        }
    }
    }while(codigoduplicado);
    
    (*numBibliotecarios)++;
    printf("\n**bibliotecario %s cadastrado com sucesso**\n",bibliotecarios[*numBibliotecarios - 1].nome);//- 1 para ter acesso ao ultimo registro.
    getchar();
    getchar();
    system("cls");
}//Estrutura para cadastro de Bibliotecário.
//..................................................................................................................................................................

void cadastrarLivro(struct Livro livros[],int *numLivros){
    int livroDuplicado;
    if(*numLivros >= max_livros){
        printf("\n***Limite de livros atingido***\n");
        return;
    }

    printf("###Cadastro de livros###\n");
    printf("Nome do livro: ");
    scanf(" %[^\n]s", &livros[*numLivros].nome);
    printf("Autor: ");
    scanf(" %[^\n]s", &livros[*numLivros].autor);
    do{
        livroDuplicado = 0;
        printf("codigo: "); 
        scanf(" %[^\n]s", &livros[*numLivros].cod_li);
        for(int i =0;i < *numLivros;i++){
            if(strcmp(livros[i].cod_li,livros[*numLivros].cod_li)==0){
                printf("\nCodigo ja cadastrado, digite outro.\n");
                livroDuplicado = 1;
                break;
            }
        }
    }while(livroDuplicado);
    livros[*numLivros].disponivel = 1;
    (*numLivros)++;
    printf("\n**Livro: %s - Autor: %s cadrastado com sucesso**\n",livros[*numLivros -1].nome,livros[*numLivros -1].autor);
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
            printf("**Login realizado com sucesso**\n");
            return 1;// retorna 1 se o login estiver correto
        }

    }
    printf("**Nome ou Senha invalida,**.\n  Enter para voltar");
    getchar();//para pausar o progama para n ir para procima tela direto
    getchar();
    system("cls");
    return 0;// retorna 0 se o login estiver errado
}//Estrutura para validar login.
int validarLoginAdm(struct Admin admins[], int numAdmins){
    char nome_adm[30];
    char senha_adm[20];
    int i;
    printf(" \n**Administrador seja Bem vindo** \n");
    printf("\n Digite nome de Admin: ");
    scanf(" %[^\n]s", &nome_adm);
    printf("\n Digite a senha: ");
    scanf(" %[^\n]s", &senha_adm);

    for(i=0;i < numAdmins;i++){
        if(strcmp(admins[i].nome,nome_adm)== 0 && strcmp(admins[i].senha,senha_adm)==0 ){
            printf("\n **Login realizado com sucesso** \n");
            return 1;
        }
    }
    printf(" **Admin ou senha invalda** \n Enter para voltar");
    getchar();
    getchar();
    system("cls");
    return 0;
    

}

void 
iniciarAdmins(struct Admin admins[],int *numAdmins){

    strcpy(admins[0].nome, "admin");
    strcpy(admins[0].senha, "senhaAdm");
    *numAdmins = 1;


}
//----------------------------------------------------------------------------------------------------------------
void exibirLivros(struct Livro livros[],int numLivros){

    if(numLivros == 0){
        printf("Nenhum livro cadastrado\n");
        getchar();
        return;
    }

    printf("\n###Livros cadastrados###\n");
    // int i = 0: significa que o contador i em 0, indica que o primeiro livro está na posição 0 do array.
    for(int i = 0;i < numLivros;i++){
        printf("%d. Livro: %s - (Autor): %s - codigo: *%s* (%s)\n",i+1,livros[i].nome,livros[i].autor,livros[i].cod_li,livros[i].disponivel ?"Disponivel":"Reservado");
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
        getchar();
        return;
    }
    
    printf("\n###Usuarios cadastrados###\n");
    for(int i = 0;i < numUsuarios;i++){
        printf("%d. Nome: %s - Idade: %d - RA: %s\n",i+1,usuarios[i].nome,usuarios[i].idade,usuarios[i].RA);
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
        getchar();
        return;
    }
   
    printf("\n###Bibliotecarios cadastrados###\n");
    for(int i=0;i <numBibliotecarios;i++){
        printf("%d. Bibliotecario: %s - Codigo: %s\n",i+1,bibliotecarios[i].nome,bibliotecarios[i].cod_b);
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
void relatorios(struct Livro livros[],int *numLivros,struct Usuario usuarios[],int *numUsuarios,struct Bibliotecario bibliotecarios[],int *numBibliotecarios){
    int menu_r;
    do{
    printf("\n Escolha qual lista de relatorio deseja acessar. \n");
    printf(" [1] Lista de Bibliotecarios. \n");
    printf(" [2] Lista de Usuarios. \n");
    printf(" [3] Lista de Livros. \n");
    printf(" [0] Para voltar. \n");
    scanf("%d", &menu_r);
    system("cls");

    switch(menu_r){
        case 1:
            exibirBibliotecarios(bibliotecarios,*numBibliotecarios);
            break;
        case 2:
            exibirUsuarios(usuarios,*numUsuarios);
            break;
        case 3:
            exibirLivros(livros,*numLivros);
            break;
        case 0:
        printf(" Voltando ao menu anterior. ");
            break;
        default:
        printf("\n Opcao invalida!! \n");
    }
  }while(menu_r != 0); 
}
//..................................................................................................................................................................
void exibirMenu(struct Livro livros[],int *numLivros,struct Usuario usuarios[],int *numUsuarios,struct Bibliotecario bibliotecarios[],int *numBibliotecarios,struct Emprestimo emprestimos[],int *numEmprestimos){
    int sub_menu,menu_u,menu_l;
    do {
        printf("\n***Escolha uma opcao***\n");
        printf(" [1] Usuarios. \n");
        printf(" [2] Livros. \n");
        printf(" [3] Emprestar Livro. \n");
        printf(" [4] Devolucao de Livro.\n");
        printf(" [5] Relatorios. \n");
        printf(" [6] **(Leia)Manual de navegacao ** \n");
        printf(" [0] voltar\n");
        scanf("%d", &sub_menu);
        system("cls");
//Looping de DO-While para sub menu.
        switch (sub_menu) {
            case 1:
                do {
                    printf("\n [1] Cadastrar Usuarios. \n");
                    printf(" [2] Excluir Usuarios. \n");
                    printf(" [3] Atualizar cadastros de Usuarios. \n");
                    printf(" [0] voltar\n");
                    scanf("%d", &menu_u);
                    system("cls");

                    switch (menu_u) {
                        case 1:
                            cadastrarUsuario(usuarios,numUsuarios);
                            break;
                        case 2:                          
                            excluirUsuarios(usuarios,numUsuarios);
                            break;
                        case 3:
                            atualizarUsuario(usuarios,numUsuarios);
                            break;
                        case 0:
                            printf("\n Voltando ao menu anterior. ");
                            break;
                        default:
                            printf("Opcao invalida!\n");
                            break;
                    }
                } while (menu_u != 0);
                break;              
            case 2:
                do {
                    printf("\n [1] Cadastrar Livros. \n");
                    printf(" [2] Excluir Livros. \n");
                    printf(" [3] Atualizar cadastros de Livros. \n");
                    printf(" [0] voltar\n");
                    scanf("%d", &menu_l);
                    system("cls");

                    switch (menu_l) {
                        case 1:
                            cadastrarLivro(livros,numLivros);
                            break;
                        case 2:                          
                            excluirLivros(livros,numLivros);
                            break;
                        case 3:
                            atualizarLivro(livros,numLivros);
                            break;
                        case 0:
                            printf("\n Voltando ao menu anterior. ");
                            break;
                        default:
                            printf("Opcao invalida!\n");
                            break;
                    }
                } while (menu_l != 0);
               
                break;
            case 3:
                emprestarLivro(usuarios,numUsuarios,livros,numLivros, emprestimos,numEmprestimos);
                break;
            case 4:
                printf(" Devolucao de livro em processo");
            case 5:
                relatorios(livros,numLivros,usuarios,numUsuarios,bibliotecarios,numBibliotecarios);
                break;
            case 6:
                printf("Manual de navegação em processo");
            case 0:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }

    } while (sub_menu != 0);
}//Estrutura criada para chamar um sub-menu
void exibirMenuAdm(struct Livro livros[],int *numLivros,struct Usuario usuarios[],int *numUsuarios,struct Bibliotecario bibliotecarios[],int *numBibliotecarios,struct Admin admins[], int *numAdmins){
    int menu,menu_b;

    do{
        printf("\n *** Bem vindo Administrador *** \n");
        printf("\n [1] Bibliotecario. \n");
        printf(" [2] relatorios.\n");
        printf(" [0] Para voltar.\n");
        scanf("%d", &menu);
        system("cls");

        switch(menu){
            case 1:  
            do{ 
                printf("\n ### Menu de Bibliotecario ### \n");
                printf("\n [1] Cadastrar Bibliotecario. \n");
                printf(" [2] excluir Bibliotecario. \n");
                printf(" [3] Atualizar cadastro de Bibliotecario. \n");
                printf(" [0] Para voltar.\n ");
                scanf("%d", &menu_b);
                getchar();
                system("cls");

                switch(menu_b){
                    case 1:
                        cadastrarBibliotecario(bibliotecarios, numBibliotecarios);
                        break;
                    case 2:
                        excluirBibliotecarios(bibliotecarios, numBibliotecarios);
                        break;
                    case 3:
                        atualizarBibliotecario(bibliotecarios,numBibliotecarios);
                        break;
                    case 0:
                        printf("\n Voltando ao menu anterior \n");
                        break;
                        default:
                        printf("\n Opcao invalida!! \n");
                        break;
                }

            }while(menu_b != 0);            
               
                break;
            case 2:
                relatorios(livros,numLivros,usuarios,numUsuarios,bibliotecarios,numBibliotecarios);
                break;
            case 0:
                printf(" Voltando ao menu anterior. \n");
                break;
                default:
                printf("\n Opcao ivalida!! \n");

        }
    }while(menu != 0);
}
//..................................................................................................................................................................


int main(){

    struct Usuario usuarios[max_usuarios];
    struct Bibliotecario bibliotecarios[max_bibliotecarios];
    struct Livro livros[max_livros];
    struct Emprestimo emprestimos[max_emprestimos];
    struct Admin admins[max_admins];

//As structs acima estão sendo vinculada a quantidade maxima que podem ser cadastradas.
    int numUsuarios = 0, numBibliotecarios = 0, numLivros = 0, numEmprestimos = 0, numAdmins = 0 ;
    //variavies acima criada para identificar que o numero de usuarios,livros,bibliotecarios,emprestimos comecem com 0 para n pegar lixo de memória.
    int opcao1;
    memset(livros, 0, sizeof(livros));//limpesa de lixo de memória
    memset(bibliotecarios, 0, sizeof(bibliotecarios));

    iniciarAdmins(admins, &numAdmins);

    do{
        printf("\n#### Bem vindo a Biblioteca 'ds2p17' ###\n");
        printf(" [1] Entrar como Admin. \n");
        printf(" [2] Entrar como Bibliotecarios. \n");
        printf(" [0] sair. \n");
        scanf("%d", &opcao1);
        system("cls");
        switch(opcao1){
            case 1:
                if(validarLoginAdm(admins, numAdmins)){
                    exibirMenuAdm(livros,&numLivros,usuarios,&numUsuarios,bibliotecarios,&numBibliotecarios,admins,&numAdmins);
                }
                break;  
            case 2:
                if(validarLogin(bibliotecarios, numBibliotecarios)){
                    exibirMenu(livros,&numLivros,usuarios,&numUsuarios,bibliotecarios,&numBibliotecarios,emprestimos,&numEmprestimos);
                }

                break;
            case 0:
            printf("saindo...");
                system("cls");
                break;
            default:
            printf(" Opcao invalida!! \n");
        }

    }while(opcao1);
//Estrutura do menu principal.
//..................................................................................................................................................................

  return 0;
}
