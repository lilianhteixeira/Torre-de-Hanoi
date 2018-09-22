/* Praticas De Paradgimas De Linguagens De Programação
            Projeto Torre De Hanoi
                Grupo 3
        Victor Arruda Câmara Virgolino
        Lilian Honorio Teixeira
        Alex Micaela
        Jailson Ramos Campos
*/

#include <iostream>

void inicializarJogo(int[], int);

using namespace std;

int main(){
    int numeroDeDiscos = 0;
    int escolha = 0;
    
    while(escolha != 1 && escolha != 2){
        cout << "---Torre De Hanoi---\n" <<
            "Escolhar uma opção:\n" <<
            "1 - Jogar Torre De Hanoi\n" <<
            "2 - IA Resolve\n";

    cin >> escolha;
    }
    if(escolha == 1 ){
       while(numeroDeDiscos < 3){
            cout << "\nDigite o numero de discos(maior ou igual a 3):\n";
            cin >> numeroDeDiscos;
       }
    
        int esquerda[numeroDeDiscos] = {};
        int meio[numeroDeDiscos] = {};
        int direita[numeroDeDiscos] = {};
        inicializarJogo(esquerda, numeroDeDiscos);



    }
    else if(escolha == 2){

    }
    
    return 0;
}

void inicializarJogo(int esquerda[], int numeroDeDiscos){
    int i = numeroDeDiscos;
    for(int j = 0; j < numeroDeDiscos;j++){
        esquerda[j] = i;
        i--;
    }


}

