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
    char vetorPalavras[MAX][15] = {
    "Bolacha", "Jato", "Rato", "Bota", "Brio", "Corte", "Caju", "Outra", "Oito", "Rio", "Trio", "Rua", "Tia", "Lua", "Rota", "Boia", "Taco", "Rico", "Bote", "Tijolo"
    };

    char vetorLetras[20] = {'A','B','C','D','A','E','I','O','U','D','B','J','R','T','U','J','B','T','L','L'};
    char vetorRespostas[MAX][15];
    char resposta[15];
    int conta_erros = 0;
    int erro = 0;

    
    imprime_anagrama(vetorLetras);

    do
    {
        cout<<"\nDigite uma Palavra: ";
        cin.getline(resposta, 15);

        erro = confere(vetorPalavras, resposta);

        if(erro){
            conta_erros += 1;
            cout<<"\nErrou!";
        }else{
            cout<<"\nAcertou!";
        }

            
    } while ((conta_erros < 6) || (erro = 1));
    

}
