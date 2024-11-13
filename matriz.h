
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
 //inclui as minas em posições aleatórias de acordo com a dificuldade do jogo 
 //representadas pelo valor -1 

 int leitura_das_coordenadas(int n, int acum, int cont, int n3, int n4, int** mat); 
 /*lê 'x' e 'y' dados pelo usuário, confere se as coordenadas são válidas e não são repetidas, após isso verifica se a mat[x][y] == -1, 
 e em caso positivo imprime o campo com a presença da mina e finaliza a função retornando 0, que significa que o usuário perdeu. 
 Caso mat[x][y] == -10, será chamada a função floodfill que recursivamente iniciliaza todas as casas vizinhas da mina na posicão x,y com 
 o número equivalente a quantidade de minas próximas e repete o processo enquanto o valor for igual a 0, paralelo a essa função, enquanto 
 as casas vizinhas estão sendo inicializadas o endereço do contador esta sendo adicionado 1, assim, quando o contador atingir o valor de n3, 
 a função termina e retorna 1, que significa que o usuário ganhou o jogo. */ 

 int** resultado_final(int** mat, int acum, int n, int n4); 
 /*tanto em caso de vitória quanto de derrota será executada essa função afim
  de apresentar o campo completo sem a presença do 'x'*/ 

  void liberar_matriz(int** mat, int lin); 
  //libera o espaço da matriz alocada dinamicamente
