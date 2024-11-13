#include <stdio.h> 
#include <time.h> 

//cria uma struct de arquivo que será usada nas funções a seguir
typedef struct { 
	FILE* arquivo; 
} Log; 

//abre o arquivo dentro da função leitura_das_coordenadas e imprime data e hora que o usuário iniciou o jogo
Log* abrir_log(); 

//registra cada jogada do usuário imprimindo o campo dentro da matriz
void registrar_jogada(Log* log, int** mat, int n, int x, int y); 

//imprime a mensagem que informa o usuário em caso de vitória ou derrota
//e imprime a matriz completa sem a presença do 'x'
void campo_final(Log* log, int** mat, int n, int ok);

//fecha o arquivo ao fim da função leitura_das_coordenadas
void fechar_log(Log* log);
