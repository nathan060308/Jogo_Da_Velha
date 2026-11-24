#include <stdio.h>
#include <stdlib.h>
#include <time.h>

 int cont = 1, tempo = -1; //minha variável global, ela que vai decidir se o jogo continua ou não
 char tab[3][3] = {
    {' ', ' ', ' '},  
    {' ', ' ', ' '}, 
    {' ', ' ', ' '}};

void mostrar_tab();
//mostra o jogo

short int ganhou(int a){
    if (a == 3){
        mostrar_tab();
        printf("BOLINHA GANHOU!!\n");
        cont--;
        return 1;
        //como se retornasse true ou false
    }else if(a == -3){
        mostrar_tab();
        printf("X GANHOU!!\n");
        cont--;
        return 1;
    }else{
        return 0;
    }
}

void alguem_ganhou(){
    //vamos verificar as linhas, colunas e as duas diagonais
    //se for com O, cont deve ser +3, se for com X, cont deve ser -3
    //primeiro as linhas
    int contador = 0;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (tab[i][j] == 'O'){
                contador++;
            }else if(tab[i][j] == 'X'){
                contador--;
            }
        }
        if (ganhou(contador) == 1){
             printf("Ganhou pela linha!!\n");
            return;
            }else{
            contador = 0;
            }
    }

    //colunas
    for (int j = 0; j < 3; j++){
        for (int i = 0; i < 3; i++){
            if (tab[i][j] == 'O'){
                contador++;
            }else if(tab[i][j] == 'X'){
                contador--;
            }
        }
        if (ganhou(contador) == 1){
             printf("Ganhou pela coluna!!\n");
             return;
            }else{
            contador = 0;
            }
    }
    
    //diagonais agora
    //diagonal principal
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if(i == j){
                if (tab[i][j] == 'O'){
                contador++;
                }else if(tab[i][j] == 'X'){
                    contador--;
            }
        }
    }
  }
  if (ganhou(contador) == 1){
    printf("Ganhou pela diagonal principal!!\n");
        return;
    }else{
        contador = 0;
    }

  //diagonal secundaria
  for (int i = 0; i < 3; i++){
        for (int j = 2; j >= 0; j--){
            if(i + j == 2){
                if (tab[i][j] == 'O'){
                contador++;
                }else if(tab[i][j] == 'X'){
                contador--;
                }else{
                    return;
                }
        }
    }
  }
  if (ganhou(contador) == 1){
    printf("Ganhou pela diagonal secundaria!!\n");
        return;
    }else{
        contador = 0;
    }
}

void fazer_jogada(){
    int lin, col;
    printf("Digite a linha: \n");
    scanf("%d", &lin);
    printf ("Digite a coluna: \n");
    scanf("%d", &col);
    if (tab[lin-1][col-1] == ' ' && lin >= 1 && lin < 4 && col >= 1 && col < 4){
        if (tempo % 2 == 0){
           tab[lin-1][col-1] = 'X';
        }else{
           tab[lin-1][col-1] = 'O';
        }
    }else{
        printf("Essa posicao e impossivel, tente novamente\n");
        fazer_jogada();
    }
}

void mostrar_tab(){
    for (int i = 0; i < 3; i++){
            printf(" %c  |  %c  |  %c \n", tab[i][0], tab[i][1], tab[i][2]);
            if (i != 2){
                 printf("---------------\n");
                 //diferente de dois pois se eu estiver na ultima linha, não preciso botar mais nenhuma linha
            }
    }
}

int main(){
    printf ("---- JOGO DA VELHA ----\n");
    while(cont == 1){
        mostrar_tab();
        printf("Onde gostaria de jogar?\n");
        tempo++;
        fazer_jogada();
        alguem_ganhou();
    }
}