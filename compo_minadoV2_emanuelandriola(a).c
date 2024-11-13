#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include "matriz.h" 
#include "log.h"

int main(){ 
int dif, n, n2, n3, n4; 

printf("Bem-Vindo ao Campo Minado!\n"); 
printf("Digite o número da dificuldade que deseja jogar:\n"); 
printf("1 - Fácil\n2 - Médio\n3 - Difícil\n"); 

scanf("%d" , &dif); 
variaveis_dificuldade(dif, &n, &n2, &n3, &n4);
//lê a dificuldade do jogo conforme especificado no enunciado variaveis_dificuldade(dif, &n, &n2, &n3, &n4);

if(dif == 1 || dif == 2 || dif == 3){ //só permite a entrada em caso de numeros validos 

int* *mat = inicializa_matriz(n); 

int* *mat2 = inicializa_randomico(mat, n2, n); 

int acum = 0; //contará quantas bombas tem próximo a cada coordenada, exceto -1 
int cont = 0; //irá de 0 a n3 para indicar se o usuario ganhou o jogo 

printf("Coloque as coordenadas desejadas no estilo x,y "); 
printf("e repita o processo ao final de cada rodada.\n"); printf("obs: não se esqueça da vírgula.\n"); 

//imprime a matriz inicial para o usuário ter noção das dimensões 
for (int i = 0; i < n; i++){ 
	for (int j = 0; j < n; j++){
	 printf("  x");
	}
  printf("\n");
}

Log* log = abrir_log(); 

int x, y, ok; 
while (scanf("%d,%d" , &x, &y)){ 

	  if ((x < 1 || y < 1) || (x > n || y > n)){ 
	 printf("Coordenadas indisponíveis, tente outros números.\n"); 
	   }

	  else if (mat2[x - 1][y - 1] != - 10 && mat2[x - 1][y - 1] != -1){  
	 printf("Coordenadas repetidas, tente outros números.\n"); 
	   } 

	  else {
	    x -= 1; //para o usuario digitar numeros entre 1 e 10, 20 ou 30 
	    y -= 1; 

	    if (mat[x][y] == -10) floodfill(mat2, x, y, n4, &cont); 
		
	   registrar_jogada(log, mat2, n, x, y); 

	  for (int i = 0; i < n; i++){ 
		for (int j = 0; j < n; j++){ 
			if (mat2[i][j] == -10) printf("  x"); //se a matriz nao foi inicializa com -1 ou acum 
			else if (mat2[i][j] == -1 && (x != i || y != j)){ 
	          printf("  x"); //todo m[i][j] = -1 ja foi inicilizado, logo ele só aparece caso o usuario digite suas coordenadas
	 	} 
	 		else if (mat2[i][j] == -1 && (x == i && y == j)){ 
	 		  printf(" %d" , mat2[i][j]);  //imprime -1, somente caso x == i e y == j 
		} 
	        else printf("  %d" , mat2[i][j]); //imprime os acumuladores já inicializados
	 	}
	  printf("\n"); 
	 } 

	 //critério de parada que finaliza o jogo em caso tanto de vitória quanto de derrota 
	 if (mat2[x][y] == -1 || cont == n3){ 
	 	break;
			 }
	  	}
	}

if (cont == n3) ok = 1; 
	else ok = 0;

campo_final(log, mat2, n, ok);
fechar_log(log);


//imprime a mensagem em caso de vitória 
if (ok){ 
printf("parabéns, vc eh fera!\n"); 
} 
//imprime a mensagem em caso de derrota 
else { 
	printf("game over\n"); 
} 

int* *mat3 = resultado_final(mat2, acum, n, n4); 

for (int i = 0; i < n; i++){ 
	for (int j = 0; j < n; j++){ 
		if (mat3[i][j] == -1) printf(" %d" , mat3[i][j]); 
		else printf("  %d" , mat3[i][j]); 
	} 
	printf("\n"); 
} 

liberar_matriz(mat3, n); 
} 

return 0; 

}

