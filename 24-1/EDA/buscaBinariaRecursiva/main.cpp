#include <iostream>
using namespace std;

int BuscaBinaria(int busca, int vetor[], int inicio, int fim)
{
  //ideal p/ vetores ordenados!
  int meio;
  while (inicio <= fim) 
  {
    meio = inicio + (fim - inicio) / 2;
    if(vetor[meio] == busca)
    {
      return meio;
    }
    else if(busca > vetor[meio])
    {
      return BuscaBinaria(busca,vetor, meio+1,fim);
    }
    else
    {
      return BuscaBinaria(busca, vetor,inicio,meio-1);
    }
  }
  return -1;
}
int main() {
   int vetor[] = {1,2,3,4,5,6,7,8,9,10}, busca = 0, indice = -1;
  cout << "Insira a busca: \t";
  cin >> busca;
  indice = BuscaBinaria(busca, vetor, 0, 10);
  if(indice==-1) cout<< "Erro! O valor não foi encontrado.";
  else cout << "O endereço está no índice "<< indice;
}