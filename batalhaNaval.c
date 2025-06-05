// Desafio Batalha Naval - MateCheck
// Nível Aventureiro
// Exibir o tabuleiro e posicionar dois navios
// 05/06/2025 por Reginaldo Moura

#include <stdio.h>

#include <stdlib.h>     // inclui a biblioteca padrão para utilizar a função rand()
#include <time.h>       // inclui a biblioteca time para utilizar a função time()

//Constantes
#define LINHAS 10
#define COLUNAS 10
#define TAMANHO_NAVIO 3
#define NAVIO 3
#define AGUA 0

// função que imprime o tabuleiro
void printTabuleiro(int tabuleiro[LINHAS][COLUNAS]){
    for (int i = 0; i < LINHAS; i++){

        // imprime o cabeçalho
        if (i == 0){ 
            printf("## # BATALHA NAVAL # ##\n\n");
            printf("    A B C D E F G H I J\n");    //imprime as colunas
        }
        
        for (int j = 0; j < COLUNAS; j++){

            // imprime uma coluna com a numeração das linhas
            if (j == 0 && i != COLUNAS - 1){
                printf("%d - ", i + 1);
            } else if (j == 0 && i > 8){
                printf("%d- ", i + 1);  // imprime o número da linha 10 (por estética)
            }

            printf("%d ", tabuleiro[i][j]); //imprime o tabuleiro, de fato
        }

        printf("\n");   //imprime uma nova linha
    }
} // fim da função printTabuleiro


// função main inicia o programa
int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    int tabuleiro[LINHAS][COLUNAS];      // criação do tabuleiro
    int navio[TAMANHO_NAVIO];   //criação do navio

    int posicaoX = 0;        //posição inicial X do navio
    int posicaoY = 0;        //posição inicial Y do navio

    srand(time(0));             //inicializa a função randomica com base no time atual

    // inicialização da matriz tabuleiro
    // for aninhado para percorrer e inicializar os elementos da matriz como 0
    for (int i = 0; i < LINHAS; i++){
        for (int j = 0; j < COLUNAS; j++){
            tabuleiro[i][j] = AGUA;
        }
    }

    // Inicialização do navio
    for (int i = 0; i < TAMANHO_NAVIO; i++){
        navio[i] = NAVIO;
    }

    // POSICIONAMENTO DOS NAVIOS
    // navio horizontal
    while (1) //loop infinito controlado internamente
    {
        //variaveis locais
        int tentarDeNovo = 0;   //para controlar o loop
        
        // determina a posição Y (Linhas ou Vertical)
        posicaoY = rand() % LINHAS; // determina um numero entre 0 e "LINHAS"
        
        // determina a posição X (Colunas ou Horizontal)
        while (1)
        {
            posicaoX = rand() % COLUNAS;
    
            // garante que o tamanho do navio não exceda o limite do tabuleiro
            if (posicaoX > (COLUNAS - TAMANHO_NAVIO)){
                continue;
            } else {
                break;
            }
        }

        // avalia a sobreposição
        for (int i = 0; i < TAMANHO_NAVIO; i++){
            if (tabuleiro[posicaoX + i][posicaoY] != AGUA){
                tentarDeNovo = 1;
            }
        }

        //posicionando o navio no tabuleiro
        for (int i = 0; i < TAMANHO_NAVIO; i++){
            tabuleiro[posicaoY][posicaoX + i] = navio[i];
        }

        // controla o loop
        if (tentarDeNovo){
            continue;
        } else {
            break;
        }
    } // fim do loop que define o navio vertical
    

    // navio vertical
    while (1) // loop infinito contolado internamente
    {
        // declaração de variáveis locais
        int tentarDeNovo = 0;   //para controlar o loop

        //determina a posição inicial X (Colunas ou Horizontal)
        posicaoX = rand() % COLUNAS;

        //determina a posição inicial Y (Linhas ou Vertical)
        while (1){
            posicaoY = rand() % LINHAS;

            // garante que o navio não saia do tabuleiro
            if (posicaoY > (LINHAS - TAMANHO_NAVIO)){
                continue;
            } else {
                break;
            }
        }

        // avalia a sobreposição
        for (int i = 0; i < TAMANHO_NAVIO; i++){
            if (tabuleiro[posicaoY + i][posicaoX] != AGUA){
                tentarDeNovo = 1;
            }
        }

        //posicionando o navio no tabuleiro
        for (int i = 0; i < TAMANHO_NAVIO; i++){
        tabuleiro[posicaoY + i][posicaoX] = navio[i];
        }

        // controla o loop
        if (tentarDeNovo){
            continue;
        } else {
            break;
        }
    } // fim do loop q define o navio horizontal
    
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.
    
    // navio diagonal Esq --> Dir
    while (1) // loop infinito contolado internamente
    {
        // declaração de variáveis locais
        int tentarDeNovo = 0;   //para controlar o loop

        //determina a posição inicial X (Colunas ou Horizontal)
        while (1){
            posicaoX = rand() % COLUNAS;

            // garante que o navio não saia do tabuleiro
            if (posicaoY > (COLUNAS - TAMANHO_NAVIO)){
                continue;
            } else {
                break;
            }
        }
        
        //determina a posição inicial Y (Linhas ou Vertical)
        while (1){
            posicaoY = rand() % LINHAS;

            // garante que o navio não saia do tabuleiro
            if (posicaoY > (LINHAS - TAMANHO_NAVIO)){
                continue;
            } else {
                break;
            }
        }

        // avalia a sobreposição
        for (int i = 0; i < TAMANHO_NAVIO; i++){
            if (tabuleiro[posicaoY + i][posicaoX + i] != AGUA){
                tentarDeNovo = 1;
            }
        }

        //posicionando o navio no tabuleiro
        for (int i = 0; i < TAMANHO_NAVIO; i++){
        tabuleiro[posicaoY + i][posicaoX + i] = navio[i];
        }

        // controla o loop
        if (tentarDeNovo){
            continue;
        } else {
            break;
        }
    } // fim do loop q define o navio diagonal Esq --> Dir

    // navio diagonal Dir --> Esq
    while (1) // loop infinito contolado internamente
    {
        // declaração de variáveis locais
        int tentarDeNovo = 0;   //para controlar o loop

        //determina a posição inicial X (Colunas ou Horizontal)
        while (1){
            posicaoX = rand() % COLUNAS;

            // garante que o navio não saia do tabuleiro
            if (posicaoY < (TAMANHO_NAVIO - 1)){
                continue;
            } else {
                break;
            }
        }
        
        //determina a posição inicial Y (Linhas ou Vertical)
        while (1){
            posicaoY = rand() % LINHAS;

            // garante que o navio não saia do tabuleiro
            if (posicaoY < (TAMANHO_NAVIO - 1)){
                continue;
            } else {
                break;
            }
        }

        // avalia a sobreposição
        for (int i = 0; i < TAMANHO_NAVIO; i++){
            if (tabuleiro[posicaoY - i][posicaoX + i] != AGUA){
                tentarDeNovo = 1;
            }
        }

        //posicionando o navio no tabuleiro
        for (int i = 0; i < TAMANHO_NAVIO; i++){
        tabuleiro[posicaoY - i][posicaoX + i] = navio[i];
        }

        // controla o loop
        if (tentarDeNovo){
            continue;
        } else {
            break;
        }
    } // fim do loop q define o navio diagonal Dir --> Esq

    
    // imprimir o tabuleiro
    printTabuleiro(tabuleiro);


    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
} // fim da função main
