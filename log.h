#include <stdio.h>
#include <stdlib.h>
#define MINA -1

FILE* criar_arquivo(); 
//cria arquivo.txt e retorna na main

void imprime_arquivo_log(FILE* arq, int** campo, int tam, int x, int y); 
//imprime cada jogada no arquivo semelhamte ao terminal

void imprimeCampo_arq(FILE* arq, int** campo, int tam);
//ao final do jogo, imprime o campo sem a presença de 'x'

void arq_fimDeJogo(FILE* arq, int det); 
//declara no arquivo se o usuário venceu ou perdeu

void arq_jogadaErrada(FILE* arq, int x, int y, int det);
//declara no arquivo jogadas repetidas ou inválidas
