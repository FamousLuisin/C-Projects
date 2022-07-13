/*nome: Luís Filipe Melo
  matricula: UC20104783
  nome: Eduardo Souza de Oliveira
  matricula: UC19201106*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// menu principal
void menu();
// cadastros circuito
void cadastrar_circuito(int *ponteiro);
void identificador_circuito(int i);
void nome_do_circuito(int i);
void pais_do_circuito(int i);
void tamanho_do_circuito(int i);

void menor_tempo_circuito();

void cadastrar_volta(int *ponteiro);
void cadastrar_piloto_em_circuito(int i);
void cadastrar_dias_mes_ano(int i);
void cadastrar_nome_equipe(int i);
void cadastrar_menor_tempo(int i);

// relatorio
void relatorio(int k1, int k2, int k3);
void consulta_simples(int k1, int k2, int k3);
void consultar_todos(int k1, int k2, int k3);
void consultar_id_piloto(int k1);
void consultar_id_circuito(int k2);
void consulta_nome(int k1);
void consultar_circuito(int k2);
void consulta_por_tempo(int k3);

// Cadastro piloto
void cadastrar_piloto(int *ponteiro);

void identificar_piloto(int i);
void nome_piloto(int i);
void idade_piloto(int i);
void sexo_piloto(int i);
void pais_origem_piloto(int i);

struct Piloto
{
  int id_piloto, idade;
  char nome[50], sexo, pais_origem[50];
} corredores[100];

struct Circuito
{
  int codigo_seq, mtempo_min, mtempo_seg, mtempo_mil, id_piloto_menor_tempo;
  float tamanho_circuito;
  char nome_circuito[50], pais_circuito[50];
} percursos[100];

struct Melhor_volta
{
  int id2_piloto, codigo2_seq;
  int tempo_min, tempo_seg, tempo_mil, dia, mes, ano;
  char equipe[50];
} voltas[1000];

int main()
{
  menu();
  return 0;
}

void menu()
{
  int escolha, i_piloto = 0, i_circuito = 0, i_volta = 0;
  int *ponteiro_piloto, *ponteiro_circuito, *ponteiro_volta;
  ponteiro_piloto = &i_piloto;
  ponteiro_circuito = &i_circuito;
  ponteiro_volta = &i_volta;

  do
  {

    printf("[1] Cadastrar piloto\n[2] Cadastrar circuito\n[3] Cadastrar volta\n[4] Relatorio\n[5]Sair\n");
    fflush(stdin);
    scanf("%d", &escolha);

    if (escolha == 1)
    {
      system("clear||cls");
      cadastrar_piloto(ponteiro_piloto);
      system("clear||cls");
    }

    else if (escolha == 2)
    {
      system("clear||cls");
      cadastrar_circuito(ponteiro_circuito);
      system("clear||cls");
    }

    else if (escolha == 3)
    {
      system("clear||cls");
      cadastrar_volta(ponteiro_volta);
      system("clear||cls");
    }

    else if (escolha == 4)
    {
      system("clear||cls");
      relatorio(i_piloto, i_circuito, i_volta);
      system("clear||cls");
    }

  } while (escolha != 5);
}

//===========================================================================================

void cadastrar_piloto(int *ponteiro)
{
  int parada;
  do
  {
    identificar_piloto(*ponteiro);
    nome_piloto(*ponteiro);
    idade_piloto(*ponteiro);
    sexo_piloto(*ponteiro);
    pais_origem_piloto(*ponteiro);

    ++*ponteiro;

    printf("Deseja continuar? [1]Sim / [2]Nao\n");
    fflush(stdin);
    scanf("%d", &parada);

    system("clear||cls");

  } while (parada != 2);
}

void identificar_piloto(int x)
{
  int cond, i;

  do
  {
    cond = 0;
    printf("Id do piloto: ");
    fflush(stdin);
    scanf("%d", &corredores[x].id_piloto);
    for (i = 0; i < x; i++)
    {
      if (corredores[x].id_piloto == corredores[i].id_piloto)
      {
        printf("Ja cadastrado.\n");
        cond = 1;
      }
    }

  } while (corredores[x].id_piloto < 100 || corredores[x].id_piloto > 500 || cond == 1);
}

void nome_piloto(int x)
{
  int MAX_PER, espaso, i;
  // Nome presidente

  do
  {
    espaso = 0;
    printf("Nome piloto: ");
    fflush(stdin);
    scanf("%[^\n]s", &corredores[x].nome);

    MAX_PER = strlen(corredores[x].nome);

    for (i = 0; i < MAX_PER; i++)
    {
      if (corredores[x].nome[i] == ' ')
      {
        espaso += 1;
      }
    }

    MAX_PER = MAX_PER - espaso;

  } while (MAX_PER < 3 || MAX_PER > 50);
}

void idade_piloto(int x)
{
  do
  {
    printf("Idade piloto: ");
    fflush(stdin);
    scanf("%d", &corredores[x].idade);
  } while (corredores[x].idade < 18 || corredores[x].idade > 60);
}

void sexo_piloto(int x)
{
  do
  {
    printf("Sexo piloto: ");
    fflush(stdin);
    scanf("%c", &corredores[x].sexo);
  } while (corredores[x].sexo != 'm' && corredores[x].sexo != 'M' && corredores[x].sexo != 'f' && corredores[x].sexo != 'F');
}

void pais_origem_piloto(int x)
{
  // Pais origem
  int MAX_PER, espaso, i;

  do
  {
    espaso = 0;
    printf("Pais piloto: ");
    fflush(stdin);
    scanf("%[^\n]s", &corredores[x].pais_origem);

    MAX_PER = strlen(corredores[x].pais_origem);

    for (i = 0; i < MAX_PER; i++)
    {
      if (corredores[x].pais_origem[i] == ' ')
      {
        espaso += 1;
      }
    }

    MAX_PER = MAX_PER - espaso;

  } while (MAX_PER < 3 || MAX_PER > 50);
}

//==========================================================================================

void cadastrar_circuito(int *j_circuito)
{
  int parada;

  do
  {
    identificador_circuito(*j_circuito);
    nome_do_circuito(*j_circuito);
    pais_do_circuito(*j_circuito);
    tamanho_do_circuito(*j_circuito);

    ++*j_circuito;

    printf("Deseja continuar? [1]Sim / [2]Nao\n");
    fflush(stdin);
    scanf("%d", &parada);

    system("clear||cls");

  } while (parada != 2);
}

void identificador_circuito(int x)
{
  percursos[x].codigo_seq = 100 + x;
  printf("%d cadastrado\n", 100 + x);
}

void nome_do_circuito(int x)
{
  int MAX_PER, espaso, i, comparar, existe;
  // Nome presidente

  do
  {
    espaso = 0;
    printf("Nome circuito: ");
    fflush(stdin);
    scanf("%[^\n]s", &percursos[x].nome_circuito);

    MAX_PER = strlen(percursos[x].nome_circuito);

    for (i = 0; i < MAX_PER; i++)
    {
      if (percursos[x].nome_circuito[i] == ' ')
      {
        espaso += 1;
      }
    }

    MAX_PER = MAX_PER - espaso;

    existe = 0;
    for (i = 0; i < x; i++)
    {
      comparar = strcmp(percursos[i].nome_circuito, percursos[x].nome_circuito);
      if (comparar == 0)
      {
        printf("Ja cadastrado.\n");
        existe = 1;
      }
    }

  } while (MAX_PER < 3 || MAX_PER > 50 || existe == 1);
}

void pais_do_circuito(int x)
{
  int MAX_PER, espaso, i, existe, comparar;
  // Nome presidente

  do
  {
    espaso = 0;
    printf("Pais do circuito: ");
    fflush(stdin);
    scanf("%[^\n]s", &percursos[x].pais_circuito);

    MAX_PER = strlen(percursos[x].pais_circuito);

    for (i = 0; i < MAX_PER; i++)
    {
      if (percursos[x].pais_circuito[i] == ' ')
      {
        espaso += 1;
      }
    }

    MAX_PER = MAX_PER - espaso;

    existe = 0;
    for (i = 0; i < x; i++)
    {
      comparar = strcmp(percursos[i].pais_circuito, percursos[x].pais_circuito);
      if (comparar == 0)
      {
        printf("Ja cadastrado.\n");
        existe = 1;
      }
    }

  } while (MAX_PER < 3 || MAX_PER > 50 || existe == 1);
}

void tamanho_do_circuito(int x)
{
  do
  {
    printf("Tamanho Km: ");
    fflush(stdin);
    scanf("%f", &percursos[x].tamanho_circuito);

  } while (percursos[x].tamanho_circuito < 3 || percursos[x].tamanho_circuito > 25);
}

//=========================================================================================

void cadastrar_volta(int *j_volta)
{
  int parada;
  do
  {
    cadastrar_piloto_em_circuito(*j_volta);
    cadastrar_dias_mes_ano(*j_volta);
    cadastrar_nome_equipe(*j_volta);
    cadastrar_menor_tempo(*j_volta);
    menor_tempo_circuito();

    ++*j_volta;

    printf("Deseja continuar? [1]Sim / [2]Nao\n");
    fflush(stdin);
    scanf("%d", &parada);

    system("clear||cls");

  } while (parada != 2);
}

void cadastrar_piloto_em_circuito(int x)
{
  int cond, i;
  do
  {
    cond = 0;
    printf("Id do piloto: ");
    fflush(stdin);
    scanf("%d", &voltas[x].id2_piloto);
    for (i = 0; i < x + 1; i++)
    {
      if (corredores[i].id_piloto == voltas[x].id2_piloto)
      {
        cond = 1;
      }
    }

  } while (voltas[x].id2_piloto < 100 || voltas[x].id2_piloto > 500 || cond == 0);

  do
  {
    cond = 0;
    printf("Id do circuito: ");
    fflush(stdin);
    scanf("%d", &voltas[x].codigo2_seq);
    for (i = 0; i < x + 1; i++)
    {
      if (percursos[i].codigo_seq == voltas[x].codigo2_seq)
      {
        cond = 1;
      }
    }

  } while (voltas[x].codigo2_seq < 100 || voltas[x].codigo2_seq > 500 || cond == 0);
}

void cadastrar_dias_mes_ano(int x)
{
  int verificar, i;

  do
  {
    verificar = 0;

    do
    {
      printf("Dia: ");
      fflush(stdin);
      scanf("%d", &voltas[x].dia);
    } while (voltas[x].dia < 1 || voltas[x].dia > 31);

    do
    {
      printf("Mes: ");
      fflush(stdin);
      scanf("%d", &voltas[x].mes);
    } while (voltas[x].mes < 1 || voltas[x].mes > 12);

    do
    {
      printf("Ano: ");
      fflush(stdin);
      scanf("%d", &voltas[x].ano);
    } while (voltas[x].ano < 2000 || voltas[x].ano > 2050);

    for (i = 0; i < x; i++)
    {
      if (voltas[i].id2_piloto == voltas[x].id2_piloto && voltas[i].codigo2_seq == voltas[x].codigo2_seq)
      {
        if (voltas[i].dia == voltas[x].dia && voltas[i].mes == voltas[x].mes && voltas[i].ano == voltas[x].ano)
        {
          printf("Ja cadastrado.\n");
          verificar = 1;
        }
      }
    }

  } while (verificar != 0);
}

void cadastrar_nome_equipe(int x)
{

  int MAX_PER, espaso, i, comparar, existe;

  do
  {
    espaso = 0;
    printf("Nome equipe: ");
    fflush(stdin);
    scanf("%[^\n]s", &voltas[x].equipe);

    MAX_PER = strlen(voltas[x].equipe);

    for (i = 0; i < MAX_PER; i++)
    {
      if (voltas[x].equipe[i] == ' ')
      {
        espaso += 1;
      }
    }

    MAX_PER = MAX_PER - espaso;

  } while (MAX_PER < 3 || MAX_PER > 50);
}

void cadastrar_menor_tempo(int x)
{
  do
  {
    printf("Minutos: ");
    fflush(stdin);
    scanf("%d", &voltas[x].tempo_min);
  } while (voltas[x].tempo_min < 0 || voltas[x].tempo_min > 60);

  do
  {
    printf("segundos: ");
    fflush(stdin);
    scanf("%d", &voltas[x].tempo_seg);
  } while (voltas[x].tempo_seg < 0 || voltas[x].tempo_seg > 60);

  do
  {
    printf("Milessimos: ");
    fflush(stdin);
    scanf("%d", &voltas[x].tempo_mil);
  } while (voltas[x].tempo_mil < 0 || voltas[x].tempo_mil > 1000);
}

void menor_tempo_circuito()
{
  int i, j, menor_time, milessecundos = 0, ganhador;
  for (i = 0; i < 100; i++)
  {

    menor_time = 1000000;
    ganhador = 0;

    for (j = 0; j < 1000; j++)
    {
      if (percursos[i].codigo_seq == voltas[j].codigo2_seq)
      {
        milessecundos = (voltas[j].tempo_mil + (voltas[j].tempo_seg * 1000) + (voltas[j].tempo_min * 6000));
        if (menor_time > milessecundos)
        {
          menor_time = milessecundos;
          ganhador = j;
        }
      }
    }
    percursos[i].id_piloto_menor_tempo = voltas[ganhador].id2_piloto;
    percursos[i].mtempo_mil = voltas[ganhador].tempo_mil;
    percursos[i].mtempo_seg = voltas[ganhador].tempo_seg;
    percursos[i].mtempo_min = voltas[ganhador].tempo_min;
  }
}

//==============================================================================================================

void relatorio(int k1, int k2, int k3)
{
  int escolha;
  do
  {

    printf("[1] Consulta Simples\n[2] Nome piloto\n[3] Circuito\n[4] Voltas\n[5]Sair\n");
    fflush(stdin);
    scanf("%d", &escolha);

    if (escolha == 1)
    {
      consulta_simples(k1, k2, k3);
    }

    else if (escolha == 2)
    {
      consulta_nome(k1);
    }
    else if (escolha == 3)
    {
      consultar_circuito(k3);
    }

    else if (escolha == 4)
    {
      consulta_por_tempo(k3);
    }

  } while (escolha != 5);
}

void consulta_simples(int x1, int x2, int x3)
{
  int alternativa;

  do
  {

    printf("[1] Consulta todos\n[2] chave piloto\n[3] chave circuito\n[4]Sair\n");
    fflush(stdin);
    scanf("%d", &alternativa);

    if (alternativa == 1)
    {
      consultar_todos(x1, x2, x3);
    }

    else if (alternativa == 2)
    {
      consultar_id_piloto(x1);
    }
    else if (alternativa == 3)
    {
      consultar_id_circuito(x2);
    }

  } while (alternativa != 4);
}

void consultar_todos(int t1, int t2, int t3)
{
  int i;

  printf("XXXXX - PILOTOS - XXXXX\n");
  for (i = 0; i < t1; i++)
  {
    printf("ID Piloto: %d || nome: %s || idade: %d || ", corredores[i].id_piloto, corredores[i].nome, corredores[i].idade);
    printf("sexo: %c || pais de origem: %s\n", corredores[i].sexo, corredores[i].pais_origem);
  }

  printf("XXXXX - CIRCUITOS - XXXXX\n");
  for (i = 0; i < t2; i++)
  {
    printf("ID Circuito: %d || nome circuito: %s || pais do circuito: %s || Tamanho: %.2f ||\nMenor Tempo\n%d:%d:%d || ID Piloto: %d\n", percursos[i].codigo_seq, percursos[i].nome_circuito, percursos[i].pais_circuito, percursos[i].tamanho_circuito, percursos[i].mtempo_min, percursos[i].mtempo_seg, percursos[i].mtempo_mil, percursos[i].id_piloto_menor_tempo);
  }

  printf("XXXXX - VOLTAS - XXXXX\n");
  for (i = 0; i < t3; i++)
  {
    printf("DATA: %d/%d/%d\nID Piloto: %d || ID Circuito: %d  || Tempo: %d:%d:%d || equipe: %s\n", voltas[i].dia, voltas[i].mes, voltas[i].ano, voltas[i].id2_piloto, voltas[i].codigo2_seq, voltas[i].tempo_min, voltas[i].tempo_seg, voltas[i].tempo_mil, voltas[i].equipe);
  }
}

void consultar_id_piloto(int t1)
{
  int i, escolha;

  printf("Qual piloto voce deseja encontrar? ");
  fflush(stdin);
  scanf("%d", &escolha);

  for (i = 0; i < t1; i++)
  {
    if (escolha == corredores[i].id_piloto)
    {
      printf("ID Piloto: %d || nome: %s || idade: %d || ", corredores[i].id_piloto, corredores[i].nome, corredores[i].idade);
      printf("sexo: %c || pais de origem: %s\n", corredores[i].sexo, corredores[i].pais_origem);
    }
  }
}

void consultar_id_circuito(int t2)
{
  int i, escolha;

  printf("Qual circuito voce deseja encontrar? ");
  fflush(stdin);
  scanf("%d", &escolha);

  for (i = 0; i < t2; i++)
  {
    if (escolha == percursos[i].codigo_seq)
    {
      printf("ID Circuito: %d || nome circuito: %s || pais do circuito: %s || Tamanho: %.2f ||\nMenor Tempo\n%d:%d:%d || ID Piloto: %d\n", percursos[i].codigo_seq, percursos[i].nome_circuito, percursos[i].pais_circuito, percursos[i].tamanho_circuito, percursos[i].mtempo_min, percursos[i].mtempo_seg, percursos[i].mtempo_mil, percursos[i].id_piloto_menor_tempo);
    }
    else
    {
      printf("Nao existe");
    }
  }
}

void consulta_nome(int k1)
{
  int i;
  char temporaria[50];

  printf("Nome piloto: ");
  fflush(stdin);
  scanf("%[^\n]s", &temporaria);

  for (i = 0; i < k1; i++)
  {
    if (strcmp(corredores[i].nome, temporaria) == 0)
    {
      printf("ID Piloto: %d || nome: %s || idade: %d || ", corredores[i].id_piloto, corredores[i].nome, corredores[i].idade);
      printf("sexo: %c || pais de origem: %s\n", corredores[i].sexo, corredores[i].pais_origem);
    }
  }
}

void consultar_circuito(int k3)
{
  int id_temp, i;

  printf("Id circuito: ");
  fflush(stdin);
  scanf("%d", &id_temp);

  for ( i = 0; i < k3; i++)
  {
    if (id_temp == voltas[i].codigo2_seq)
    {
      printf("DATA: %d/%d/%d\nID Piloto: %d || ID Circuito: %d  || Tempo: %d:%d:%d || equipe: %s\n", voltas[i].dia, voltas[i].mes, voltas[i].ano, voltas[i].id2_piloto, voltas[i].codigo2_seq, voltas[i].tempo_min, voltas[i].tempo_seg, voltas[i].tempo_mil, voltas[i].equipe);
    }
    
  }
}

void consulta_por_tempo(int k3)
{
  int min_temp, seg_temp, mil_temp, menor_time;
  int i, j, milessecundos = 0;

  do
  {
    printf("Minutos: ");
    fflush(stdin);
    scanf("%d", & min_temp);
  } while ( min_temp < 0 ||  min_temp > 60);

  do
  {
    printf("segundos: ");
    fflush(stdin);
    scanf("%d", &seg_temp);
  } while (seg_temp < 0 || seg_temp > 60);

  do
  {
    printf("Milessimos: ");
    fflush(stdin);
    scanf("%d", &mil_temp);
  } while (mil_temp < 0 || mil_temp > 1000);

  menor_time = (mil_temp + (seg_temp * 1000) + (min_temp * 6000));


  for ( i = 0; i < k3; i++)
  {
    milessecundos = (voltas[i].tempo_mil + (voltas[i].tempo_seg * 1000) + (voltas[i].tempo_min * 6000));
    if (milessecundos < menor_time)
    {
      printf("DATA: %d/%d/%d\nID Piloto: %d || ID Circuito: %d  || Tempo: %d:%d:%d || equipe: %s\n", voltas[i].dia, voltas[i].mes, voltas[i].ano, voltas[i].id2_piloto, voltas[i].codigo2_seq, voltas[i].tempo_min, voltas[i].tempo_seg, voltas[i].tempo_mil, voltas[i].equipe);
    }
  }
  
}