#include <iostream>
#include <stdio.h>
#include <string.h>
#include <iomanip>
using namespace std;
#define MAX 30


void imprime_jogo(char *vetor_anagrama, char vetorRespostas[][15], int num_erros, int num_acertos){
    system("cls");
    for (int i = 0 ; i < 20 ; i++){
        cout<<vetor_anagrama[i]<<"   ";
        if ((i+1)%4 == 0){
            cout<<endl;
        }
    }
    cout<<"\nNumero de erros: "<<num_erros;
    cout<<"\nNumero de acertos: "<<num_acertos;
    cout<<"\n\nATENCAO!!!";
    cout<<"\nNao pode repetir palavras";
    cout<<"\nPara sair digite ENTER";
    if (num_acertos > 0) {
        cout<<"\n\n------------------------------";
        cout<<"\nPalavras ja acertadas: \n";
        for (int ax = 0; ax < num_acertos; ax++) {
            if (ax%6==0) {
                cout<<endl;
            }
            cout<<vetorRespostas[ax]<<" ";
        }
        cout<<"\n--------------------------------\n";
    }
};

void maiuscula(char *resposta, int tamanho) {
    for (int ax = 0; ax < tamanho; ax++) {
        resposta[ax] = toupper(resposta[ax]);
    }
}

int valida(char resposta[15], int *contaErros, int tamanho) {
    int error = 0;
    for (int ax = 0; ax < tamanho; ax++) {
        if (resposta[ax] < 'A' || resposta[ax]  > 'Z') {
            error = 1;
        }
    }
    if (error == 1) {
        (*contaErros)++;
        return 0;
    }
    else {
        return 1;
    }
}
void verifica(char vetorPalavras[][15], char Respostas[15], char vetorRespostas[][15], int *contaErros, int *contaAcertos) {
    int encontrada = 0;
    for (int ax = 0; ax < MAX; ax++) {
        if (strcmp(vetorPalavras[ax], Respostas) == 0) {
            encontrada = 1;
            break;
        }
    }
    if (encontrada == 0) {
        (*contaErros)++;
    } else {
        int repetida = 0;
        for (int ax2 = 0; ax2 < *contaAcertos; ax2++) {
            if (strcmp(vetorRespostas[ax2], Respostas) == 0) {
                repetida = 1;
                break;
            }
        }
        if (repetida == 0) {
            strcpy(vetorRespostas[*contaAcertos], Respostas);
            (*contaAcertos)++;
        } else {
            (*contaErros)++;
        }
    }
}

void imprimeBanco (char vetorPalavras[][15]) {
    cout<<endl;
    cout<<"Banco de palavras\n";
    for(int ax = 0; ax < 20; ax++) {
        if(ax%5==0) {
            cout<<endl;
        }
            cout<<vetorPalavras[ax]<<" ";
    }
}
int main () {
    int contaErro = 0;
    int contaAcerto = 0;
    int flag;
    char resposta[15];
    char vetorPalavras[MAX][15] = {
    "BOLACHA", "JATO", "RATO", "BOTA", "BRIO", "CORTE", "CAJU", "OUTRA", "OITO", "RIO", "TRIO", "RUA", "TIA", "LUA", "ROTA", "BOIA", "TACO", "RICO", "BOTE", "TIJOLO"
    };
    
    char vetorLetras[20] = {'A','B','C','D','A','E','I','O','U','D','B','J','R','T','U','J','B','T','L','L'};
    char vetorRespostas[MAX][15];
    char bancoPalavras;
    do {
        imprime_jogo(vetorLetras, vetorRespostas, contaErro, contaAcerto);
        cout << "\n\nPalavra: ";
        cin.getline(resposta, 15);
        maiuscula(resposta, strlen(resposta));
        if (strcmp(resposta, "ENTER")==0) {
            break;
        }
        flag = valida(resposta, &contaErro, strlen(resposta));
        if (flag == 1) {
            verifica(vetorPalavras, resposta, vetorRespostas, &contaErro, &contaAcerto);
        }
    } while (contaErro < 5);
    system("pause");
    system("cls");
    do {
        cout<<"Deseja ver oo banco de palavras: (S|N) \n";
        cin>>bancoPalavras;
        bancoPalavras = toupper(bancoPalavras);
    }while(bancoPalavras != 'S' && bancoPalavras != 'N');
    if (bancoPalavras == 'S') {
        imprimeBanco(vetorPalavras);
        cout<<endl;
    }
}