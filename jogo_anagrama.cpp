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

int main () {
    char vetorPalavras[MAX][15];
    char vetorLetras[20] = {'A','B','C','D','A','E','I','O','U','D','B','J','R','T','U','J','B','T','L','L'};
    char vetorRespostas[MAX][15];


    imprime_anagrama(vetorLetras);
}
