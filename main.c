#include<stdio.h>
#include<stdlib.h>
#include"interface.h"
#include"entidades.h"
#include"jogo.h"

/*
    Comando para compilar no terminal(copiar e colar no terminal): gcc main.c interface.c entidades.c -o app
    Comando para executar(copiar e colar no terminal): ./app
*/


int main()
{
    int opt;
    char textRanking[50];

    // COORD pos;//COORD tipo especifico de variavel da wind para determinar a localização
    // pos.X = 4;
    // pos.Y = 0;

    mostrar_menu();
    // loop para menu de navegação
    do{
        if(scanf("%d", &opt) != 1){
            while(getchar() != '\n');
            printf("opcao invalida\n");
            continue;
        }

        if(opt == 1){
            // Lógica para iniciar nova partida
            ocultar_cur();
            system("cls");
            while (1)
            {
                des_masmorra(masmorra, &pos);
                mov(&pos);
                Sleep(100);
            }
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