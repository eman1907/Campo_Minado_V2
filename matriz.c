#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include "matriz.h" 
#include "log.h" 


int iniciliza_coordenadas(int** mat, int x, int y, int n4){ 
 int acum = 0; 
  if (x < n4 && mat[x + 1][y] == -1) acum++; 
  if (x > 0 && mat[x - 1][y] == -1) acum++; 
  if (y < n4 && mat[x][y + 1] == -1) acum++; 
  if (y > 0 && mat[x][y - 1] == -1) acum++; 
  if (x > 0 && y > 0 && mat[x - 1][y - 1] == -1) acum++; 
  if (x > 0 && y < n4 && mat[x - 1][y + 1] == -1) acum++; 
  if (x < n4 && y > 0 && mat[x + 1][y - 1] == -1) acum++; 
  if (x < n4 && y < n4 && mat[x + 1][y + 1] == -1) acum++; 
  return acum; 
} 



void floodfill(int** mat, int x, int y, int n4, int *cont){ 

  //verifica as "bordas" do campo e se ele ainda nao foi inicializado 
  // funcionando como critério de parada 
  if(x >= 0 && y >= 0 && y <= n4 && x <= n4 && mat[x][y] == -10){ 


  //inicializa cada coordenada conforme a quantidade de minas próximas 
  mat[x][y] = iniciliza_coordenadas(mat, x, y, n4); 


  (*cont)++; //adiciona um ao contador para cada coordenada inicilalizada 


  //caso a coordenada não possua minas vizinhas ela 
  //"expandirá" suas coordenadas próximas usando recursão 
  if (mat[x][y] == 0) { 
 	floodfill(mat, x - 1, y - 1, n4, cont); 
 	floodfill(mat, x - 1, y, n4, cont); 
 	floodfill(mat, x, y - 1, n4, cont); 
 	floodfill(mat, x + 1, y, n4, cont);
 	floodfill(mat, x, y + 1, n4, cont); 
 	floodfill(mat, x + 1, y + 1, n4, cont); 
 	floodfill(mat, x + 1, y - 1, n4, cont); 
 	floodfill(mat, x - 1, y + 1, n4, cont); 
 		} 
 	} 
} 



void liberar_matriz(int** mat, int lin){ 
 	for (int i = 0; i < lin; i++){ 
 	  free(mat[i]); 
 	} 
   free(mat); 
} 



int** resultado_final(int** mat, int acum, int n, int n4){ 
	for (int x = 0; x < n; x++){ 
		for (int y = 0; y < n; y++){ 
	if (mat[x][y] != - 1) mat[x][y] = iniciliza_coordenadas(mat, x, y, n4); 
		} 
	  } 
	return mat;
} 



int leitura_das_coordenadas(int n, int acum, int cont, int n3, int n4, int** mat){ 

	Log* log = abrir_log(); 

	 int ok, x, y;

	 //x e y serão lidos pelo usuário como as coordenadas do jogo int ok, x, y;
	 while (scanf("%d,%d" , &x, &y)){ 

	  if ((x < 1 || y < 1) || (x > n || y > n)){ 
	 printf("Coordenadas indisponíveis, tente outros números.\n"); 
	   }

	  else if (mat[x - 1][y - 1] != - 10 && mat[x - 1][y - 1] != -1){
	 printf("Coordenadas repetidas, tente outros números.\n"); 
	   } 

	  else {
	    x -= 1; //para o usuario digitar numeros entre 1 e 10, 20 ou 30 
	    y -= 1; 

	    if (mat[x][y] == -10) floodfill(mat, x, y, n4, &cont); 
		
	   registrar_jogada(log, mat, n, x, y); 

	  for (int i = 0; i < n; i++){ 
		for (int j = 0; j < n; j++){ 
			if (mat[i][j] == -10) printf("  x"); //se a matriz nao foi inicializa com -1 ou acum 
			else if (mat[i][j] == -1 && (x != i || y != j)){ 
	          printf("  x"); //todo m[i][j] = -1 ja foi inicilizado, logo ele só aparece caso o usuario digite suas coordenadas
	 	} 
	 		else if (mat[i][j] == -1 && (x == i && y == j)){ 
	 		  printf(" %d" , mat[i][j]);  //imprime -1, somente caso x == i e y == j 
		} 
	        else printf("  %d" , mat[i][j]); //imprime os acumuladores já inicializados
	 	}
	  printf("\n"); 
	 } 

	 //critério de parada que finaliza o jogo em caso tanto de vitória quanto de derrota 
	 if (mat[x][y] == -1 || cont == n3){ 
	 	break;
	 	 		 } 
	 	   }
	  } 

	 if (cont == n3) ok = 1; 
	 else ok = 0;

	fechar_log(log);
	 return ok; 
 } 



 int** inicializa_randomico(int** mat, int n2, int n){ 
	 //faz com que os numeros aleatorios sejam de 1 ate 10,20 ou 30 
	 int random, random2; 
	 srand(time(NULL)); 
	 //util para que os termos deêm números distintos 

	 for (int i = 0; i < n2; i++){ 
	 random = rand() % n; //gera numeros aleatorios que serao as coordenadas das minas 
	 random2 = rand() % n; 
	 // printf("%d %d\n" , random + 1, random2 + 1); 

	 if (mat[random][random2] != -1){ 	 //evita que gere coordenadas repetidas 
	 mat[random][random2] = -1; 
		}
	 else n2++; 
	} 

	return mat; 
}



int** inicializa_matriz(int n){ 
	int* *mat = malloc(n * sizeof(int*)); 
		if(mat == NULL){ 
			printf("Memória insuficiente\n"); 
	} 
	  for (int i = 0; i < n; i++){ 
		mat[i] = malloc(n * sizeof(int)); 
		if(mat[i] == NULL){ 
			printf("Memória insuficiente\n"); 
		} 
	} 

	  for (int i = 0; i < n; i++){ 
		for (int j = 0; j < n; j++){ 
			mat[i][j] = -10; 
			} 
		}

	 return mat; 
}

void variaveis_dificuldade(int dif, int *n, int *n2, int *n3, int *n4){ 
		if (dif == 1){ 
			*n = 10; 
			*n2 = 15;
		    *n3 = 85; 
		    *n4 = 9; 
		} 
		else if (dif == 2){ 
			*n = 20; 
			*n2 = 60; 
			*n3 = 360; 
			*n4 = 19; 
		} else if (dif == 3){ 
			*n = 30; 
			*n2 = 135; 
			*n3 = 765; 
			*n4 = 29; 
		} 
		else printf("Erro, numeração inválida!\n");
}
