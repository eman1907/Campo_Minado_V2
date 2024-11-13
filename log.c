#include <stdlib.h> 
#include <time.h> 
#include "log.h" 

Log* abrir_log(){ 
	Log* log = malloc(sizeof(Log)); 
	log->arquivo = fopen("log.txt" , "w"); 
	if (log->arquivo == NULL){ 
		printf("Erro ao escrever em arquivo\n"); 
		return NULL; 
	} 
	time_t t = time(NULL); 
	struct tm tm = *localtime(&t); 
	fprintf(log->arquivo, "%02d/%02d/%04d %02d:%02d:%02d\n", tm.tm_mday, tm.tm_mon + 1, 
		tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec); 
	fprintf(log->arquivo, "\n");
	return log; 
}

 void registrar_jogada(Log* log, int** mat, int n, int x, int y){ 
	fprintf(log->arquivo,"Coordenada jogada: %d, %d\n" , x + 1, y + 1);
 	for (int i = 0; i < n; i++){ 
 		for (int j = 0; j < n; j++){ 
 			if(mat[i][j] == -10) fprintf(log->arquivo,"  x"); 
 			else if(mat[i][j] == -1 && (x != i || y != j)) fprintf(log->arquivo,"  x");
 			 else if(mat[i][j] == -1 && (x == i && y == j)) fprintf(log->arquivo," %d" , mat[i][j]); 
 			 else fprintf(log->arquivo,"  %d" , mat[i][j]); 
 			  } 
 			fprintf(log->arquivo, "\n"); 
 		  } 
 		fprintf(log->arquivo, "\n");
 	 } 


 void fechar_log(Log* log){
 	if(log != NULL && log->arquivo != NULL){ 
 		fclose(log->arquivo); 
 		} 
 	free(log); 
 	}
