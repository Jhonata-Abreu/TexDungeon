#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

//Declaração da masmorra
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

//Função para imprimir a masmorra 
void des_masmorra(char masmorra[10][21], COORD *pos)
{
    int i, j;
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


void mov(COORD *pos)
{
    int n_posx = pos->X;
    int n_posy = pos->Y; 

  
    
    
    
    if (GetAsyncKeyState('A') & 0x8000) n_posx--;
    if (GetAsyncKeyState('D') & 0x8000) n_posx++;
    if (GetAsyncKeyState('W') & 0x8000) n_posy--;
    if (GetAsyncKeyState('S') & 0x8000) n_posy++;

    if ( n_posx >= 0 && n_posx < 20 &&
    n_posy >= 0 && n_posy < 10 &&
    masmorra[n_posy][n_posx] != '#')
    {
        pos->X = n_posx;
        pos->Y = n_posy;
    }
}
int main()
{
    COORD pos;//COORD tipo especifico de variavel da wind para determinar a localização
    pos.X = 4;
    pos.Y = 0;
    while (1)
    {
        des_masmorra(masmorra, &pos);
        mov(&pos);
    }
    
    
    return 0;
}