#include <stdio.h>
#include <stdlib.h>

//prototipação
void menu();
int le_valida_op();

int main() {
  menu();
  return 0;
}


//declaração
void menu(){
  //Definindo variavel
  int continuar;
  //Iniciando variavel para entrar no while
  continuar = 1;
  //Laço de repetição para chamada da função enquanto o usuario desejar;
  while(continuar != 0){
    //Verificando o que o usuario deseja
    if(continuar == 1){
      le_valida_op();
  }
  //Pedir para o usuario se ele deseja ou não continuar os calculos;
  printf("deseja continuar\n[0]Nop\n[1]Nova op\n:");
  fflush(stdin);
  scanf("%d", &continuar);
}
}

//declaração
int le_valida_op(){
  //Definindo variaveis do programa;
  float n, resultado;
  char operador;
  resultado = 0;
  //pedindo valor de n
  printf(":");
  fflush(stdin);
  scanf("%f", &n);
  resultado = n;
  //pedindo valor do operador
  printf(":");
  fflush(stdin);
  scanf("%c", &operador);
  //pedindo valor de n
  printf(":");
  fflush(stdin);
  scanf("%f", &n);
  //Definindo se a operação será de soma
  if(operador == '+'){
    resultado = resultado + n;
  }
  //Definindo se a operação será de subtração
  if(operador == '-'){
    resultado = resultado - n; 
  }
  //Definindo se a operação será de multiplicação
  if(operador == '*'){
    resultado = resultado * n;
  }
  //Definindo se a operação será de divisão
  if(operador == '/'){
    resultado = resultado / n;
  }
  printf("%.2f\n", resultado);
}