/* Praticas De Paradgimas De Linguagens De Programação
            Projeto Torre De Hanoi
                Grupo 3

        Alex Micaela
        Bruno Meneses
        Lílian Honorio Teixeira
        Victor Arruda Câmara Virgolino
		
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef _WIN32
#define CLEAR "clear"
#else
#define CLEAR "cls"
#endif

using namespace std;

int numeroDeDiscos;
int jogadas;
int tamanho;
bool iniciado;
int historico;
int etapa;
int nivelDeDificuldade;
int opcao;

struct Haste
{
	int *pilha;
	int topo;
	int numerodiscos;

	void novaHaste(int size)
	{
		pilha = new int[size + 1]; //AQUI!!
		topo = -1;
		numerodiscos = size;//AQUI!!
		zerarArray();

	}

	void zerarArray()
	{
		for (int i = 0; i < numerodiscos + 1; i++)
		{
			pilha[i] = 0;
		}
	}

	bool isEmpty()
	{
		return topo == -1;
	}

	int get(int indice)
	{
		return pilha[indice];
	}

	int len()
	{
		return numerodiscos;//AQUI!!
	}



	bool isFull()
	{
		return topo == len() - 1;
	}

	int top()
	{
		if (!isEmpty())
		{
			return pilha[topo];
		}
		return -1;
	}

	void push(int element)
	{
		if (!isFull())
		{
			if(isEmpty())
			{
				topo++;
				pilha[topo] = element;
			}
			else
			{
				topo++;
				pilha[topo] = element;
			}

		}
	}

	void toString()
	{
		for (int i = 0; i < len(); i++)
		{
			cout << pilha[i] << "--";
		}
	}

	int pop()
	{
		int element = top();

		if (element != -1)
		{
			pilha[topo] = 0;
			topo = topo - 1;
		}
		return element;
	}

	void preencheHaste(int qtdDiscos)
	{
		for(int i = qtdDiscos; i >= 1; i--)
		{
			push(i);
		}
	}

	void moveDisco(Haste *destino)

	{
		if(topo == -1)
		{

			cout << "Jogada Invalida\n";

			jogadas--;
		}

		else
		{
			if(destino->isEmpty())

			{
				destino->push(pop());

			}

			else if(destino->top() > top())

			{
				destino->push(pop());

			}

			else

			{
				cout << "Jogada Invalida\n";

				jogadas--;

			}
		}
	}

} esquerda, meio, direita;

void inicializarJogo();
void constroitorre();
void resolucaoIA(Haste*, Haste*, Haste*, int);
string insereQTD(int, string);
void limparTela();
void pausar();
void mostrarMenu(Haste*, Haste*, Haste*);
void regrasDoJogo();

void resetaVariaveis()
{
	numeroDeDiscos = 0;
	tamanho = 0;
	iniciado = false;
	historico = 0;
	etapa = 0;
	nivelDeDificuldade = 0;
	opcao = 1;
}

int main()
{

	setlocale(LC_ALL, "Portuguese");//nao esta habilitando a acentuacao
	do
	{
		resetaVariaveis();
		printf("---Torre De Hanoi---\n Escolhar uma opcao:\n 1 - Jogar Torre De Hanoi\n 2 - IA Resolve\n 3 - Regras do jogo\n 4 - Sair\n  - DIGITE: ");
		scanf("%d", &opcao);
		switch(opcao)
		{
		case 1:
			limparTela();
			printf("\nEscolha qual sera a dificuldade: \n 1 - Facil(3 discos)\n 2 - Medio(4 discos)\n 3 - Dificil(5 discos)\n");
			scanf("%d", &nivelDeDificuldade);

			if(nivelDeDificuldade == 1)
			{
				numeroDeDiscos = 3;
			}
			else if(nivelDeDificuldade == 2)
			{
				numeroDeDiscos = 4;
			}
			else if(nivelDeDificuldade == 3)
			{
				numeroDeDiscos = 5;
			}
			limparTela();
			inicializarJogo();
			mostrarMenu(&esquerda, &meio, &direita);
			break;

		case 2:
			limparTela();
			while(numeroDeDiscos < 3)
			{
				cout << "Digite o numero de discos(Maior ou igual a 3):" << "\n> ";
				cin >> numeroDeDiscos;
			}
			limparTela();
			cout << "Exibir por etapa? \n" << "1 - Sim  |" <<  " 2 - Nao\n> ";
			cin >> etapa;

			limparTela();
			inicializarJogo();
			resolucaoIA(&esquerda, &meio, &direita, numeroDeDiscos);

			if (etapa == 1)
			{
				limparTela();
				cout << "\nExibir historico?\n" << "1 - Sim  |" <<  " 2 - Nao\n> ";
				cin >> historico;
				limparTela();
				if (historico == 1)
				{
					cout << "\n--Historico de Movimentos---\n\n";
					inicializarJogo();
					resolucaoIA(&esquerda, &meio, &direita, numeroDeDiscos);
				}
			}
			if (historico != 2) {
				pausar();	
			}
			limparTela();


			break;
		case 3:
			regrasDoJogo();
			break;

		case 4:
			exit(0);

		default:
			if(opcao != 0)
			{
				printf(" - Opcao invalida, por favor informe uma opcao valida.\n - ");
				pausar();
				limparTela();
			}
			else
			{
				limparTela();
				printf("\n\n\t\t\t  Jogo encerrado com sucesso.\n");
			}
			break;
		}

	}
	while(opcao != 0);

	return 0;
}

void inicializarJogo()
{
	jogadas = 0;
	tamanho = numeroDeDiscos;

	esquerda.novaHaste(tamanho);
	meio.novaHaste(tamanho);
	direita.novaHaste(tamanho);
	esquerda.preencheHaste(numeroDeDiscos);
	constroitorre();
	iniciado = true;
}

void limparTela()
{
	system(CLEAR);
}

void pausar()
{
	cout << "\n\nPressione qualquer tecla para continuar...";
	fflush(stdin);
	getchar();
}

void constroitorre()  //impressao da torre
{

	if (historico == 0 && etapa == 1)
	{
		limparTela();
	}

	if (jogadas >= 1)
	{
		cout << "Movimento: " << jogadas << "\n\n";
	}
	else
	{
		cout << "Inicio" << "\n\n";
	}
	jogadas++;

	for (int i = numeroDeDiscos; i >= 0; i--)
	{

		string linha = "";

		//HASTE ESQUERDA

		if (esquerda.get(i) != 0)
		{
			int qtdEspacos = (numeroDeDiscos - esquerda.get(i));
			linha = linha + insereQTD(qtdEspacos, " ") + "(" + insereQTD(esquerda.get(i) * 2, "_") + ")" + insereQTD(qtdEspacos, " ");
		}
		else
		{
			linha = linha + insereQTD(numeroDeDiscos, " ") + "||" + insereQTD(numeroDeDiscos, " ");
		}

		//HASTE CENTRAL

		if (meio.get(i) != 0)
		{
			int qtdEspacos = (numeroDeDiscos - meio.get(i));
			linha = linha + insereQTD(qtdEspacos, " ") + "(" + insereQTD(meio.get(i) * 2, "_") + ")" + insereQTD(qtdEspacos, " ");
		}
		else
		{
			linha = linha + insereQTD(numeroDeDiscos, " ") + "||" + insereQTD(numeroDeDiscos, " ");
		}

		//HASTE DIREITA

		if (direita.get(i) != 0)
		{
			int qtdEspacos = (numeroDeDiscos - direita.get(i));
			linha = linha + insereQTD(qtdEspacos, " ") + "(" + insereQTD(direita.get(i) * 2, "_") + ")" + insereQTD(qtdEspacos, " ");
		}
		else
		{
			linha = linha + insereQTD(numeroDeDiscos, " ") + "||" + insereQTD(numeroDeDiscos, " ");
		}
		

		cout << linha << endl;

	}
	
	if (historico == 0 && etapa == 1)
	{
		pausar();
	}
	cout << "\n";
}

void mostrarMenu(Haste *esquerda, Haste *meio, Haste *direita)
{
	int saida, chegada, test = 0, aux;
	do
	{
		// VERIFICA SE GANHOU!
		if(direita->isFull())
		{
			aux = pow(2, numeroDeDiscos) - 1;
			jogadas--;
			if(jogadas == aux)
			{
				printf("\nParabens, voce ganhou e sua pontuacao foi excelente %d de %d.\n", jogadas, aux);
			}
			else if(jogadas > aux && jogadas < aux + 5)
			{
				printf("\nParabens, voce ganhou mas sua pontuacao foi abaixo da media %d de %d.\n", jogadas, aux);
			}
			else
			{
				printf("\nParabens, voce ganhou mas sua pontuacao foi ruim: %d de %d.\n", jogadas, aux);
			}
			printf("\n\n Jogo encerrado com sucesso.\n");
			pausar();
			limparTela();
			break;
		}
		printf("Informe qual a torre de origem (1 a 3): ");
		scanf("%d", &saida);
		do
		{
			if(saida < 1 || saida > 3)
			{
				printf(" - Torre de origem nao corresponde, informe corretamente.\nInforme qual a torre de origem (1 a 3): ");
				scanf("%d", &saida);
			}
		}
		while(saida < 1 || saida > 3);
		printf("Informe qual a torre de destino (1 a 3): ");
		scanf("%d", &chegada);
		do
		{
			if(chegada < 1 || chegada > 3)
			{
				printf(" - Torre de destino nao corresponde, informe corretamente.\nInforme qual a torre de destino (1 a 3): ");
				scanf("%d", &chegada);
			}
			if(chegada == saida)
			{
				printf(" - O destino nao pode ser igual a torre de origem.\nInforme qual a torre de destino (1 a 3): ");
				scanf("%d", &chegada);
			}
		}
		while(chegada < 1 || chegada > 3 || chegada == saida);

		if(saida == 1)
		{
			if(chegada == 2)
			{
				esquerda->moveDisco(meio);
			}
			else if(chegada == 3)
			{
				esquerda->moveDisco(direita);
			}
		}
		else if(saida == 2)
		{
			if(chegada == 1)
			{
				meio->moveDisco(esquerda);
			}
			else if(chegada == 3)
			{
				meio->moveDisco(direita);
			}
		}
		else if(saida == 3)
		{
			if(chegada == 1)
			{
				direita->moveDisco(esquerda);
			}
			else if(chegada == 2)
			{
				direita->moveDisco(meio);
			}
		}
		limparTela();
		constroitorre();
	}
	while(test != 1);
}


void resolucaoIA(Haste *origem, Haste *intermediario, Haste *destino, int numeroDeDiscos)
{
	if(numeroDeDiscos == 1)
	{
		origem->moveDisco(destino);
		constroitorre();
	}

	else
	{
		resolucaoIA(origem, destino, intermediario, numeroDeDiscos - 1);
		origem->moveDisco(destino);
		constroitorre();
		resolucaoIA(intermediario, origem, destino, numeroDeDiscos - 1);
	}
}


string insereQTD(int qtd, string simbolo)
{

	string resp = "";

	for (int i = 0; i < qtd; i++)
	{

		resp += simbolo;

	}

	return resp;
}

void regrasDoJogo()
{
	limparTela();
	printf(" - Torre de Hanoi:\n");
	printf("   O objetivo deste jogo, consiste em deslocar todos os discos da primeira haste para a ultima haste.\n");
	printf("   Respeitando as seguintes regras:\n\n");
	printf("    1 - Deslocar um disco de cada vez, o qual devera ser o do topo de uma das tres hastes.\n\n");
	printf("    2 - Cada disco nunca podera ser colocado sobre outro de tamanho menor.\n\n ");
	pausar();
	limparTela();
}
