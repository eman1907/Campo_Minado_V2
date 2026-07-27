#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#define MINA -1

int** aloca_campo(int tamanho);
//aloca dinamicamente uma matriz de dimensão tamanho x tamanho

void preenche_minas(int** campo, int tam, int mina);
//coloca a quantidade de minas definidas aleatoriamente no campo

int calcula_coordenada(int** campo, int tamanho, int x, int y);
//calcula o valor de cada coordenada de acordo com a quantidade de minas próximas

void floodfill(int** campo, int tamanho, int x, int y, int* cont);
//preenche de forma recursiva o campo a partir da coordenada escolhida

void retira_x(int** campo, int tam);
//calcula o valor de cada coordenada 

void imprimeCampo(int** campo, int tam);
//imprime campo sem a presença do 'x' ao final do jogo

void liberaMatriz(int** campo, int tam);
//libera matriz alocada dinamicamente

void nivel_jogo(int nivel, int* tamanho, int* venceu, int* mina); 
//inicializa as variáveis de acordo com a didficulade escolhida pelo usuário
