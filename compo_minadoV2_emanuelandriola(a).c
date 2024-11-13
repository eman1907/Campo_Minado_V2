#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include "matriz.h" 

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

//lerá as coordenadas fornecidas pelo usuário e vai imprimir o campo com as devidas mudanças 
//ao final da função, será retornado 1 ou 0 
int ok = leitura_das_coordenadas(n, acum, cont, n3, n4, mat2); 

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

