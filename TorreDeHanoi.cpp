
/* Praticas De Paradgimas De Linguagens De Programação
            Projeto Torre De Hanoi
                Grupo 3
        Bruno Meneses
        Alex Micaela
        Lílian Honorio Teixeira
        Victor Arruda Câmara Virgolino
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
using namespace std;

void mostrarTorres(); 
int valorTorre(int torre[numeroDeDiscos]); 
int destinoTorre(int torre[numeroDeDiscos]); 
void moverDiscos(int orig, int dest); 
void mostrarMenu(); 
int verificarFinal(); 
void regras(); 


int nivelDeDificuldade;
int numeroDeDiscos;
int torre1[5]= {1,2,3,4,5}, torre2[numeroDeDiscos]={}, torre3[numeroDeDiscos] ={}; // ARRAYS;

int cont=0;


int main(void){
  int op=1;
  while(op!=0){
    printf(" - TORRE DE HANOI \n   2 - JOGAR\n   1 - REGRAS\n   0 - SAIR\n - DIGITE: ");
    scanf("%d", &op);
    switch(op){
      case 2:
          mostrarTorres();
          mostrarMenu();
          break;
      case 1:
          regras();
          break;
      default:
          if(op != 0){
            printf(" - OPÇÃO INVALIDA INFORME NOVAMENTE\n - ");
            system("PAUSE");
            system("CLS");
          }else{
            system("CLS");
            printf("\n\n\t\t\t  ENCERRADO COM SUCESSO.\n");
          }   
          break;
    }
  }
  return 0;
}

void mostrarTorres(){
  printf("\nEscolha a Dificuldade: \n 1 - Fácil(3 discos)\n 2 - Médio(4 discos)\n 3 - Dificil(5 discos)\n");
  scanf("%d", &nivelDeDificuldade);

  if(nivelDeDificuldade == 1){
    numeroDeDiscos = 3;
  } else if(nivelDeDificuldade == 2){
    numeroDeDiscos = 4;
  } else if(nivelDeDificuldade == 3){
    numeroDeDiscos = 5;
  }

  system("CLS");
  printf("\t   TORRE DE HANOI \n");
  for(int i=0;i<numeroDeDiscos;i++){
    printf(" \t |%d|    |%d|    |%d| \n", torre1[i], torre2[i], torre3[i]); 
    
  }
  printf("\t Nº de jogadas: ");
  if(cont < 10){
    printf("0%d\n", cont);
  }else{
    printf("%d\n", cont);
  }
}


int valorTorre(int torre[]){ 
  int i, a=0;
  for(i=numeroDeDiscos-1; i>=0; i--){
    if(torre[i] != 0){
      a = i;
    }
    if(torre[4] == 0){
      a = 0;
    }
  }
  return(a);
}


int destinoTorre(int torre[]){ 
  int i, a=0;
  for(i=0; i<numeroDeDiscos; i++){
    if(torre[i] == 0){
      a = i;
    }
  }
  return(a);
}


void moverDiscos(int orig, int dest){
  int aux1, aux2, aux3;
  
  // ORIGEM 1 - TORRE 1
  if(orig == 1){
    // DESTINO 2 - TORRE 2  
    if(dest == 2){
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
          cont++;
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
          cont++;
        }
      }
    }     
  }
  
  // ORIGEM 2 - TORRE 2
  if(orig == 2){
    // DESTINO 1 - TORRE 1
    if(dest == 1){
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
          cont++;
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
          cont++;         
        }
      }
    } 
  }
  
  // ORIGEM 3 - TORRE 3
  if(orig == 3){
    // DESTINO 1 - TORRE 1
    if(dest == 1){
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
          cont++;       
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
          cont++;
        }
      }
    } 
  } 
  mostrarTorres();
}


void mostrarMenu(){
  int orig, dest, test=0, aux;
  do{
    
    if(verificarFinal() == 1){
      aux = pow(2, numeroDeDiscos)-1;
      if(cont == aux){
        printf("\nParabéns, você ganhou e sua pontuação foi excelente %d de %d.\n", cont, aux);
      }else if(cont > aux && cont <aux+5){
        printf("\nParabéns, você ganhou mas sua pontuação foi abaixo da média %d de%d.\n", cont, aux);
      }else{
        printf("\nParabéns, você ganhou mas sua pontuação foi ruim: %d de %d.\n", cont, aux);
      }
      system("PAUSE");
      system("CLS");
      printf("\n\n\t\t\t  ENCERRADO COM SUCESSO.\n");
      exit(0); // FINALIZA O PROGRAMA;
    }
    printf("Informe Torre Origem (1 a 3): ");
    scanf("%d", &orig);
    do{
      if(orig < 1 || orig > 3){
        printf(" - Torre de Origem não corresponde, informe corretamente.\nInforme Torre Origem (1 a 3): ");
        scanf("%d", &orig); 
      }
    }while(orig < 1 || orig > 3);
    mostrarTorres();
    printf("Informe Torre Destino (1 a 3): \t");
    scanf("%d", &dest);
    do{
      if(dest < 1 || dest > 3){
        printf(" - Torre de Destino não corresponde, informe corretamente.\nInforme Torre Destino (1 a 3): ");
        scanf("%d", &dest); 
      }
      if(dest == orig){
        printf(" - O destino não pode ser igual a torre de origem.\nInforme Torre Destino (1 a 3): ");
        scanf("%d", &dest); 
      }
      }while(dest < 1 || dest > 3 || dest == orig);
    moverDiscos(orig, dest);
  }while(test != 1);
}


int verificarFinal(){
  int opt=0;
  if(torre3[0] == 1){
    opt = 1;
  }
  return(opt);
}


void regras(){
  system("CLS");
  printf(" - Torre de Hanói:\n");
  printf("   O objetivo deste jogo, consiste em deslocar todos os discos da primeira haste para a última haste.\n");
  printf("   Respeitando as seguintes regras:\n\n");
  printf("    1 - Deslocar um disco de cada vez, o qual deverá ser o do topo de uma das três hastes.\n\n");
  printf("    2 - Cada disco nunca poderá ser colocado sobre outro de tamanho menor.\n\n ");
  system("pause");
  system("CLS");
}