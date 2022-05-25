#include <stdio.h>

int main()
{
  //Declarando idade como uma variavel do tipo int(inteiro);
  int idade;

  //Pedindo para o usuario digitar sua idade;
  printf("Digite sua idade: ");
  scanf("%d", &idade);

  //Verificando a qual grupo aquele usuario pertence
  //Verificando se o usuario tem 41 anos;
  if (idade == 41){
    printf("ganha prêmio 1");
  }
  else{
    //Verificando se o usuario tem 82 anos;
    if(idade == 82){
      printf("ganha prêmio 2");
    }
    else{
      //Verificando se o usuario tem mais de 65 anos;
      if(idade >= 65){
        printf("opcional");
      }
      else{
        //Verificando se o usuario tem mais de 18 anos;
        if(idade >= 18){
          printf("obrigatório");
        }
        else{
          //Verificando se o usuario tem mais de 16 anos;
          if(idade >= 16){
            printf("opcional");
          }
          else{
            //Verificando se o usuario tem mais de 0 anos;
            if(idade >= 0){
              printf("não vota");
            }
            else{
              printf("não nasceu");
            }
          }
        }
      }
    }
  }

  return 0;
}
