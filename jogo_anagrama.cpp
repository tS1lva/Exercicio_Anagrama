#include <iostream>
#include <stdio.h>
#include <string.h>
#include <iomanip>
using namespace std;
#define MAX 30


void imprime_anagrama(char *vetor_anagrama){

    for (int i = 0 ; i < MAX ; i++){
        cout<<vetor_anagrama[i];
        if (i%4 == 0){
            cout<<endl;
        }

    }
};

int main () {
    char vetorPalavras[MAX][15];
    char vetorLetras[20];
    char vetorRespostas[MAX][15];
}
