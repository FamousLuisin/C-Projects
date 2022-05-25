#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main()
{
  //Definir vairaveis do tipo char;
  char nome[50], endereso[50], complementoCasa[25], bairro[25], siglaEstado[20],
  cidade[20], email[30], cep[20], telefoneCelular[20], ddd[20], telefoneCasa[20], cpf[20],  
  diaNasc[20], mesNasc[20], anoNasc[20], numeroCasa[20], diaContrato[20], mesContrato[20], anoContrato[20];

  //Pedir o nome para o usuario;
  printf("Nome: ");
  fflush(stdin);
  scanf("%[^\n]s", &nome);

  //Pedir o dia de nascimento;
  printf("dia nascimento: ");
  fflush(stdin);
  scanf("%s", &diaNasc);

  //Pedir o mes de nascimento;
  printf("mes nascimento: ");
  fflush(stdin);
  scanf("%s", &mesNasc);

  //Pedir o ano de nascimento;
  printf("ano nascimento: ");
  fflush(stdin);
  scanf("%s", &anoNasc);

  //Pedir o email;
  printf("email: ");
  fflush(stdin);
  scanf("%s", &email);

  //Pedir o cpf;
  printf("Cpf: ");
  fflush(stdin);
  scanf("%s", &cpf);

  //Pedir o endereço do usuario;
  printf("Endereço: ");
  fflush(stdin);
  scanf("%[^\n]s", &endereso);

  //Pedir o cep do usuario;
  printf("Cep: ");
  fflush(stdin);
  scanf("%s", &cep);

  //Pedir o numero da casa;
  printf("Numero da casa: ");
  fflush(stdin);
  scanf("%s", &numeroCasa);
  
  //Pedir um complemento;
  printf("Complemento: ");
  fflush(stdin);
  scanf("%[^\n]s", &complementoCasa);

  //Pedir a sigla do estado;
  printf("Estado: ");
  fflush(stdin);
  scanf("%s", &siglaEstado);
  printf("%s", siglaEstado);

  //Pedir a bairro;
  printf("bairro: ");
  fflush(stdin);
  scanf("%s", &bairro);

  //Pedir a cidade;
  printf("Cidade: ");
  fflush(stdin);
  scanf("%s", &cidade);

  //Pedir o Telefone de casa;
  printf("Telefone de casa: ");
  fflush(stdin);
  scanf("%s", &telefoneCasa);

  //Pedir o telefone celular;
  printf("telefone celular: ");
  fflush(stdin);
  scanf("%s", &telefoneCelular);

  //Pedir o ddd;
  printf("ddd: ");
  fflush(stdin);
  scanf("%s", &ddd);

  //Pedir o dia do contrato;
  printf("dia: ");
  fflush(stdin);
  scanf("%s", &diaContrato);

  //Pedir o mes do contrato;
  printf("mes: ");
  fflush(stdin);
  scanf("%s", &mesContrato);

  //Pedir o ano do contrato;
  printf("ano: ");
  fflush(stdin);
  scanf("%s", &anoContrato);


  //contrato;
  printf("Nome Completo: %s\n", nome);
  printf("Endereso: %s\n", endereso);
  printf("Numero:\tComplemento:\tBairro:\n");
  printf("%s\t%s\t%s\n", numeroCasa, complementoCasa,bairro);
  printf("Cep:\tEstado:\tCidade:\n");
  printf("%s\t%s\t%s\n", cep, siglaEstado, cidade);
  printf("DDD:\tTelefone:\tDDD:\tCelular:\n");
  printf("%s\t%s\t%s\t%s\n", ddd, telefoneCasa, ddd, telefoneCelular);
  printf("CPF:\n");
  printf("%s\n", cpf);
  printf("Data de nasc:\n");
  printf("%s/%s/%s\n", diaNasc, mesNasc, anoNasc);
  printf("E-mail:\n");
  printf("%s\n", email);
  printf("Data:\n");
  printf("%s/%s/%s\n", diaContrato, mesContrato, anoContrato);




  return 0;
}
