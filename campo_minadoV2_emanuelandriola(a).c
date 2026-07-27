#include "matriz.h" 
#include "log.h" 

int main(){

    printf("Deseja jogar em qual nivel?\n");
    printf("1 - Facil (10x10)\n2 - Medio (20x20)\n3 - Dificil (30x30)\n");
    printf("Digite o numero correspondente: ");
    int nivel, tamanho, mina, venceu;
    scanf("%d" , &nivel);
    nivel_jogo(nivel, &tamanho, &venceu, &mina);
    //tamanho representa as dimensões da matriz que representa o campo
    //venceu representa a quantidade de 'casas' sem minas
    //mina representa a quantidade de minas  

    int** campo = aloca_campo(tamanho);
    for (int i = 0; i < tamanho; i++){
        for (int j = 0; j < tamanho; j++){
            campo[i][j] = 10; 
        }
    }

    preenche_minas(campo, tamanho, mina);

    for (int i = 0; i < tamanho; i++){
        for (int j = 0; j < tamanho; j++){
            printf("  x");
        }
        printf("\n");
    }
    //imprime o campo com 'x' para o usuário ter noção das dimensões

    FILE* arq = criar_arquivo(); 

    int x, y, cont_vitoria;
    cont_vitoria = 0;
    //x e y representam as tentativas do usuário, linha e coluna no campo, respectivamente
    //cont_vitoria vai contar a quantidade de jogadas ate 'venceu' para indicar a vitoria no jogo

    while(1){
        printf("Digite as coordenadas (no estilo x, y): ");
        scanf("%d, %d" , &x, &y);

        if (x < 1 || x > tamanho - 2 || y < 1 || y > tamanho - 2){
            printf("Coordenadas invalidas!\n\n");
            arq_jogadaErrada(arq, x, y, 1);

        } else if (campo[x][y] == MINA){
            printf("Game Over, vc perdeu!\n");
            arq_fimDeJogo(arq, 1);
            break; 

        } else if (campo[x][y] != 10){
            printf("Coordenadas repetidas!\n\n");
            arq_jogadaErrada(arq, x, y, 0);

        } else {
            floodfill(campo, tamanho, x, y, &cont_vitoria);

            imprime_arquivo_log(arq, campo, tamanho, x, y); 

            for (int i = 1; i < tamanho - 1; i++){
                for (int j = 1; j < tamanho - 1; j++){
                    if (campo[i][j] != 10 && campo[i][j] != MINA) printf("  %d" , campo[i][j]);
                    else printf("  x");
                }
                printf("\n");
            }

            if (cont_vitoria == venceu){
                printf("Parabens, voce venceu!\n");
                arq_fimDeJogo(arq, 0);
                break;
            }
        }
    }
    
    retira_x(campo, tamanho);
    imprimeCampo(campo, tamanho);

    imprimeCampo_arq(arq, campo, tamanho);
    fclose(arq); 

    liberaMatriz(campo, tamanho);
    return 0; 
}
