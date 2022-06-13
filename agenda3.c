#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define TAM_NOME 100

enum tipoEndereco {Alameda, Avenida, Praca, Rua, Travessa};

char *obterNomeEndereco ( enum tipoEndereco tpEnd )
{
    const char *nomeEndereco[] =
    {
        "", "Al.", "Av.", "Pr.", "Rod.", "R.", "Tr."
    };

    return ( nomeEndereco [ tpEnd ] );
}

struct registro{ 
    char nome[ TAM_NOME];
    char numero_tel [11];
    char endereco [100]; 
    enum tipoEndereco TpEnd;
    int numero;
    char email [50];
}agenda[200];

int menuAgenda (){
    int opcao;
    printf ("Digite a opção que você deseja: \n");
    printf ("1 - Adicionar\n2 - Editar\n3 - Ver contato\n4 - Excluir\n5 - Ver agenda\n6 - Sair\n");
    scanf("%i", &opcao);
    return opcao;
}

int criarContato (int *total){
    
        printf("Nome: ");
        fflush(stdin);
        scanf("%[^\n]s", agenda[*total].nome);
    
        printf("Número: ");
        fflush(stdin);
        scanf("%[^\n]s", agenda[*total].numero_tel);

        printf("Email: ");
        fflush(stdin);
        scanf("%[^\n]s", agenda[*total].email);

        printf("Endereço: ");
        fflush(stdin);
        scanf("%[^\n]s", agenda[*total].endereco);

        printf ("Tipo de endereço: \n");
        printf ("1 - Alameda\n2 - Avenida\n3 - Praça\n4 - Rua\n5 - Travessa\n");
        fflush (stdin);
        scanf ("%i", &agenda[*total].TpEnd);

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
        break;
    }
    }while (opcao != 6);
}
