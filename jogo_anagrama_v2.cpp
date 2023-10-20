#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MAX 20

void imprime_anagrama(char *vetor_anagrama, int max){
    cout<<"\nANAGRAMA:\n";
    for (int i=0 ; i<max ; i++){
        cout<<"  ";  
        cout<<vetor_anagrama[i];
        if((i+1)%4 == 0){
            cout<<endl;
        }
    }
};

void insere_palavra_correta(char v_corretas[][15] , char palavra[15], int pos){
    strcpy(v_corretas[pos], palavra);
};

int verifica_palavra(char vetor_palavras[][15], char palavra[15], char v_corretas[][15], int contador){
    int inserir;

    for (int i=0 ; i<MAX ; i++){
        inserir = 1;

        if(strcmp(vetor_palavras[i], palavra) == 0){

            for (int j=0 ; j<contador ; j++){
                if(strcmp(v_corretas[j], palavra) == 0){
                    cout<<"\nVoce ja encontrou essa palavra...";
                    inserir = 0;
                }
            }

            if (inserir == 1){
                cout<<"\nPalavra Encontrada!";
                strcpy(v_corretas[contador], palavra);
                return 1;
            }
        }
    }
    cout<<"\nPalavra nao encontrada!";
    return 0;
};

void imprime_palavras(char v_corretas[][15], int quantidade){
    for (int i = 0 ; i<quantidade ; i++){
    cout<<v_corretas[i]<<"    ";
    if((i+1)%4 == 0){
        cout<<endl;
        }
    }
}

void imprime_score(int acertos, int erros){
    cout<<"\n>>>>Acertos: "<<acertos;
    cout<<"\n>>>>Erros: "<<erros;
}

int main(){
    char vetorLetras[20] = {'A','B','C','D','A','E','I','O','U','D','B','J','R','T','U','J','B','T','L','L'};
    char vetorPalavras[MAX][15] = {
    "Bolacha", "Jato", "Rato", "Bota", "Beijo", "Corte", "Caju", "Outra", "Oito", "Rio", "Tatu", "Rua", "Tia", "Lua", "Dado", "Boia", "Dia", "Rico", "Bola", "Tijolo"
    };
    char vetorPalavrasCorretas[MAX][15];
    char palavra[15];
    int teste = 0;
    int contador_acertos = 0, contador_erros = 0;
    int ver_banco;
    
    
    do
    {
        imprime_anagrama(vetorLetras, MAX);

        if (contador_acertos > 0 || contador_erros > 0){
            imprime_score(contador_acertos, contador_erros);
            cout<<endl;
        }

        if(contador_acertos > 0){
            cout<<"\n --- Palavras Encontradas --- \n";
            imprime_palavras(vetorPalavrasCorretas,contador_acertos);
            cout<<endl;
        }

        cout<<"\nDigite uma palavra: ";cin.getline(palavra, 15);
        teste = verifica_palavra(vetorPalavras, palavra, vetorPalavrasCorretas, contador_acertos);
        //cout<<"\nTESTE: "<<teste;
        if(teste){
            contador_acertos++;
        }else{
            contador_erros++;
        }

        cout<<endl;
        system("pause");
        system("cls");
        
    } while (contador_erros < 5);


    cout<<"\nLISTA DE ACERTOS:\n\n";
    imprime_palavras(vetorPalavrasCorretas,contador_acertos);

    cout<<"\nGostaria de ver o banco de palavras?(1 = sim |0 = nao): ";
    cin>>ver_banco;
    if(ver_banco){
        cout<<"\nPALAVRAS:\n";
        imprime_palavras(vetorPalavras, MAX);
    }

    return 0;
}