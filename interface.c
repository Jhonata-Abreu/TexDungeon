#include<stdio.h>

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