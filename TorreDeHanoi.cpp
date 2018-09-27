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
using namespace std;

struct Haste{
	int pilha[5];
	int topo;
	
	void novaHaste(int size) {
	    //pilha=(int*)malloc( size * sizeof(int));
	    topo = -1;
	}
	bool isEmpty() {
		return topo == -1;
	}
	
	int get(int indice) {
		return pilha[indice];
	}
	
	int len() {
		return (sizeof(pilha) / sizeof(int));
	}
	
	bool isFull() {
		return topo == len() - 1;
	}
	
	int top() {
		if (!isEmpty()) {
			return pilha[topo];
		}
		return -1;
	}
	
	void push(int element) {
		if (!isFull()) {
				if (isEmpty()) {
					topo = topo + 1;
					pilha[topo] = element;
					
				} else if (top() > element) {
					topo = topo + 1;
					pilha[topo] = element;
				}
				
		}
	}
	
	void toString() {
		for (int i = 0; i < 5; i++){
			cout << pilha[i] << "--";
    	}
	}
	
	int pop() {
		int element = top();
		
		if (element != -1) {
			pilha[topo] = 0;
			topo = topo - 1;
		}
		return element;
	}
	
	void preencheHaste(int qtdDiscos) {
		for(int i = qtdDiscos; i > 0; i--) {
			push(i);
		}
	}
	
	void moveDisco(Haste *destino) {
		destino->push(pop());
	}
	
} esquerda, meio, direita;

void inicializarJogo();
void printteste();
void resolucaoIA(Haste*, Haste*, Haste*, int);

int numeroDeDiscos;
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
        resolucaoIA(&esquerda, &meio, &direita, numeroDeDiscos);
    
    }

   

    
    return 0;
}

void inicializarJogo(){
    tamanho = numeroDeDiscos;

    esquerda.novaHaste(tamanho);
    meio.novaHaste(tamanho);
    direita.novaHaste(tamanho);

	esquerda.preencheHaste(numeroDeDiscos);
}

void printteste(){
    cout << "Jogada: " << jogadas << "\n\n";
    jogadas++;
    for (int j = 0; j < numeroDeDiscos; j++){
        cout << esquerda.get(j) << "--";
    }
    cout << " Torre Esquerda \n";
    for (int j = 0; j < numeroDeDiscos; j++){
        cout << meio.get(j) << "--";
    }
    cout << " Torre Meio\n";
    for (int j = 0; j < numeroDeDiscos; j++){
        cout << direita.get(j) << "--";
    }
    cout << " Torre Direita\n\n";
}

void resolucaoIA(Haste *origem, Haste *intermediario, Haste *destino, int numeroDeDiscos){
    
    if(numeroDeDiscos == 1){
        origem->moveDisco(destino);
        printteste();
    }
    
    else{
        resolucaoIA(origem, destino, intermediario, numeroDeDiscos -1);
        origem->moveDisco(destino);
        printteste();
        resolucaoIA(intermediario, origem, destino, numeroDeDiscos-1);
    }

}
