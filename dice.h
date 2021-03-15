#ifndef __dice__
#define __dice__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


int roll(int dado, int quantidade){
    int valor=0, soma=0;

    for(int i = 0; i < quantidade; i++){
        sleep(3);
        srand(time(NULL));
        
        valor = rand()%(dado+1);
        valor = valor == 0 ? 1: valor;
        //printf("dado %d valor: %d \n", i+1, valor);
        soma += valor;
    }

    return soma;
}

// int main(int argc, char **argv){
//     int resposta=-1, dado=0, quantidade;
//     int resu=0;

//     while(resposta != 0){

//         printf("Digite 4   para D4   e a quantidade\n");
//         printf("Digite 6   para D6   e a quantidade\n");
//         printf("Digite 8   para D8   e a quantidade\n");
//         printf("Digite 10  para D10  e a quantidade\n");
//         printf("Digite 12  para D12  e a quantidade\n");
//         printf("Digite 20  para D20  e a quantidade\n");
//         printf("Digite 100 para D100 e a quantidade\n");
//         printf("DIGITE 0 PARA ENCERRAR \n");

//         scanf("%d", &resposta);
//         if (resposta == 0)break;
//         scanf("%d", &quantidade);

//         // while (1)
//         // {
//         //     srand(time(NULL));
//         //     int t = rand();
//         //     time_t tempo;
//         //     struct tm *raw;

//         //     time(&tempo);
//         //     raw = localtime(&tempo);
//         //     // printf("AQUI O TEMPOOO %s\n", asctime(raw));
//         //     int s = raw->tm_sec + raw->tm_min + raw->tm_hour;
            
//         //     printf("*/*/*/*/*/*/*/*/*//*/*/ srand(time(NULL)):(%d)       localtime(&tempo): (%d)\n", t%21, s%21);
//         // }
        
        
//         srand(time(NULL));

//         switch (resposta)
//         {
//             case 4:
              
//                 resu = roll( resposta+1, quantidade);
//                 break;
            
//             case 6:
               
//                 resu = roll( resposta+1, quantidade);

//                 break;
            
//             case 8:
               
//                 resu = roll( resposta+1, quantidade);
//                 break;
            
//             case 10:
                
//                 resu = roll( resposta+1, quantidade);
//                 break;
            
//             case 12:
               
//                 resu = roll( resposta+1, quantidade);
//                 break;
            
//             case 20:
                
//                 resu = roll( resposta+1, quantidade);
//                 break;

//             case 100:
                
//                 resu = roll( resposta+1, quantidade);
//                 break;
            
//             default:
//                 break;
//         }

//         //dado = dado == 0 ? 1: dado;
//         printf("\n\n\n***** Valor do dado: %d || Dado escolhido %d*****\n\n\n", resu, resposta);
//         dado=0;
//         resu=0;

//     }

//     printf("Obrigado por jogar!\n");

//     return EXIT_SUCCESS;
// }

#endif