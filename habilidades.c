#include <stdio.h>

int main(){

    int tamanho = 5;
    int centro = tamanho / 2;
    int dist_x, dist_y;     //distância do centro

    int cone[tamanho][tamanho];
    int cruz[tamanho][tamanho];
    int octaedro[tamanho][tamanho];

    //matriz da habilidade em cruz
    for (int i = 0; i < tamanho; i++){
        for (int j = 0; j < tamanho; j++){

            cruz[i][j] = (j == centro || i == centro) ? 1 : 0;

            printf("%d ", cruz[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");

    //matriz da habilidade cone
    for (int i = 0; i < tamanho; i++){
        for (int j = 0; j < tamanho; j++){

            if (j >= centro - i && j <= centro + i && i <= centro){
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }

            printf("%d ", cone[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    
    //matriz da habilidade octaedro
    for (int i = 0; i < tamanho; i++){
        for (int j = 0; j < tamanho; j++){

            //calcula as distãncias até o centro
            dist_x = (j > centro) ? j - centro : centro - j;
            dist_y = (i > centro) ? i - centro : centro - i;

            //condição do losango
            octaedro[i][j] = (dist_x + dist_y <= centro) ? 1 : 0;

            printf("%d ", octaedro[i][j]);
        }
        printf("\n");
    }


    return 0;
}