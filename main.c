#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct usuario{
    char RA[50],nome[50];
    int idade;
};
typedef struct admin{
    char senha[50],nome[50];
    int idade;
};
typedef struct livro{
    char codigo[50],nome[50],nomeA[50];
    
};


 int main(){
   struct usuario usuarios;
   struct admin admins;
   struct livro livros;

   int deci1, deci2, deci3;

   printf(".....Bem Vindo.....\n");
   printf("Para Biblioteca [1]\n");
   printf("Para sair [0]\n");
   scanf("%d", &deci1);
    system("cls");
   if(deci1 == 1){
    printf("\n***Voce esta no meunu principal***\n");
    printf("Para cadastrar admins[1]\n");
    printf("Para cadastrar usuarios[2]\n");
    printf("Para cadastrar livros[3]\n");
    printf("Para login[4]\n");
    printf("Para voltar[0]\n");
    scanf("%d", &deci2);
        while(deci2 != 1 && deci2 != 2 && deci2 != 3 && deci2 != 4 && deci2 != 0 ){
         printf("opcao invalida, digite uma opcao correta: ");
         scanf("%d", &deci2);
        }
    }
    else{
        printf("....Saindo....");
        exit(0);
    }
    switch(deci2){
        case 1:
            system("cls");
            printf("***Cadastro de Admin***\n");
            printf("digite o nome: ");
            scanf(" %[^\n]s", &admins.nome);
            printf("digite uma senha: ");
            scanf(" %[^\n]s", &admins.senha);
            printf("***cadastro realizado com sucesso***\n");
            break;
        case 2:
            system("cls");
            printf("***Cadastro de usuario***\n");
            printf("Digite o nome:");
            scanf(" %[^\n]s", &usuarios.nome);
            printf("Digite o RA : ");
            scanf(" %[^\n]s", &usuarios.RA);
            printf("***usuario cadastrado com sucesso***\n");
            break;
        case 3:
            system("cls");
            printf("***Cadastro de livro***\n");
            printf("Nome do livro: ");
            scanf(" %[^\n]s", &livros.nome);
            printf("Nome do autor: ");
            scanf(" %[^\n]s", &livros.nomeA);
            printf("Codigo do livro: ");
            scanf(" %[^\n]s", &livros.codigo);
            printf("***Livro cadastrado com sucesso***\n");
            break;
        case 4:
            system("cls");
            printf("***Digite nome e senha***\n");
            printf("digite nome : ");
            printf("digite a senha : ");




        




    }

return 0;
}