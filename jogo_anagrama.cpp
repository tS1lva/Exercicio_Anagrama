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

int confere (char vetorPalavras[][15], char resposta[15]) {
    for(int ax = 0; ax < MAX; ax++) {
        if (strcmp(vetorPalavras[ax], resposta) == 0) {
            return 0;
        }
    }
    return 1;
}

int main () {
    int contaErro = 1;
    int contaAcerto = 0;
    int flag;
    char resposta[15];
    char vetorPalavras[MAX][15] = {
    "Bolacha", "Jato", "Rato", "Bota", "Brio", "Corte", "Caju", "Outra", "Oito", "Rio", "Trio", "Rua", "Tia", "Lua", "Rota", "Boia", "Taco", "Rico", "Bote", "Tijolo"
    };
    
    char vetorLetras[20] = {'A','B','C','D','A','E','I','O','U','D','B','J','R','T','U','J','B','T','L','L'};
    char vetorRespostas[MAX][15];
    imprime_anagrama(vetorLetras);
    do {
        cout<<"Nome: ";
        cin.getline(resposta, 15);
        flag = confere(vetorPalavras, resposta);
        if (flag == 0) {
            strcpy(vetorRespostas[contaAcerto], resposta);
            contaAcerto++;
        }
        else {
            contaErro++;
        }
    }while (contaErro < 6);
    for(int ax = 0; ax < contaAcerto; ax++) {
        cout<<vetorRespostas[ax]<<endl;
    }

    return 0;
}
