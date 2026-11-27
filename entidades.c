#include <windows.h>

// definição da masmorra como uma matriz global
char masmorra[10][21] =
{
    "####..........######",
    "######.........#####",
    "##........##########", 
    "###......###########", 
    "#####...........####", 
    "#######........#####", 
    "........###.........", 
    "########............", 
    "####################", 
    "####################"
};

// Função para movimentar o personagem na masmorra
void mov(COORD *pos)
{
    int n_posx = pos->X;
    int n_posy = pos->Y; 

    // Verifica se as teclas A, D, W ou S foram pressionadas e atualiza a posição do personagem
    if (GetAsyncKeyState('A') & 0x8000) n_posx--;
    if (GetAsyncKeyState('D') & 0x8000) n_posx++;
    if (GetAsyncKeyState('W') & 0x8000) n_posy--;
    if (GetAsyncKeyState('S') & 0x8000) n_posy++;
    // Verifica se a nova posição está dentro dos limites da masmorra e não é uma parede
    if ( n_posx >= 0 && n_posx < 20 &&
    n_posy >= 0 && n_posy < 10 &&
    masmorra[n_posy][n_posx] != '#')
    {
        pos->X = n_posx;
        pos->Y = n_posy;
    }
}