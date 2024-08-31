#include <iostream>
using namespace std;

struct no
{
  bool topo;
  int info;
  struct no* prox;
};

typedef struct no* ponteiro_no;
ponteiro_no topo = NULL;//começa com  nulo

typedef struct no no;

void empilhar()
{
  ponteiro_no n = new no();
  cout << "Entre com o valor";
  cin >> n->info;
  if(topo == NULL)
  {
    n->prox = NULL;
  }
  else n->prox = topo;

  topo = n;
  
}

void desempilhar()
{
  if(topo == NULL)
  {
    cout << "Essa lista não contém elementos";
  }
  else topo = topo->prox;
  
}
void listar()
{
  ponteiro_no aux = topo;
  if (topo == NULL)
  {
    cout << "Lista Vazia\n";
  }
  else {

    while (aux != NULL)
    {
      cout << aux->info << "\t";
      cout << aux->prox <<"\n";
      aux = aux->prox;
    }
    cout << "\n";
  }
}


int main() {
  int op;
  do 
  {
    
    cout << "1. Empilhar\n" 
         << "2. Desempilhar\n"
      << "3. Listar\n"
      << "0. Sair\n"   
      << "Digite uma opção: ";
    cin >> op;

    switch (op)
    {
      case 1: empilhar(); break;
      case 2: desempilhar(); break;
      case 3: listar(); break;
    }
  } while (op !=0);
  
  
}