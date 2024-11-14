
void floodfill(int** mat, int x, int y, int n4, int *cont);
/*função recursiva que expande o campo em caso das coordenadas apresentadas não possuirem minas vizinhas,
chama dentro dela a função 'inicializa_coordenadas' para ler o valor de cada coordenada conforme a quantidade
de minas vizinhas*/

int inicializa_coordenadas(int** mat, int x, int y, int n4);
/*função usada dentro de floodfill, resultado_final e campo_final(log.c) 
para calcular o valor de cada coordenada diferente de -1 */

void variaveis_dificuldade(int dif, int *n, int *n2, int *n3, int *n4);
 //dif lê a dificuldade do jogo, podendo ser fácil, médio ou difícil 
 //n será a ordem da matriz conforme a dificuldade desejada 
 //n2 vai ser a quantidade de 'minas' no jogo, referente ao numero -1 
 //n3 é o máximo de casas do jogo sem a presença das bombas 
 //n4 é o útimo termo de n 

int** inicializa_matriz(int n); 
 //aloca a matriz nxn dinamicamente 
 //atribuindo -10 a cada coordenada por ser um númeoro impossível no jogo 

 int** inicializa_randomico(int** mat, int n2, int n); 
 /*inclui as minas em posições aleatórias de acordo com a dificuldade do jogo 
 representadas pelo valor -1*/ 


 int** resultado_final(int** mat, int acum, int n, int n4); 
 /*tanto em caso de vitória quanto de derrota será executada essa função afim
  de apresentar o campo completo sem a presença do 'x'*/ 

  void liberar_matriz(int** mat, int lin); 
  //libera o espaço da matriz alocada dinamicamente
