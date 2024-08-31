#include <iostream>
using namespace std;

struct no
{
  int info;
  struct no* prox;
};

typedef struct no* ponteiro_no;
ponteiro_no comeco = NULL;
ponteiro_no fim = NULL;

typedef struct no no;

//enfileirar
void enfileirar()
{
  ponteiro_no n = new no();
  cout << "Entre com o valor";
  cin >> n->info;
  if(comeco == NULL)
  {
    n->prox = NULL;
    comeco = n;
    fim = n;
  }
  else{
    n->prox = comeco;
    fim = n;
  } 


}

//desenfileirar
void desenfileirar()
{
  if(fim == NULL)
  {
    cout << "Essa lista não contém elementos";
  }
  else comeco = comeco->prox;

}

//listar
void listar()
{
  ponteiro_no aux = comeco;
  if (comeco == NULL)
  {
    cout << "Lista Vazia\n";
  }
  else 
  {
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

    cout << "1. Enfileirar\n" 
         << "2. Desenfileirar\n"
      << "3. Listar\n"
      << "0. Sair\n"   
      << "Digite uma opção: ";
    cin >> op;
    cout << endl;
    
    switch (op)
    {
      case 1: enfileirar(); break;
      case 2: desenfileirar(); break;
      case 3: listar(); break;
    }
  } while (op !=0);


}