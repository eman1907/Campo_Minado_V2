#include "matriz.h" 

int** aloca_campo(int tamanho){
    int** campo = malloc(tamanho * sizeof(int*));
    if (campo == NULL){
        printf("Memoria insuficiente\n");
        exit(1);
    }
    for (int i = 0; i < tamanho; i++){
        campo[i] = malloc(tamanho * sizeof(int));
        if (campo[i] == NULL){
            printf("Memoria insuficiente\n");
            exit(1); 
        }
    }
    return campo; 
}

void preenche_minas(int** campo, int tam, int mina){
    int x, y;
    srand(time(NULL));
    for (int i = 0; i < mina; i++){
        x = rand() % (tam - 1);
        y = rand() % (tam - 1);
        if (campo[x][y] == MINA || x == 0 || y == 0) mina++; 
        else campo[x][y] = MINA;
        //printf("x: %d, y: %d\n" , x, y); 
    }
}

void floodfill(int** campo, int tamanho, int x, int y, int* cont){
    if (x < 1 || x > tamanho - 2 || y < 1 || y > tamanho - 2 || campo[x][y] != 10) return; 
    campo[x][y] = calcula_coordenada(campo, tamanho, x, y);
    (*cont)++;
    if (campo[x][y] == 0){
        floodfill(campo, tamanho, x - 1, y - 1, cont);
        floodfill(campo, tamanho, x, y - 1, cont);
        floodfill(campo, tamanho, x + 1, y - 1, cont);
        floodfill(campo, tamanho, x - 1, y, cont);
        floodfill(campo, tamanho, x + 1, y, cont);
        floodfill(campo, tamanho, x - 1, y + 1, cont);
        floodfill(campo, tamanho, x, y + 1, cont);
        floodfill(campo, tamanho, x + 1, y + 1, cont);
    }
}

int calcula_coordenada(int** campo, int tamanho, int x, int y){
    int cont = 0;
    if (campo[x - 1][y - 1] == MINA) cont++;
    if (campo[x][y - 1] == MINA) cont++;
    if (campo[x + 1][y - 1] == MINA) cont++;
    if (campo[x - 1][y] == MINA) cont++;
    if (campo[x + 1][y] == MINA) cont++;
    if (campo[x - 1][y + 1] == MINA) cont++;
    if (campo[x][y + 1] == MINA) cont++;
    if (campo[x + 1][y + 1] == MINA) cont++;
    return cont; 
}

void retira_x(int** campo, int tam){
     for (int i = 1; i < tam - 1; i++){
        for (int j = 1; j < tam - 1; j++){
            if (campo[i][j] != MINA) campo[i][j] = calcula_coordenada(campo, tam, i, j);
        }
    }
}

void imprimeCampo(int** campo, int tam){
    for (int i = 1; i < tam - 1; i++){
        for (int j = 1; j < tam - 1; j++){
            if (campo[i][j] == MINA) printf(" %d" , MINA);
            else printf("  %d" , campo[i][j]);
        }
        printf("\n"); 
    }
}

void liberaMatriz(int** campo, int tam){
    for (int i = 0; i < tam; i++){
        free(campo[i]);
    }
    free(campo); 
}

void nivel_jogo(int nivel, int* tamanho, int* venceu, int* mina){
    if (nivel == 1) {
        *tamanho = 12;
        *venceu = 85; 
        *mina = 15;
    } else if (nivel == 2){
        *tamanho = 22;
        *venceu = 370;
        *mina = 30;
    } else if (nivel == 3) {
        *tamanho = 32;
        *venceu = 840;
        *mina = 60;
    } else {
        printf("Numeracao invalida!\n");
    }
}
