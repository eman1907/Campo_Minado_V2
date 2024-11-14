#include <stdio.h> 
#include <time.h> 

//cria uma struct de arquivo que será usada nas funções a seguir
typedef struct { 
	FILE* arquivo; 
} Log; 

//abre o arquivo e imprime data e hora que o usuário iniciou o jogo
Log* abrir_log(); 

//imprime quando a coordenada não existe ou já foi iniciaizada, 
//'det' funciona como diferenciação entre repetida(passa 0 como parametro),
//e inexistente(passa 1 como parametro)
void coordenada_errada(Log* log, int x, int y, int det);

//registra cada jogada do usuário imprimindo o campo dentro do arquivo log.txt incluindo
//as escolhas de jogada do usuário
void registrar_jogada(Log* log, int** mat, int n, int x, int y); 

/*imprime a mensagem que informa o usuário em caso de vitória ou derrota
e imprime a matriz completa sem a presença do 'x' ao final do jogo,
recebe dentro da função o 'inicializa_coordenadas' para calcular o valor
de cada coordenada*/
void campo_final(Log* log, int** mat, int n, int ok);

//fecha o arquivo 
void fechar_log(Log* log);
