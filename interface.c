#include<stdio.h>
#include <windows.h>
#include"jogo.h"

COORD pos = {4, 0}; // Inicializa a posição do personagem no início da masmorra;
char campo_visao[10][21];

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

bool linhaVisao(int alvoX, int alvoY){
    int x = pos.X;
    int y = pos.Y;
    
    int dx = abs(alvoX - x);
    int dy = abs(alvoY - y);
    int sx = (alvoX > x) ? 1 : -1;
    int sy = (alvoY > y) ? 1 : -1;
    int err = dx - dy;

    while(true){
        if(masmorra[y][x] == '#'){
            return false; // linha de visão obstruída por uma parede
        }
        if(x == alvoX && y == alvoY){
            break; // chegou ao alvo
        }
        // Calcula o erro e ajusta a posição
        int e2 = err * 2;
        // Ajusta a posição x se necessário
        if(e2 > -dy){
            err -= dy;
            x += sx;
        }
        // Ajusta a posição y se necessário
        if(e2 < dx){
            err += dx;
            y += sy;
        }

    }
    return true; // linha de visão desobstruída
}

void atualizarVisao(){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 21; j++){
            // Lógica para atualizar o campo de visão
            int dx = j - pos.X;
            int dy = i - pos.Y;

            bool raioVisao = (dx * dx + dy * dy) <= 16; // raio de visão de 4 unidades
            if(raioVisao && linhaVisao(j, i)) 
            {
                campo_visao[i][j] = 1; // visível
            } else {
                campo_visao[i][j] = 0; // não visível
            }
        }
    }
}



void des_masmorra(char masmorra[10][21], COORD *pos)
{
    int i, j;
    HANDLE hsaid = GetStdHandle(STD_OUTPUT_HANDLE);//variável especial que lida com o output do sistema
    COORD coord = {0, 0};
    SetConsoleCursorPosition(hsaid,coord);//Coloca a saida do console no canto superior esquerdo do console

    atualizarVisao(); // Atualiza o campo de visão antes de desenhar a masmorra

    for(i = 0; i < 10; i++ )
    {
        for(j = 0; j < 20; j++)
        {
            if(campo_visao[i][j] == 0){
                if(masmorra[i][j] == '#'){
                    printf("#");
                } else {
                    printf(" ");
                }
            }
            else if (i == pos->Y && j == pos->X)
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
    printf("\nUse as teclas W, A, S e D para se movimentar. Pressione ESC para sair.\n");
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