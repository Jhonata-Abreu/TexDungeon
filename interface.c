#include<stdio.h>
#include <windows.h>

void mostrar_menu(void){
    printf("1-Iniciar nova partida\n");
    printf("2-Carregar jogo salvo\n");
    printf("3-Mostrar ranking\n");
    printf("4-Sair do jogo\n");
}

void mostrar_subMenu(void){
    printf("\n========================\n");
    printf("1-Voltar ao menu\n");
    printf("========================\n");
}

void mostrar_ranking(const char *txtRanking){
    FILE *arqRanking = fopen(txtRanking, "r");
    // valida se o arquivo foi aberto corretamente
    if(arqRanking == NULL){
        printf("Erro ao abrir o arquivo ou arquivo inexistente\n");
        return;
    }
    // lê e exibe o conteúdo do arquivo de ranking
    char linha[20]; // buffer para armazenar cada linha do arquivo
    printf("\n========Ranking========\n");
    while(fgets(linha, sizeof(linha), arqRanking) != NULL){
        printf("%s", linha);
    }

    fclose(arqRanking);
}


// Função para imprimir a masmorra
void des_masmorra(char masmorra[10][21], COORD *pos)
{
    int i, j;
    HANDLE hsaid = GetStdHandle(STD_OUTPUT_HANDLE);//variável especial que lida com o output do sistema
    COORD coord = {0, 0};
    SetConsoleCursorPosition(hsaid,coord);//Coloca a saida do console no canto superior esquerdo do console

    for(i = 0; i < 10; i++ )
    {
        for(j = 0; j < 20; j++)
        {
            if (i == pos->Y && j == pos ->X)
            {
                printf("@");
            }
            else
            {
                printf("%c", masmorra[i][j]);
            }
            
        }
        printf("\n");
    }
   
}

// Função para ocultar o cursor do console
void ocultar_cur()
{
    HANDLE hsaida = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorinfo;
    GetConsoleCursorInfo(hsaida, &cursorinfo);
    cursorinfo.bVisible = FALSE;
    SetConsoleCursorInfo(hsaida, &cursorinfo);
}