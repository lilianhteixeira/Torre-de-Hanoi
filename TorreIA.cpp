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
	int *pilha;
	int topo;
    int numerodiscos;
	
	void novaHaste(int size) {
	    pilha = new int[size];
	    topo = -1;
        numerodiscos = size;//AQUI!!
        zerarArray();

	}

    void zerarArray(){

		for (int i = 0; i < numerodiscos - 1; i++) {

			pilha[i] = 0;

		}

	}

	bool isEmpty() {
		return topo == -1;
	}
	
	int get(int indice) {
		return pilha[indice];
	}
	
	int len() {
		return numerodiscos;//AQUI!!
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
				if(isEmpty()){
                    topo++;
                    pilha[topo] = element;
                }
                else if(top() < element){
                    cout << "Movimento invalido";//AQUI
                }
				else {
					topo++;
					pilha[topo] = element;
				}
				
		}
	}
	
	void toString() {
		for (int i = 0; i < len(); i++){
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
		for(int i = qtdDiscos; i >= 1; i--) {
			push(i);
		}
	}
	
	void moveDisco(Haste *destino) {
		destino->push(pop());
	}
	
} esquerda, meio, direita;

void inicializarJogo();
void constroitorre();
void resolucaoIA(Haste*, Haste*, Haste*, int);
string insereQTD(int, string);

int numeroDeDiscos;
int jogadas = 0;
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

        while(!direita.isFull()){

        }
        



    }
    else if(escolha == 2){
       
       while(numeroDeDiscos < 3){
           cout << "Digite o Numero De Discos(Maior ou igual a 3):" << "\n";
           cin >> numeroDeDiscos;
       }
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
    constroitorre();
}

void constroitorre(){
    
    cout << "Jogada: " << jogadas << "\n\n";
    jogadas++;

    for (int i = (numeroDeDiscos); i >= 0; i--) {

		string linha = "";

		//HASTE ESQUERDA

		if (esquerda.get(i) != 0) {
			int qtdEspacos = (numeroDeDiscos - esquerda.get(i));
			linha = linha + insereQTD(qtdEspacos, " ") + "[" + insereQTD(esquerda.get(i) * 2, "_") + "]" + insereQTD(qtdEspacos, " ");
		} else {
			linha = linha + insereQTD(numeroDeDiscos, " ") + "||" + insereQTD(numeroDeDiscos, " ");
		}

		//HASTE CENTRAL

		if (meio.get(i) != 0) {
			int qtdEspacos = (numeroDeDiscos - meio.get(i));
			linha = linha + insereQTD(qtdEspacos, " ") + "[" + insereQTD(meio.get(i) * 2, "_") + "]" + insereQTD(qtdEspacos, " ");
		} else {
			linha = linha + insereQTD(numeroDeDiscos, " ") + "||" + insereQTD(numeroDeDiscos, " ");
		}

		//HASTE DIREITA

		if (direita.get(i) != 0) {
			int qtdEspacos = (numeroDeDiscos - direita.get(i));
			linha = linha + insereQTD(qtdEspacos, " ") + "[" + insereQTD(direita.get(i) * 2, "_") + "]" + insereQTD(qtdEspacos, " ");
		} else {
			linha = linha + insereQTD(numeroDeDiscos, " ") + "||" + insereQTD(numeroDeDiscos, " ");
		}

		cout << linha << endl;
        
    }
    cout << "\n";
}

void resolucaoIA(Haste *origem, Haste *intermediario, Haste *destino, int numeroDeDiscos) {
    
    if(numeroDeDiscos == 1){
        origem->moveDisco(destino);
        constroitorre();
    }
    
    else{
        resolucaoIA(origem, destino, intermediario, numeroDeDiscos -1);
        origem->moveDisco(destino);
        constroitorre();
        resolucaoIA(intermediario, origem, destino, numeroDeDiscos-1);
    }

}

string insereQTD(int qtd, string simbolo) {

	string resp = "";

	for (int i= 0; i < qtd; i++) {

		resp += simbolo;

	}

	return resp;

}