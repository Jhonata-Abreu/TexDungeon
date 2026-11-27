#ifndef INTERFACE_H
#define INTERFACE_H
#include <windows.h>

// Funções de interface do menu e ranking
void mostrar_menu(void);
void mostrar_subMenu(void);
void mostrar_ranking(const char *txtRanking);

// Funções desenho da masmorra e ocultar cursor
void des_masmorra(char masmorra[10][21], COORD *pos);
void ocultar_cur();


#endif
