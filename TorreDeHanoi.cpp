#include <stdio.h>
#include <stdlib.h>
#include <math.h> // usa a função pow();, para calcular o valor minimo de movimentos para resolver a torre de hanoi;
#include <locale.h>

int nivelDeDificuldade;
int numeroDeDiscos;

int torre1[3]= {1,2,3}, torre2[3]={0,0,0}, torre3[3] ={0,0,0};
//int torre14[4]= {1,2,3,4}, torre24[3]={0,0,0,0}, torre34[3] ={0,0,0,0};
//int torre15[5]= {1,2,3,4,5}, torre25[5]={0,0,0,0,0}, torre35[5] ={0,0,0,0,0};// criar um para cada opção

int numeroDeJogadas = 0; 

void mostrarTorres(); 

int valorTorre(int torre[3]); 

int destinoTorre(int torre[3]);

void moverDiscos(int orig, int dest); 

void mostrarMenu(); 

int verificarFinal(); 

void regrasDoJogo();

int main(void){

  setlocale(LC_ALL, "Portuguese");//nao esta habilitando a acentuacao

  int opcao = 1;
  while(opcao!=0){
    printf("---Torre De Hanoi---\n Escolhar uma opção:\n 1 - Jogar Torre De Hanoi\n 2 - IA Resolve\n 3 - Regras do jogo\n 4 - Sair\n  - DIGITE: ");
    scanf("%d", &opcao);
    switch(opcao){
      case 1:
          printf("\nEscolha qual será a dificuldade: \n 1 - Fácil(3 discos)\n 2 - Médio(4 discos)\n 3 - Dificil(5 discos)\n");
          scanf("%d", &nivelDeDificuldade);

          if(nivelDeDificuldade == 1){
            numeroDeDiscos = 3;
          } else if(nivelDeDificuldade == 2){
            numeroDeDiscos = 4;
          } else if(nivelDeDificuldade == 3){
            numeroDeDiscos = 5;
          }

          mostrarTorres();
          mostrarMenu();
          break;
      case 3:
          regrasDoJogo();
          break;
      default:
          if(opcao != 0){
            printf(" - Opção inválida, por favor informe uma opcao válida.\n - ");
            system("PAUSE");
            system("CLS");
          }else{
            system("CLS");
            printf("\n\n\t\t\t  Jogo encerrado com sucesso.\n");
          }   
          break;
    }
  }
  return 0;
}


int valorTorre(int torre[]){ 
  int i, a=0, auxiliar= 2;

  if(numeroDeDiscos == 4){
    torre[4];
    auxiliar = 3;
  }else if(numeroDeDiscos == 5){
    torre[5];
    auxiliar = 4;
  }

  for(i=numeroDeDiscos-1; i>=0; i--){
    if(torre[i] != 0){
      a = i;
    }
    if(torre[auxiliar] == 0){
      a = 0;
    }
  }
  return(a);
}


int destinoTorre(int torre[]){ 
  int i, a=0;

  if(numeroDeDiscos == 4){
    torre[4];
  }else if(numeroDeDiscos == 5){
    torre[5];
  }

  for(i=0; i<numeroDeDiscos; i++){
    if(torre[i] == 0){
      a = i;
    }
  }
  return(a);
}


void moverDiscos(int origem, int destino){ 
  int aux1, aux2, aux3;
  
  if(numeroDeDiscos == 4){
    int torre1[4]= {1,2,3,4}, torre2[4]={0,0,0,0}, torre3[4] ={0,0,0,0};
  }else if(numeroDeDiscos == 5){
    int torre1[5]= {1,2,3,4,5}, torre2[5]={0,0,0,0,0}, torre3[5] ={0,0,0,0,0};
  }  


  // ORIGEM 1 - TORRE 1
  if(origem == 1){
    // DESTINO 2 - TORRE 2  
    if(destino == 2){
      aux1 = torre1[valorTorre(torre1)];
      aux2 = torre2[destinoTorre(torre2)+1] ;
      aux3 = torre2[valorTorre(torre2)];
      if(aux3 < aux1 && aux3 != 0){
        printf("Disco da origem [%d] é maior que o disco de destino [%d]\n", aux1, aux3);
        system("PAUSE");
      }else{
        if(aux1 == 0){
          printf("Sem discos na torre de origem.\n");
          system("PAUSE");        
        }else{
          torre1[valorTorre(torre1)] = 0;
          torre2[destinoTorre(torre2)] = aux1;
          numeroDeJogadas++;
        }
      }
    // DESTINO 3 - TORRE 3
    }else{
      aux1 = torre1[valorTorre(torre1)];
      aux2 = torre3[destinoTorre(torre3)+1] ;
      aux3 = torre3[valorTorre(torre3)];
      if(aux3 < aux1 && aux3 != 0){
        printf("Disco da origem [%d] é maior que o disco de destino [%d]\n", aux1, aux3);
        system("PAUSE");
      }else{
        if(aux1 == 0){
          printf("Sem discos na torre de origem.\n");
          system("PAUSE");        
        }else{
          torre1[valorTorre(torre1)] = 0;
          torre3[destinoTorre(torre3)] = aux1;
          numeroDeJogadas++;
        }
      }
    }     
  }
  
  // ORIGEM 2 - TORRE 2
  if(origem == 2){
    // DESTINO 1 - TORRE 1
    if(destino == 1){
      aux1 = torre2[valorTorre(torre2)];
      aux2 = torre1[destinoTorre(torre1)+1] ;
      aux3 = torre1[valorTorre(torre1)];
      if(aux3 < aux1 && aux3 != 0){
        printf("Disco da origem [%d] é maior que o disco de destino [%d]\n", aux1, aux3);
        system("PAUSE");
      }else{
        if(aux1 == 0){
          printf("Sem discos na torre de origem.\n");
          system("PAUSE");        
        }else{
          torre2[valorTorre(torre2)] = 0;
          torre1[destinoTorre(torre1)] = aux1;
          numeroDeJogadas++;
        }
      }
    // DESTINO 3 - TORRE 3
    }else{
      aux1 = torre2[valorTorre(torre2)];
      aux2 = torre3[destinoTorre(torre3)+1] ;
      aux3 = torre3[valorTorre(torre3)];
      if(aux3 < aux1 && aux3 != 0){
        printf("Disco da origem [%d] é maior que o disco de destino [%d]\n", aux1, aux3);
        system("PAUSE");
      }else{
        if(aux1 == 0){
          printf("Sem discos na torre de origem.\n");
          system("PAUSE");        
        }else{
          torre2[valorTorre(torre2)] = 0;
          torre3[destinoTorre(torre3)] = aux1;
          numeroDeJogadas++;         
        }
      }
    } 
  }
  
  // ORIGEM 3 - TORRE 3
  if(origem == 3){
    // DESTINO 1 - TORRE 1
    if(destino == 1){
      aux1 = torre3[valorTorre(torre3)];
      aux2 = torre1[destinoTorre(torre1)+1] ;
      aux3 = torre1[valorTorre(torre1)];
      if(aux3 < aux1 && aux3 != 0){
        printf("Disco da origem [%d] é maior que o disco de destino [%d]\n", aux1, aux3);
        system("PAUSE");
      }else{
        if(aux1 == 0){
          printf("Sem discos na torre de origem.\n");
          system("PAUSE");        
        }else{
          torre3[valorTorre(torre3)] = 0;
          torre1[destinoTorre(torre1)] = aux1;
          numeroDeJogadas++;       
        }   
      }
    // DESTINO 2 - TORRE 2
    }else{
      aux1 = torre3[valorTorre(torre3)];
      aux2 = torre2[destinoTorre(torre2)+1] ;
      aux3 = torre2[valorTorre(torre2)];
      if(aux3 < aux1 && aux3 != 0){
        printf("Disco da origem [%d] é maior que o disco de destino [%d]\n", aux1, aux3);
        system("PAUSE");
      }else{
        if(aux1 == 0){
          printf("Sem discos na torre de origem.\n");
          system("PAUSE");        
        }else{
          torre3[valorTorre(torre3)] = 0;
          torre2[destinoTorre(torre2)] = aux1;
          numeroDeJogadas++;
        }
      }
    } 
  } 
  mostrarTorres();
}


void mostrarMenu(){
  int origem, destino, test=0, aux;
  do{
    // VERIFICA SE GANHOU!
    if(verificarFinal() == 1){
      aux = pow(2, numeroDeDiscos)-1;
      if(numeroDeJogadas == aux){
        printf("\nParabéns, você ganhou e sua pontuação foi excelente %d de %d.\n", numeroDeJogadas, aux);
      }else if(numeroDeJogadas > aux && numeroDeJogadas <aux+5){
        printf("\nParabéns, você ganhou mas sua pontuação foi abaixo da média %d de%d.\n", numeroDeJogadas, aux);
      }else{
        printf("\nParabéns, você ganhou mas sua pontuação foi ruim: %d de %d.\n", numeroDeJogadas, aux);
      }
      system("PAUSE");
      system("CLS");
      printf("\n\n\t\t\t  Jogo encerrado com sucesso.\n");
      exit(0); 
    }
    printf("Informe qual a torre de origem (1 a 3): ");
    scanf("%d", &origem);
    do{
      if(origem < 1 || origem > 3){
        printf(" - Torre de origem não corresponde, informe corretamente.\nInforme qual a torre de origem (1 a 3): ");
        scanf("%d", &origem); 
      }
    }while(origem < 1 || origem > 3);
    mostrarTorres();
    printf("Informe qual a torre de destino (1 a 3): \t");
    scanf("%d", &destino);
    do{
      if(destino < 1 || destino > 3){
        printf(" - Torre de destino não corresponde, informe corretamente.\nInforme qual a torre de destino (1 a 3): ");
        scanf("%d", &destino); 
      }
      if(destino == origem){
        printf(" - O destino não pode ser igual a torre de origem.\nInforme qual a torre de destino (1 a 3): ");
        scanf("%d", &destino); 
      }
      }while(destino < 1 || destino > 3 || destino == origem);
    moverDiscos(origem, destino);
  }while(test != 1);
}


void mostrarTorres(){

  system("CLS");
  printf("\t   ---TORRE DE HANOI--- \n");

  /*//colocar um if aqui, pra passar no for abaixo qual os arrays certos
  //retirar/mover esse if
  if(numeroDeDiscos == 3){
    int torre1[3]= {1,2,3}, torre2[3]={0,0,0}, torre3[3] ={0,0,0};
  }else if(numeroDeDiscos == 4){
    //int torre1[4]= {1,2,3,4}, torre2[3]={0,0,0,0}, torre3[3] ={0,0,0,0};
  }else if(numeroDeDiscos == 5){
    //int torre1[5]= {1,2,3,4,5}, torre2[5]={0,0,0,0,0}, torre3[5] ={0,0,0,0,0};
  }*/

  for(int i=0;i<numeroDeDiscos;i++){ //impressao da torre

    printf(" \t |%d|    |%d|    |%d| \n", torre1[i], torre2[i], torre3[i]); 
  
  }
  printf("\t Nº de jogadas: ");
  if(numeroDeJogadas < 10){
    printf("0%d\n", numeroDeJogadas);
  }else{
    printf("%d\n", numeroDeJogadas);
  }
}


int verificarFinal(){
  int opt=0;
  if(torre3[0] == 1){
    opt = 1;
  }
  return(opt);
}


void regrasDoJogo(){
  system("CLS");
  printf(" - Torre de Hanói:\n");
  printf("   O objetivo deste jogo, consiste em deslocar todos os discos da primeira haste para a última haste.\n");
  printf("   Respeitando as seguintes regras:\n\n");
  printf("    1 - Deslocar um disco de cada vez, o qual deverá ser o do topo de uma das três hastes.\n\n");
  printf("    2 - Cada disco nunca poderá ser colocado sobre outro de tamanho menor.\n\n ");
  system("pause");
  system("CLS");
}