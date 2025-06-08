// Desafio Batalha Naval - MateCheck
// Nível Mestre
// Implementar habilidades
// 07/06/2025 por Reginaldo Moura

#include <stdio.h>
#include <stdlib.h>     // inclui a biblioteca padrão para utilizar a função rand()
#include <time.h>       // inclui a biblioteca time para utilizar a função time()

//Constantes
#define TAMANHO_TAB 12
#define TAMANHO_NAVIO 3
#define TAMANHO_HAB 5
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 1
#define EFEITO_HAB 5

// protótipos de funções

// função que inicializa uma matriz quadrada com todos elementos iguais
void inicializaMatriz(int valor, int tamanho, int matriz[tamanho][tamanho]);

// função que inicializa um vetor com todos elementos iguais
void inicializaVetor(int valor, int tamanho, int vetor[tamanho]);

// função que retorna um número aleatório entre 0 e (TAMANHO - 1)
int posicaoAleatoria();

// função que define um navio na posição horizontal
void navioHorizontal(int tamanhoTab, int tabuleiro[tamanhoTab][tamanhoTab],
                     int tamanhoNavio, int navio[tamanhoNavio]);

// função que define um navio na vertical
void navioVertical(int tamanhoTab, int tabuleiro[tamanhoTab][tamanhoTab],
                   int tamanhoNavio, int navio[tamanhoNavio]);

// função que define um navio na posição diagonal Esq --> Dir
void navioDiagonalPrincipal(int tamanhoTab, int tabuleiro[tamanhoTab][tamanhoTab],
                           int tamanhoNavio, int navio[tamanhoNavio]);

// função que define um navio na posição diagonal Dir --> Esq
void navioDiagonalSecundaria(int tamanhoTab, int tabuleiro[tamanhoTab][tamanhoTab],
                           int tamanhoNavio, int navio[tamanhoNavio]);


// função que inicializa a habilidade em Cone
void inicializaCone(int altura, int tamanho, int cone[altura][tamanho]);

// função que inicializa a habilidade em Cruz
void inicializaCruz(int tamanho, int cruz[tamanho][tamanho]);

// função que inicializa a habilidade em Octaedro
void inicializaOctaedro(int tamanho, int octaedro[tamanho][tamanho]);

// função que posiciona a habilidade no tabuleiro
void posicionaHabilidade(int linhasHab, int colunasHab, int habilidade[linhasHab][colunasHab],
                         int tamanhoTab, int tabuleiro[tamanhoTab][tamanhoTab]);

// função que imprime o tabuleiro
void imprimeTabuleiro(int tamanho, int tabuleiro[tamanho][tamanho]);

// a função main inicia o programa
int main(){
    srand(time(0));

    //DECLARAÇÃO DE ELEMENTOS DO JOGO
    //estruturas
    int tabuleiro[TAMANHO_TAB][TAMANHO_TAB];    //tabuleiro de batalha naval
    int navio[TAMANHO_NAVIO];                   // "objeto" navio

    //habilidades
    int centro = TAMANHO_HAB / 2;
    int alturaCone = TAMANHO_HAB - centro;  //evita linhas extras além da base do cone
    int cone[alturaCone][TAMANHO_HAB];
    int cruz[TAMANHO_HAB][TAMANHO_HAB];
    int octaedro[TAMANHO_HAB][TAMANHO_HAB];

    inicializaMatriz(AGUA, TAMANHO_TAB, tabuleiro); //inicializa o tabuleiro
    inicializaVetor(NAVIO, TAMANHO_NAVIO, navio);   //inicializa o navio

    inicializaCone(alturaCone, TAMANHO_HAB, cone);
    inicializaCruz(TAMANHO_HAB, cruz);
    inicializaOctaedro(TAMANHO_HAB, octaedro);

    //POSICIONA NAVIOS NO TABULEIRO
    /*
    navioHorizontal(TAMANHO_TAB, tabuleiro, TAMANHO_NAVIO, navio);
    navioVertical(TAMANHO_TAB, tabuleiro, TAMANHO_NAVIO, navio);
    navioDiagonalPrincipal(TAMANHO_TAB, tabuleiro, TAMANHO_NAVIO, navio);
    navioDiagonalSecundaria(TAMANHO_TAB, tabuleiro, TAMANHO_NAVIO, navio);
    */

    //POSICIONA HABILIDADES NO TABULEIRO
    
    posicionaHabilidade(alturaCone, TAMANHO_HAB, cone, TAMANHO_TAB, tabuleiro);
    posicionaHabilidade(TAMANHO_HAB, TAMANHO_HAB, cruz, TAMANHO_TAB, tabuleiro);
    posicionaHabilidade(TAMANHO_HAB, TAMANHO_HAB, octaedro, TAMANHO_TAB, tabuleiro);
    

    //imprime o tabuleiro
    imprimeTabuleiro(TAMANHO_TAB, tabuleiro);

    return 0;
} // fim da função main

// função que inicializa uma matriz quadrada com todos os elementos iguais
void inicializaMatriz(int valor, int tamanho, int matriz[tamanho][tamanho]){
    for (int i = 0; i < tamanho; i++){
        for (int j = 0; j < tamanho; j++){
            matriz[i][j] = valor;
        }
    }
} //fim da função inicializaMatriz

// função que inicializa um vetor com todos elementos iguais
void inicializaVetor(int valor, int tamanho, int vetor[tamanho]){
    for (int i = 0; i < tamanho; i++){
        vetor[i] = valor;
    }
}

// função que imprime o tabuleiro
void imprimeTabuleiro(int tamanho, int tabuleiro[tamanho][tamanho]){

    char letra = 'A'; //variável para exibir as colunas

    for (int i = 0; i < tamanho; i++){

        //imprime o cabeçalho do jogo
        if (i == 0){
            printf("## # BATALHA NAVAL # ##\n");
            printf("\n    "); //espaços para alinhar a linha de colunas
    
            //imprime indicação das colunas
            for (int c = 0; c < tamanho; c++){
                printf("%c ", letra);
                letra++;
            }
            printf("\n"); //nova linha
        }
        
        for (int j = 0; j < tamanho; j++){

            //imprime a indicação das linhas
            if (j == 0 && i <= 8){
                printf("%d - ", i + 1);
            } else if (j == 0 && i > 8){
                printf("%d- ", i + 1);
            }
            
            //imprime o tabuleiro
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
} // fim da função imprimeTabuleiro

// função que retorna um número aleatório entre 0 e (TAMANHO - 1)
int posicaoAleatoria(){
    return rand() % TAMANHO_TAB;
} // fim da função posicaoAleatoria


//FONÇÕES QUE INICIALIZAM E POSICIONAM NAVIOS

// função que define um navio na posição horizontal
void navioHorizontal(int tamanhoTab, int tabuleiro[tamanhoTab][tamanhoTab],
                     int tamanhoNavio, int navio[tamanhoNavio])
{
    int tentarDeNovo = 0;   //controla o loop
    int posicaoY, posicaoX; //posição Y e X (linha, coluna) iniciais

    while (1)
    {
        // determina a posição Y (Linhas ou Vertical)
        posicaoY = posicaoAleatoria();
        
        // determina a posição X (Colunas ou Horizontal)
        while (1)
        {
            posicaoX = posicaoAleatoria();
    
            // garante que o tamanho do navio não exceda o limite do tabuleiro
            if (posicaoX > (tamanhoTab - tamanhoNavio)){
                continue;
            } else {
                break;
            }
        }

        // avalia a sobreposição
        for (int i = 0; i < tamanhoNavio; i++){
            if (tabuleiro[posicaoY][posicaoX + i] != AGUA){
                tentarDeNovo = 1;
            }
        }

        // controla o loop
        if (tentarDeNovo){
            continue;
        } else {
            //posicionando o navio horizontal no tabuleiro
            for (int i = 0; i < tamanhoNavio; i++){
                tabuleiro[posicaoY][posicaoX + i] = navio[i];
            }

            break;

        }
    } // fim do loop que define o navio horizontal
} // fim da função navioHorizontal

// função que define um navio na posição vertical
void navioVertical(int tamanhoTab, int tabuleiro[tamanhoTab][tamanhoTab],
                   int tamanhoNavio, int navio[tamanhoNavio])
{
    
    // declaração de variáveis locais
    int tentarDeNovo = 0;
    int posicaoY, posicaoX;

    while (1) // navio vertical
    {

        //determina a posição inicial X (Colunas ou Horizontal)
        posicaoX = posicaoAleatoria();

        //determina a posição inicial Y (Linhas ou Vertical)
        while (1){
            posicaoY = posicaoAleatoria();

            // garante que o navio não saia do tabuleiro
            if (posicaoY > (tamanhoTab - tamanhoNavio)){
                continue;
            } else {
                break;
            }
        }

        // avalia a sobreposição
        for (int i = 0; i < tamanhoNavio; i++){
            if (tabuleiro[posicaoY + i][posicaoX] != AGUA){
                tentarDeNovo = 1;
            }
        }

        // controla o loop
        if (tentarDeNovo){
            continue;
        } else {
            //posicionando o navio no tabuleiro
            for (int i = 0; i < tamanhoNavio; i++){
            tabuleiro[posicaoY + i][posicaoX] = navio[i];
            }
            break;
        }
    } // fim do loop q define o navio vertical
} // fim da função navioVertical

// função que define um navio na posição diagonal Principal
void navioDiagonalPrincipal(int tamanhoTab, int tabuleiro[tamanhoTab][tamanhoTab],
                           int tamanhoNavio, int navio[tamanhoNavio])
{
    // declaração de variáveis locais
    int tentarDeNovo = 0;
    int posicaoY, posicaoX;

    while (1) // navio diagonal Esq --> Dir
    {
        //determina a posição inicial X (Colunas ou Horizontal)
        while (1){
            posicaoX = posicaoAleatoria();

            // garante que o navio não saia do tabuleiro
            if (posicaoX > (tamanhoTab - tamanhoNavio)){
                continue;
            } else {
                break;
            }
        }
        
        //determina a posição inicial Y (Linhas ou Vertical)
        while (1){
            posicaoY = posicaoAleatoria();

            // garante que o navio não saia do tabuleiro
            if (posicaoY > (tamanhoTab - tamanhoNavio)){
                continue;
            } else {
                break;
            }
        }

        // avalia a sobreposição em uma area 3 x 3
        for (int i = 0; i < tamanhoNavio; i++){
            for (int j = 0; j < tamanhoNavio; j++){
                if (tabuleiro[posicaoY + i][posicaoX + j] != AGUA){
                    tentarDeNovo = 1;
                }
            }
        }

        // controla o loop
        if (tentarDeNovo){
            continue;
        } else {
            //posicionando o navio no tabuleiro
            for (int i = 0; i < tamanhoNavio; i++){
            tabuleiro[posicaoY + i][posicaoX + i] = navio[i];
            }
            break;
        }
    } // fim do loop q define o navio diagonal Esq --> Dir
}// fim da função navioDiagonalPrincipal

// função que define um navio na posição diagonal Dir --> Esq
void navioDiagonalSecundaria(int tamanhoTab, int tabuleiro[tamanhoTab][tamanhoTab],
                           int tamanhoNavio, int navio[tamanhoNavio])
{
    // declaração de variáveis locais
    int tentarDeNovo = 0;
    int posicaoY, posicaoX;

    while (1) // navio diagonal Dir --> Esq
    {

        //determina a posição inicial X (Colunas ou Horizontal)
        while (1){
            posicaoX = posicaoAleatoria();

            // garante que o navio não saia do tabuleiro
            if (posicaoX > (tamanhoTab - tamanhoNavio)){
                continue;
            } else {
                break;
            }
        }
        
        //determina a posição inicial Y (Linhas ou Vertical)
        while (1){
            posicaoY = posicaoAleatoria();

            // garante que o navio não saia do tabuleiro
            if (posicaoY < (tamanhoNavio - 1)){
                continue;
            } else {
                break;
            }
        }

        // avalia a sobreposição em uma area 3 x 3
        for (int i = 0; i < tamanhoNavio; i++){
            for (int j = 0; j < tamanhoNavio; j++){
                if (tabuleiro[posicaoY - i][posicaoX + j] != AGUA){
                    tentarDeNovo = 1;
                }
            }
        }

        // controla o loop
        if (tentarDeNovo){
            continue;
        } else {
            //posicionando o navio no tabuleiro
            for (int i = 0; i < tamanhoNavio; i++){
            tabuleiro[posicaoY - i][posicaoX + i] = navio[i];
            }
            break;
        }
    }// fim do loop q define o navio diagonal Dir --> Esq
} // fim da função navioDiagonalSecundaria


// FUNÇÕES QUE INICIALIZAM E POSICIONAM AS HABILIDADES

// função que inicializa a habilidade em Cone
void inicializaCone(int altura, int tamanho, int cone[altura][tamanho]){
    
    int centro = tamanho / 2;

    for (int i = 0; i < altura; i++){
        for (int j = 0; j < tamanho; j++){
            //um cone "cresce" de acordo com a altura (linhas) e a distância do centro
            cone[i][j] = (j >= centro - i && j <= centro + i) ? HABILIDADE : AGUA;
        }
    }
} // fim da função inicializaCone

// função que inicializa a habilidade em Cruz
void inicializaCruz(int tamanho, int cruz[tamanho][tamanho]){

    int centro = tamanho / 2;

    for (int i = 0; i < tamanho; i++){
        for (int j = 0; j < tamanho; j++){
            cruz[i][j] = (j == centro || i == centro) ? HABILIDADE : AGUA;
        }
    }
} // fim da função inicializaCruz

// função que inicializa a habilidade em Octaedro
void inicializaOctaedro(int tamanho, int octaedro[tamanho][tamanho]){
    int centro = tamanho / 2;
    int dist_x, dist_y;         //distância do centro

    for (int i = 0; i < tamanho; i++){
        for (int j = 0; j < tamanho; j++){

            //calcula as distãncias até o centro
            dist_x = (j > centro) ? j - centro : centro - j;
            dist_y = (i > centro) ? i - centro : centro - i;

            //condição do losango
            octaedro[i][j] = (dist_x + dist_y <= centro) ? HABILIDADE : AGUA;
        }
    }
} // fim da função inicializaOctaedro

// função que posiciona a habilidade no tabuleiro
void posicionaHabilidade(int linhasHab, int colunasHab, int habilidade[linhasHab][colunasHab],
                         int tamanhoTab, int tabuleiro[tamanhoTab][tamanhoTab])
{
    int posicaoX, posicaoY;
    int tentativas = 0;
    const int MAX_TENTATIVAS = 100;

    while (tentativas < MAX_TENTATIVAS)
    {
        int posicaoValida = 1;
        
        // Gera posições aleatórias dentro dos limites
        posicaoY = rand() % (tamanhoTab - linhasHab + 1);
        posicaoX = rand() % (tamanhoTab - colunasHab + 1);

        // Verifica sobreposição
        for (int i = 0; i < linhasHab && posicaoValida; i++) {
            for (int j = 0; j < colunasHab; j++) {
                if (tabuleiro[posicaoY + i][posicaoX + j] != AGUA) {
                    posicaoValida = 0;
                    break;
                }
            }
        }

        // Se posição válida, coloca a habilidade
        if (posicaoValida) {
            for (int i = 0; i < linhasHab; i++) {
                for (int j = 0; j < colunasHab; j++) {
                    if (habilidade[i][j] == HABILIDADE) {
                        tabuleiro[posicaoY + i][posicaoX + j] = habilidade[i][j];
                    }
                }
            }
            return;
        }

        tentativas++;
    }

    printf("Não foi possível posicionar habilidade após %d tentativas\n", MAX_TENTATIVAS);
}

