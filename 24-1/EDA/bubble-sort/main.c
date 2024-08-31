#include <stdio.h>
#include <stdlib.h>
#define TAM 10

void BubbleSort(int vetor[], int tamanho)
{
  int aux;
  //podia até ter tamanho variável, mas é super complicado com sizeof
  for(int i = 0; i<(tamanho - 1);i++)
  {
   
    for(int j = 0; j < tamanho-i ; j++)
    {
        if(vetor[j]>vetor[j+1]) //Se o valor for maior que o próximo, troque
        {
          aux = vetor[j];
          vetor[j] = vetor[j+1];//o vetor[j] está no auxiliar, é só não se confundir
          vetor[j+1] = aux;
        }
    }
  }
}

void ImprimeVetor(int vetor[], int tamanho)
{
  for(int i=0;i<tamanho;i++)
  {
    printf("%d ", vetor[i]);
  }
}

int main() 
{
  int vetor[] = {9,8,3,5,6,4,7,2,1,10};
  BubbleSort(vetor, TAM);
  
  printf("Espero que tenha dado certo\n");
  ImprimeVetor(vetor, TAM);
  
  return 0;
}