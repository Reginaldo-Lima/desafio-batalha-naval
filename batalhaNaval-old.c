// Desafio Batalha Naval - MateCheck
// Nível Aventureiro
// Exibir o tabuleiro e posicionar dois navios
// 05/06/2025 por Reginaldo Moura

#include <stdio.h>
#include <stdlib.h>     // inclui a biblioteca padrão para utilizar a função rand()
#include <time.h>       // inclui a biblioteca time para utilizar a função time()

//Constantes
#define TAMANHO 10
#define TAMANHO_NAVIO 3
#define NAVIO 3
#define AGUA 0
#define HABILIDADE 1
#define AREA_HABILIDADE 5
#define EFEITO_HABILIDADE 5

// função que imprime o tabuleiro
void printTabuleiro(int tabuleiro[TAMANHO][TAMANHO]){
    for (int i = 0; i < TAMANHO; i++){

        // imprime o cabeçalho
        if (i == 0){ 
            char letra = 'A';

            printf("## # BATALHA NAVAL # ##\n\n");
            printf("    ");    //imprime um espaço, estético

            for (int i = 0; i < TAMANHO; i++){
                printf("%c ", letra);   // imprime as colunas
                letra++;
            }
            printf("\n");   //quebra de linha
        }
        
        for (int j = 0; j < TAMANHO; j++){

            // imprime uma coluna com a numeração das linhas
            if (j == 0 && i < 9){
                printf("%d - ", i + 1);
            } else if (j == 0 && i > 9){
                printf("%d- ", i + 1);  // imprime o número da linha 10 (por estética)
            }

            printf("%d ", tabuleiro[i][j]); //imprime o tabuleiro, de fato
        }

        printf("\n");   //imprime uma nova linha
    }
} // fim da função printTabuleiro

// função que retorna um número aleatório entre 0 e (TAMANHO - 1)
int posicaoAleatoria(){
    int num;
    num = rand() % TAMANHO;
    return num; 
} // fim da função posicaoAleatoria


// função main inicia o programa
int main()
{
    
    int tabuleiro[TAMANHO][TAMANHO];     //criação do tabuleiro
    int navio[TAMANHO_NAVIO];           //criação do navio
    int posicaoX = 0;        //posição inicial X do navio
    int posicaoY = 0;        //posição inicial Y do navio
    int tentarDeNovo = 0;    //para controlar o loop

    srand(time(0));             //inicializa a função randomica com base no time atual

    // inicialização da matriz tabuleiro
    // for aninhado para percorrer e inicializar os elementos da matriz como "AGUA"
    for (int i = 0; i < TAMANHO; i++){
        for (int j = 0; j < TAMANHO; j++){
            tabuleiro[i][j] = AGUA;
        }
    }

    // Inicialização do navio
    for (int i = 0; i < TAMANHO_NAVIO; i++){
        navio[i] = NAVIO;
    }

    // POSICIONAMENTO DOS NAVIOS
    
    while (1) // navio horizontal
    {
        tentarDeNovo = 0;
        
        // determina a posição Y (Linhas ou Vertical)
        posicaoY = posicaoAleatoria();
        
        // determina a posição X (Colunas ou Horizontal)
        while (1)
        {
            posicaoX = posicaoAleatoria();
    
            // garante que o tamanho do navio não exceda o limite do tabuleiro
            if (posicaoX > (TAMANHO - TAMANHO_NAVIO)){
                continue;
            } else {
                break;
            }
        }

        // avalia a sobreposição
        for (int i = 0; i < TAMANHO_NAVIO; i++){
            if (tabuleiro[posicaoY][posicaoX + i] != AGUA){
                tentarDeNovo = 1;
            }
        }

        // controla o loop
        if (tentarDeNovo){
            continue;
        } else {
            //posicionando o navio horizontal no tabuleiro
            for (int i = 0; i < TAMANHO_NAVIO; i++){
                tabuleiro[posicaoY][posicaoX + i] = navio[i];
            }

            break;

        }
    } // fim do loop que define o navio horizontal


    while (1) // navio vertical
    {
        // declaração de variáveis locais
        tentarDeNovo = 0;

        //determina a posição inicial X (Colunas ou Horizontal)
        posicaoX = posicaoAleatoria();

        //determina a posição inicial Y (Linhas ou Vertical)
        while (1){
            posicaoY = posicaoAleatoria();

            // garante que o navio não saia do tabuleiro
            if (posicaoY > (TAMANHO - TAMANHO_NAVIO)){
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

        // controla o loop
        if (tentarDeNovo){
            continue;
        } else {
            //posicionando o navio no tabuleiro
            for (int i = 0; i < TAMANHO_NAVIO; i++){
            tabuleiro[posicaoY + i][posicaoX] = navio[i];
            }
            break;
        }
    } // fim do loop q define o navio vertical
    
    // Nível Aventureiro - Posicionamento de Navios na Diagonal
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.

    while (1) // navio diagonal Esq --> Dir
    {
        // declaração de variáveis locais
        tentarDeNovo = 0;

        //determina a posição inicial X (Colunas ou Horizontal)
        while (1){
            posicaoX = posicaoAleatoria();

            // garante que o navio não saia do tabuleiro
            if (posicaoX > (TAMANHO - TAMANHO_NAVIO)){
                continue;
            } else {
                break;
            }
        }
        
        //determina a posição inicial Y (Linhas ou Vertical)
        while (1){
            posicaoY = posicaoAleatoria();

            // garante que o navio não saia do tabuleiro
            if (posicaoY > (TAMANHO - TAMANHO_NAVIO)){
                continue;
            } else {
                break;
            }
        }

        // avalia a sobreposição em uma area 3 x 3
        for (int i = 0; i < TAMANHO_NAVIO; i++){
            for (int j = 0; j < TAMANHO_NAVIO; j++){
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
            for (int i = 0; i < TAMANHO_NAVIO; i++){
            tabuleiro[posicaoY + i][posicaoX + i] = navio[i];
            }
            break;
        }
    } // fim do loop q define o navio diagonal Esq --> Dir

    
    while (1) // navio diagonal Dir --> Esq
    {
        // declaração de variáveis locais
        tentarDeNovo = 0;

        //determina a posição inicial X (Colunas ou Horizontal)
        while (1){
            posicaoX = posicaoAleatoria();

            // garante que o navio não saia do tabuleiro
            if (posicaoX > (TAMANHO - TAMANHO_NAVIO)){
                continue;
            } else {
                break;
            }
        }
        
        //determina a posição inicial Y (Linhas ou Vertical)
        while (1){
            posicaoY = posicaoAleatoria();

            // garante que o navio não saia do tabuleiro
            if (posicaoY < (TAMANHO_NAVIO - 1)){
                continue;
            } else {
                break;
            }
        }

        // avalia a sobreposição em uma area 3 x 3
        for (int i = 0; i < TAMANHO_NAVIO; i++){
            for (int j = 0; j < TAMANHO_NAVIO; j++){
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
            for (int i = 0; i < TAMANHO_NAVIO; i++){
            tabuleiro[posicaoY - i][posicaoX + i] = navio[i];
            }
            break;
        }
    }// fim do loop q define o navio diagonal Dir --> Esq

    
    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.
    
    // imprimir o tabuleiro
    printTabuleiro(tabuleiro);

    return 0;
} // fim da função main

