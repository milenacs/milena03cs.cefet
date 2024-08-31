#include <stdio.h>
#define TAM 10

void troca(int* x, int *y)
{
  int aux = *x;
  *x = *y;
  *y = aux;
}

void SelectionSort(int vetor[], int tamanho)
{
  int indice_min = 0, aux = 0;
  //esse é o for que percorre o vetor todo
  for(int i = 0; i <= tamanho; i++)
  {
    //O SelectionSort só precisa selecionar o minimo p/ trocar
    indice_min = i;
    for(int j = i; j <= tamanho; j++)
    {
      //Se trocar o < por > no if ordena em ordem decrescente
      if(vetor[j] < vetor[indice_min]) 
      {
        
        indice_min = j;
      }
      //se o minimo não for o mesmo indice atual é preciso trocar
      if(indice_min > i) 
      {
        troca(&vetor[i], &vetor[indice_min]);

      }
    }
    
  }
}

void ImprimeVetor(int vetor[], int tamanho)
{
  for(int i=0;i < tamanho;i++)
  {
    printf("%d ", vetor[i]);
  }
}

int main() 
{
  int vetor[] = {9, 8, 3, 5, 6, 4, 7, 2, 1, 10};
  printf("Vetor antes da organização: ");
  ImprimeVetor(vetor, TAM);
  
  SelectionSort(vetor, TAM);

  printf("\nVetor depois da organização: ");
  ImprimeVetor(vetor, TAM);

  return 0;
}