#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define TAM_VET 100

enum tipoEndereco {Alameda, Avenida, Praca, Rua, Travessa};
enum tipoContato {Celular, comercial, fixo, pessoal, fax};
enum tipoRedeSocial {Instagram, Facebook, Linkedin};

struct registro{ 
    char nome[ TAM_VET];
    enum tipoContato TpCon;
    char numero_tel [11];
    enum tipoEndereco TpEnd;                    
    char endereco [TAM_VET]; 
    int numero;
    enum tipoRedeSocial TpRS;
    char RedeSocial;
    char email [TAM_VET];
}agenda[200];


char *obterNomeEndereco ( enum tipoEndereco tpEnd )
{
    const char *nomeEndereco[] =
    {
        "", "Al.", "Av.", "Pr.", "Rod.", "R.", "Tr."
    };

    return ( nomeEndereco [ tpEnd ] );
}

int menuAgenda (){
    int opcao;
    printf ("MENU AGENDA\n");
    printf ("1 - Adicionar\n2 - Editar\n3 - Ver contato\n4 - Excluir\n5 - Ver agenda\n6 - Sair\n");
    printf ("Digite sua opção: ");
    scanf("%i", &opcao);
    //FUNÇÃO LIMPAR TELA
    return opcao;
}

int criarContato (int *total){
    
        printf("Nome: ");
        fflush(stdin);
        scanf("%[^\n]s", agenda[*total].nome);

        printf ("Tipo de Telefone: \n");
        printf ("1 - Celular\n2 - Comercial\n3 - Fixo\n4 - Pessoal\n5 - Fax\n");
        fflush (stdin);
        scanf ("%i", &agenda[*total].TpCon);

        printf("Número : ");
        fflush(stdin);
        scanf("%[^\n]s", agenda[*total].numero_tel);

        printf("Email: ");
        fflush(stdin);
        scanf("%[^\n]s", agenda[*total].email);
        //STRTOK
        printf ("Tipo de endereço: \n");
        printf ("1 - Alameda\n2 - Avenida\n3 - Praça\n4 - Rua\n5 - Travessa\n");
        printf ("Digite sua opção: ");
        fflush (stdin);
        scanf ("%i", &agenda[*total].TpEnd);

        printf("Endereço: ");
        fflush(stdin);
        scanf("%[^\n]s", agenda[*total].endereco);

        printf ("Tipo de rede social: \n");
        printf ("1 - Instagram\n2 - Facebook\n3 - Linkedln\n");
        fflush (stdin);
        scanf ("%i", &agenda[*total].TpRS);

        printf ("Digite seu Username: ");
        fflush(stdin);
        scanf("%[^\n]s", agenda[*total].RedeSocial);

        (*total)++;
}

void mostrarContatos (int *total){
    int i;
    for (i = 0; i < total; i++){
    
        printf ("%s\n", agenda[i].nome);
        printf ("%s\n", agenda[i].numero_tel);
        printf ("%s\n", agenda[i].email);
        printf ("%s %s\n",obterNomeEndereco(agenda[i].TpEnd), agenda[i].endereco);
    } 

}


char *obterNomeEndereco ( enum tipoEndereco tpEnd );
int menuAgenda ();
int criarContato (int *total);
void mostrarContatos (int *total);


int main (){
    setlocale (LC_ALL, "");

    int *total = 0, opcao;

    do{
    opcao = menuAgenda ();

    switch (opcao)
    {
    case 1:
        criarContato (&total);
        break;

    case 2:
        
        break;

    case 3:
        
        break;

    case 4:
        
        break;

    case 5:
        mostrarContatos (&total);
        break;

    case 6:
        
        break;
    
    default:
        printf ("Opção inválida!\n");
        printf ("----------------------------\n");
        break;
    }
    }while (opcao != 6);
}

