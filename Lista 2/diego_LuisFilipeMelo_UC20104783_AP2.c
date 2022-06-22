/*nome: Luís Filipe Melo
  matricula: UC20104783
  nome: Eduardo Souza de Oliveira*/



#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Principal
void menu();
// Funções de cadastro
int cadastro();
// char presidente();
void id_jogos(x);
void valor_arrecadados(x);
void cidades(x);
// Funções de retorno
void dados_jogo(x);
void consulta_cidades();
//==============================================================
struct partida
{
  int id_jogo;
  float valor_arrecadado;
  char cidade[120];
} partidas[450], intermediario;
//==============================================================
int main()
{
  menu();
  return 0;
}
//==============================================================
void menu()
{
  int escolha, i;
  //================================================
  do
  {
    printf("[1]Cadastro partidas:\n[2]Dados dos jogos:\n[3]Consulta de uma cidade\n[4]FIM\n");
    fflush(stdin);
    scanf("%d", &escolha);

    if (escolha == 1)
    {
      presidente();
      i = cadastro();
    }

    else if (escolha == 2)
    {
      dados_jogo(i);
    }

    else if (escolha == 3)
    {
      consulta_cidades();
    }

  } while (escolha != 0);
}
//==============================================================
int cadastro()
{
  int i;
  for (i = 0; i < 450; i++)
  {
    id_jogos(i);
    valor_arrecadados(i);
    cidades(i);
  }
  return i;
}
//==============================================================
void presidente()
{
  char nome_presidente[50];
  int MAX_PRE, espaso;
  // Nome presidente

  do
  {
    espaso = 0;
    printf("Nome: ");
    fflush(stdin);
    scanf("%[^\n]s", &nome_presidente);

    MAX_PRE = strlen(nome_presidente);

    for (int i = 0; i < MAX_PRE; i++)
    {
      if (nome_presidente[i] == ' ')
      {
        espaso += 1;
      }
    }

    MAX_PRE = MAX_PRE - espaso;

  } while (MAX_PRE < 10 || MAX_PRE > 50);
}
//==============================================================
void id_jogos(x)
{
  int cond;

  do
  {
    cond = 0;
    printf("Id do jogo: ");
    fflush(stdin);
    scanf("%d", &partidas[x].id_jogo);
    for (int i = 0; i < x; i++)
    {
      if (partidas[x].id_jogo == partidas[i].id_jogo)
      {
        cond = 1;
      }
    }

  } while (partidas[x].id_jogo < 300 || partidas[x].id_jogo > 10000 || cond == 1);
}
//==============================================================
void valor_arrecadados(x)
{
  do
  {
    printf("Valor arrecadado: ");
    fflush(stdin);
    scanf("%f", &partidas[x].valor_arrecadado);

  } while (partidas[x].valor_arrecadado < 1000 || partidas[x].valor_arrecadado > 1000000);
}
//==============================================================
void cidades(x)
{
  do
  {
    printf("Cidade: ");
    fflush(stdin);
    scanf("%[^\n]s", &partidas[x].cidade);

  } while (strlen(partidas[x].cidade) < 4 || strlen(partidas[x].cidade) > 120);
}
//==============================================================
void consulta_cidades()
{
  char consultar_cidade[120];
  int numero_cidade = 0, comparar = 0;

  printf("Digite a cidade a ser consultada: ");
  fflush(stdin);
  scanf(" %[^\n]s", &consultar_cidade);

  for (int i = 0; i < 450; i++)
  {
    comparar = strcmp(partidas[i].cidade, consultar_cidade);
    if (comparar == 0)
    {
      numero_cidade += 1;
      printf("Id do jogo: %d\tValor arrecadado: %.2f\n", partidas[i].id_jogo, partidas[i].valor_arrecadado);
    }
  }
  if (numero_cidade == 0)
  {
    printf("Nao ocorreu jogo na cidade %s\n", consultar_cidade);
  }
}
//==============================================================
void dados_jogo(x)
{
  int i, j, menor = 0;

  printf("Nome Presidente:\n");
  for (i = 0; i < x; i++)
  {
    for (j = i+1; j < x; j++)
    {
      if (partidas[menor].cidade > partidas[j].cidade)
      {
        menor = j;
      }
    }
    intermediario = partidas[i];
    partidas[i] = partidas[menor];
    partidas[menor] = intermediario;
  }

  for (i = 0; i < x; i++)
  {
    printf("cidade: %s\tid jogo: %d\tarrecadado: %.2f\n", partidas[i].cidade, partidas[i].id_jogo, partidas[i].valor_arrecadado);
  }
  
}
//printf("cidade: %s\tid jogo: %d\tarrecadado: %.2f\n", partidas[i].cidade, partidas[i].id_jogo, partidas[i].valor_arrecadado);