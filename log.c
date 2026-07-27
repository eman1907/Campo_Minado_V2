#include "log.h"

FILE* criar_arquivo(){
    FILE* arq = fopen("log.txt" , "w");
    if (arq == NULL){
        printf("Memoria insuficiente\n");
        exit(1);
    }
    return arq; 
}

void imprime_arquivo_log(FILE* arq, int** campo, int tam, int x, int y){
    fprintf(arq, "Coordenadas: %d, %d\n" , x, y);
    for (int i = 1; i < tam - 1; i++){
        for (int j = 1; j < tam - 1; j++){
            if (campo[i][j] != 10 && campo[i][j] != MINA) fprintf(arq, "  %d" , campo[i][j]);
            else fprintf(arq, "  x");
            }
        fprintf(arq, "\n");
    }
    fprintf(arq, "\n"); 
}

void imprimeCampo_arq(FILE* arq, int** campo, int tam){
    for (int i = 1; i < tam - 1; i++){
        for (int j = 1; j < tam - 1; j++){
            if (campo[i][j] == MINA) fprintf(arq, " %d" , MINA);
            else fprintf(arq, "  %d" , campo[i][j]);
        }
        fprintf(arq, "\n"); 
    }
}

void arq_fimDeJogo(FILE* arq, int det){
    if (det){
        fprintf(arq, "Game Over, vc perdeu!\n");
    } else {
        fprintf(arq, "Parabens, voce venceu!\n");
    }
}

void arq_jogadaErrada(FILE* arq, int x, int y, int det){
    if (det){
        fprintf(arq, "Coordenadas %d, %d invalidas!\n\n" , x, y);
    } else {
        fprintf(arq, "Coordenadas %d, %d repetidas!\n\n" , x, y);
    }
}
