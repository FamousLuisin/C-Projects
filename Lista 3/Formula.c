/*nome: Luís Filipe Melo
  matricula: UC20104783
  nome: Eduardo Souza de Oliveira*/    

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//menu principal
void menu();
//cadastros
int cadastrar_circuito(i);
void cadastrar_volta();
//relatorio
void relatorio();
//Cadastro piloto
int cadastrar_piloto(i);

void identificar_piloto(i);
void nome_piloto(i);
void idade();
void sexo();
void pais_origem();



struct Piloto
{
  int id_piloto, idade;
  char nome[50], sexo, pais_origem[50];
} corredores[100];

struct Circuito
{
  int codigo_seq, menor_tempo, id_piloto_menor_tempo;
  float tamanho_circuito;
} percursos[100];

struct Melhor_volta
{

  int tempo, dia, mes, ano;
  char equipe[50];
};

int main()
{
  menu();
  return 0;
}

void menu()
{
  int escolha, i_piloto = 0;

  do
  {

    printf("[1] Cadastrar piloto\n[2] Cadastrar circuito\n[3] Cadastrar volta\n[4] Relatorio\n[5]Sair\n");
    fflush(stdin);
    scanf("%d", &escolha);

    if (escolha == 1)
    {
      i_piloto = cadastrar_piloto(i_piloto);
    }
    

  } while (escolha != 5);
  
}

int cadastrar_piloto(j_piloto)
{
  int parada;
   
   do
   {
    identificar_piloto(j_piloto);
    nome_piloto(j_piloto);

    j_piloto++;

    printf("Deseja vontinuar? [1]Sim / [2]Nao\n");
    fflush(stdin);
    scanf("%d", &parada);

   } while (parada != 2);
   
}

void identificar_piloto(x)
{
  int cond;

  do
  {
    cond = 0;
    printf("Id do jogo: ");
    fflush(stdin);
    scanf("%d", &corredores[x].id_piloto);
    for (int i = 0; i < x; i++)
    {
      if (corredores[x].id_piloto == corredores[i].id_piloto)
      {
        cond = 1;
      }
    }

  } while (corredores[x].id_piloto < 100 || corredores[x].id_piloto > 500 || cond == 1);

}

void nome_piloto(x)
{
  int MAX_PER, espaso;
  // Nome presidente

  do
  {
    espaso = 0;
    printf("Nome piloto: ");
    fflush(stdin);
    scanf("%[^\n]s", &corredores[x].nome);

    MAX_PER = strlen(corredores[x].nome);

    for (int i = 0; i < MAX_PER; i++)
    {
      if (corredores[x].nome[i] == ' ')
      {
        espaso += 1;
      }
    }

    MAX_PER = MAX_PER - espaso;

  } while (MAX_PER < 3 || MAX_PER > 50);
}