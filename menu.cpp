/*
Vinicius Mendes da Cunha - 23015801
Tiago Pereira da Silva - 23012171
*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <iomanip>
using namespace std;
#define MAX 30


void imprime_jogo(char *vetor_anagrama, char vetorRespostas[][15], int num_erros, int num_acertos,int dif_acertos, int dif_erros, char dificuldade[]){
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
    cout<<"\n\nEste e o modo "<<dificuldade<<", voce precisa acertar "<<dif_acertos-num_acertos<<" palavras para ganhar !";
    cout<<"\nVoce pode errar "<<dif_erros-num_erros<<" vezes";
    cout<<"\nNao pode repetir palavras";
    cout<<"\nPara sair precione 'Enter' ";
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

void jogo (char dificuldade[], int dif_erros, int dif_acertos) {
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
        imprime_jogo(vetorLetras, vetorRespostas, contaErro, contaAcerto, dif_acertos, dif_erros, dificuldade);
        cout << "\n\nPalavra: ";
        cin.getline(resposta, 15);
        maiuscula(resposta, strlen(resposta));
        if (strcmp(resposta,"")==0) {
            break;
        }
        flag = valida(resposta, &contaErro, strlen(resposta));
        if (flag == 1) {
            verifica(vetorPalavras, resposta, vetorRespostas, &contaErro, &contaAcerto);
        }
    } while (contaErro < dif_erros && contaAcerto < dif_acertos);
    system("cls");
    if(contaAcerto == dif_acertos) {
        cout<<"Parabens voce ganhou :) ";
    }
    else {
        cout<<"Nao foi desta vez :( ";
    }
    do {
        cout<<"\nDeseja ver oo banco de palavras: (S|N) \n";
        cin>>bancoPalavras;
        bancoPalavras = toupper(bancoPalavras);
    }while(bancoPalavras != 'S' && bancoPalavras != 'N');
    if (bancoPalavras == 'S') {
        imprimeBanco(vetorPalavras);
        cout<<endl<<endl;
        system("pause");
    }
}

int menu(){
    int opcao;

    cout<<"1-Facil";
    cout<<"\n2-Medio";
    cout<<"\n3-Dificil";
    cout<<"\n4-Sair";
    cout<<"\n\nPor favor escolha uma das opcoes: ";
    cin>>opcao;
    cin.ignore();

    return opcao;
}

int main() {
    int opcao;
    int dif_erros;
    int dif_acertos;
    char dificuldade[15];

    system("cls");
    cout<<"Seja bem vindo ao ANAGRAMA PUC jogo desenvolvido por Vinicius Mendes e Tiago pereira ";
    cout<<"\n\n";
    system("pause");
    do {
        system("cls");
        opcao = menu();
        switch (opcao)
        {
        case 1:dif_erros = 8;
            dif_acertos = 5;
            strcpy(dificuldade, "facil");
            jogo(dificuldade, dif_erros, dif_acertos);
            break;
        case 2:dif_erros = 7;
            dif_acertos = 10;
            strcpy(dificuldade, "medio");
            jogo(dificuldade, dif_erros, dif_acertos);
            break;
        case 3:dif_erros = 5;
            dif_acertos = 15;
            strcpy(dificuldade, "dificil");
            jogo(dificuldade, dif_erros, dif_acertos);
            break;
        case 4: cout<<"\n\nObrigado por jogar o jogo!!";
        }
    } while (opcao != 4);
    return 0;
}