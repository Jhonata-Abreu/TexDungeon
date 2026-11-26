#include<stdio.h>
#include"interface.h"

int main()
{
    int opt;
    char textRanking[50];

    mostrar_menu();
    // loop para menu de navegação
    do{
        if(scanf("%d", &opt) != 1){
            while(getchar() != '\n');
            printf("opcao invalida\n");
            continue;
        }
        // opção 3 do menu, mostra o ranking e o submenu
        if(opt == 3){
            mostrar_ranking(textRanking); // Chama a função mostrar_ranking com um parametro string
            mostrar_subMenu();
            if(scanf("%d", &opt) != 1){
                while(getchar() != '\n');
                printf("opcao invalida\n");
                }
            if(opt == 1){
                mostrar_menu();
                continue;
            }
            
        }
    }while(opt != 4);
    printf("Jogo encerrado.\n");

    return 0;
}