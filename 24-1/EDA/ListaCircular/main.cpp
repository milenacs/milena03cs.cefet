#include <iostream>
using namespace std;
struct no{
  int info;
  struct no * prox;
};
typedef struct no * noPtr;

bool listaVazia(noPtr topo)
{
  if(topo == NULL){
   return true; 
  }
  else return false;
}

void listar(noPtr fim)
{
  noPtr aux = fim;
  if (listaVazia(fim))
  {
    cout << "Lista Vazia\n";
  }
  else 
  {
    do
    {
      cout << aux->info << "\t";
      cout << aux->prox <<"\n";
      aux = aux->prox;
    }while (aux != fim);
    cout << "\n";
  }
}

void inserir(noPtr *fim, int *qtd)
{
  noPtr novo = new no;
  cout << "Valor: ";
  cin >> novo->info;
  if(listaVazia(*fim))
  {
    *fim = novo;
   novo->prox = *fim;
  }
  else{
  novo->prox = (*fim)->prox;
  (*fim)->prox = novo;
  *fim = novo;
  }
  *qtd = *qtd + 1;
}

int menu();

int main() 
{
  noPtr fim = NULL;
  int qtd=0;
  for(;;)
  {
    int opc = menu();
    switch(opc)
    {
      case 1:
        inserir(&fim, &qtd);
      break;
      case 2:
        listar(fim);
      break;
      case 3:
        return 0;
      break;
    }
  }
}

int menu(){
  int opc;
  cout << "1. Inserir na lista\n" 
    << "0. Sair\n"   
    << "Digite uma opção: ";
  cin >> opc;
  cout << endl;
  
  return opc;
}

// só precisa do fim
// o elemento inserido terá o mesmo prox do ultimo elemento, para então ser ligado no final
//remover é mais facil pelo inicio
// se topo for o elemento a ser removido, só existe 1 elemento