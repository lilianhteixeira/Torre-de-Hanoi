/* Praticas De Paradgimas De Linguagens De Programação
            Projeto Torre De Hanoi
                Grupo 3
        Victor Arruda Câmara Virgolino
        Lilian Honorio Teixeira
        Alex Micaela
        Bruno Meneses
*/

#include <iostream>
#include <stdio.h>

void inicializarJogo();
void printteste();
void resolucaoIA(int[], int[], int[], int);
void moveDisco(int[], int[], int);

int numeroDeDiscos;
int *esquerda;
int *meio;
int *direita;
int jogadas = 1;
int tamanho;


using namespace std;

int main(){
   int escolha = 0;
   numeroDeDiscos = 0;
    
    while(escolha != 1 && escolha != 2){
        cout << "---Torre De Hanoi---\n" <<
            "Escolhar uma opção:\n" <<
            "1 - Jogar Torre De Hanoi\n" <<
            "2 - IA Resolve\n";

    cin >> escolha;
    }
    if(escolha == 1 ){
        
        escolha = 0;
        while(escolha != 1 && escolha != 2 && escolha != 3){
            cout << "\nEscolha a Dificuldade:\n" << "1 - Facil (3 Discos)\n" << "2 - Medio(4 Discos)\n" << "3 - Dificil(5 Discos)\n";
            cin >> escolha;
            if(escolha == 1){
                numeroDeDiscos = 3;
            }
            else if(escolha == 2){
                numeroDeDiscos = 4;
            }
            else if(escolha == 3){
                numeroDeDiscos = 5;
            }
       }
        
        cout << "\n" << numeroDeDiscos << "\n";
        cout << escolha << "\n";
        inicializarJogo();
        



    }
    else if(escolha == 2){
       
       while(numeroDeDiscos < 3){
           cout << "Digite o Numero De Discos(Maior ou igual a 3):" << "\n";
           cin >> numeroDeDiscos;
       }
        cout << numeroDeDiscos << "\n";
        inicializarJogo();
        resolucaoIA(esquerda, meio, direita, numeroDeDiscos);
    
    }

   

    
    return 0;
}

void inicializarJogo(){
    int i = numeroDeDiscos;
    tamanho = numeroDeDiscos;

    esquerda = new int[numeroDeDiscos];
    meio = new int[numeroDeDiscos];
    direita = new int [numeroDeDiscos];
    for(int j = 0; j < numeroDeDiscos;j++){
        esquerda[j] = i;
        i--;
    }
}

void printteste(){
    cout << "Jogada: " << jogadas << "\n\n";
    jogadas++;
    for (int j = 0; j < numeroDeDiscos; j++){
        cout << esquerda[j] << "--";
    }
    cout << " Torre Esquerda \n";
    for (int j = 0; j < numeroDeDiscos; j++){
        cout << meio[j] << "--";
    }
    cout << " Torre Meio\n";
    for (int j = 0; j < numeroDeDiscos; j++){
        cout << direita[j] << "--";
    }
    cout << " Torre Direita\n\n";
}

void resolucaoIA(int origem[], int intermediario[], int destino[], int numeroDeDiscos){
    
    if(numeroDeDiscos == 1){
        moveDisco(origem, destino, numeroDeDiscos);
        printteste();
    }
    
    else{
        resolucaoIA(origem, destino, intermediario, numeroDeDiscos -1);
        moveDisco(origem, destino, numeroDeDiscos);
        printteste();
        resolucaoIA(intermediario, origem, destino, numeroDeDiscos-1);
    }

}

void moveDisco(int origem[], int destino[], int numeroDeDiscos){
    int disco = origem[tamanho - numeroDeDiscos];
    origem[tamanho - numeroDeDiscos] = 0;
    destino[numeroDeDiscos -1] = disco;
}
