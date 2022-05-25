#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
  //Definir variaveis do tipo char;
  char nome[50], letra;
  int i, tamanho, espaso;
  
  //Recebendo o nome do usuario;
  printf("Digite seu nome: ");
  scanf("%[^\n]s", &nome);

  //Tamanho do nome;
  tamanho = strlen(nome);

  //Encontrar o ultimo espaço do nome;
  for (i = 0; i < tamanho; i++)
  {
    if(nome[i] == ' '){
      espaso = i;
    }  
  }

  //Pegar o ultimo nome e coloca-lo todo em letra maiuscula;
  for (i=espaso+1; i < tamanho; i++)
  {
    letra = toupper(nome[i]);
    printf("%c", letra);
  }
  printf(",");

  //Pegar a inicial de cada nome;
  for (i = 0; i < espaso; i++)
  {
    if(i == 0){
      letra = nome[i];
      printf("%c.", letra);
    }

    if(nome[i] == ' '){
      letra = nome[i+1];
      printf("%c.", letra);
    }
  }
  

  return 0;
}
