#include <stdio.h> 
#include <time.h> 

//cria uma struct de arquivo que será usada nas funções a seguir
typedef struct { 
	FILE* arquivo; 
} Log; 

//abre o arquivo dentro da função leitura_das_coordenadas
Log* abrir_log(); 

//registra cada jogada do usuário imprimindo o campo dentro da matriz
void registrar_jogada(Log* log, int** mat, int n, int x, int y); 

//fecha o arquivo ao fim da função leitura_das_coordenadas
void fechar_log(Log* log);
