#include <stdio.h>

#include <stdlib.h>     // inclui a biblioteca padrão para utilizar a função rand()
#include <time.h>       // inclui a biblioteca time para utilizar a função time()

// Desafio Batalha Naval - MateCheck
// Nível Iniciante
// Exibir o tabuleiro e posicionar dois navios
// 04/06/2025 por Reginaldo Moura

// função que imprime o tabuleiro
void printTabuleiro(int tabuleiro[10][10]){
    for (int i = 0; i < 10; i++){

        // imprime o cabeçalho
        if (i == 0){ 
            printf("## # BATALHA NAVAL # ##\n\n");
            printf("    A B C D E F G H I J\n");    //imprime as colunas
        }
        
        for (int j = 0; j < 10; j++){

            // imprime uma coluna com a numeração das linhas
            if (j == 0 && i != 9){
                printf("%d - ", i + 1);
            } else if (j == 0 && i == 9){
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

    
    int tabuleiro[10][10];      // criação do tabuleiro
    int navio[3] = {3, 3, 3};   //criação do navio

    int posicaoNavio1_X;        //variável para armazenar a posição inicial X do navio 1
    int posicaoNavio1_Y;        //variável para armazenar a posição inicial Y do navio 1
    int posicaoNavio2_X;        //variável para armazenar a posição inicial X do navio 2
    int posicaoNavio2_Y;        //variável para armazenar a posição inicial Y do navio 2

    srand(time(0));             //inicializa a função randomica com base no time atual

    // inicialização da matriz tabuleiro
    // for aninhado para percorrer e inicializar os elementos da matriz como 0
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            tabuleiro[i][j] = 0;
        }
    }

    // POSICIONAMENTO DOS NAVIOS
    // navio 1, horizontal

    // determina a posição Y (Linhas ou Vertical)
    posicaoNavio1_Y = rand() % 10; // entre 0 e 9

    // determina a posição X (Colunas ou Horizontal)
    while (1) //loop infinito controlado internamente
    {
        posicaoNavio1_X = rand() % 10;

        // garante que o tamanho do navio não exceda o limite do tabuleiro
        if (posicaoNavio1_X > 7){
            continue;
        } else {
            break;
        }
    }
    
    //posicionando o navio 1
    for (int i = 0; i < 3; i++){
        tabuleiro[posicaoNavio1_Y][posicaoNavio1_X + i] = navio[i];
    }

    // navio 2, vertical
    // é necessário avaliar para não sobrepor navios
    while (1) // loop infinito contolado internamente
    {
        // declaração de variáveis locais
        int tentarDeNovo = 0;   //para controlar o loop

        //determina a posição inicial X (Colunas ou Horizontal)
        posicaoNavio2_X = rand() % 10;

        //determina a posição inicial Y (Linhas ou Vertical)
        while (1){
            posicaoNavio2_Y = rand() % 10;

            // garante que o navio não saia do tabuleiro
            if (posicaoNavio2_Y > 7){
                continue;
            } else {
                break;
            }
        }

        // avalia a sobreposição
        for (int i = 0; i < 3; i++){
            if (tabuleiro[posicaoNavio2_Y + i][posicaoNavio2_X] != 0){
                tentarDeNovo = 1;
            }
        }

        // controla o loop
        if (tentarDeNovo){
            continue;
        } else {
            break;
        }
    }
    
    //posicionando o navio 2
    for (int i = 0; i < 3; i++){
        tabuleiro[posicaoNavio2_Y + i][posicaoNavio2_X] = navio[i];
    }

    // imprimir o tabuleiro
    printTabuleiro(tabuleiro);


    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

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
