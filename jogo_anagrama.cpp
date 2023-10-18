#include <iostream>
#include <stdio.h>
#include <string.h>
#include <iomanip>
using namespace std;
#define MAX 30


void imprime_anagrama(char *vetor_anagrama){

    for (int i = 0 ; i < 20 ; i++){
        cout<<vetor_anagrama[i]<<"   ";
        if ((i+1)%4 == 0){
            cout<<endl;
        }

    }
};

int confere (char *vetorPalavras[MAX], char resposta[15]) {
    for(int ax = 0; ax < MAX; ax++) {
        if (strcmp(vetorPalavras[ax], resposta) == 0) {
            return 0;
        }
    }
    return 1;
}

int main () {
    char vetorPalavras[MAX][15];
    char vetorLetras[20] = {'A','B','C','D','A','E','I','O','U','D','B','J','R','T','U','J','B','T','L','L'};
    char vetorRespostas[MAX][15];

    imprime_anagrama(vetorLetras);
}
