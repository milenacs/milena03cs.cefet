#include <iostream>
using namespace std;

struct no{
  int info;
  struct no * prox;
};
typedef struct no * noPtr;

struct lista{
  noPtr inicio = NULL;
  noPtr fim = NULL;
  int tamanho;
};

struct lista * l = new lista;

/*void enfileirar()
{
  noPtr n = new no();
  cout << "Entre com o valor";
  cin >> n->info;
  if(l->inicio == NULL)
  {
    n->prox = NULL;
    l->inicio = n;
    l->fim = n;
  }
  else{
    
    l->fim = n;
  } 


}*/
void enqueue() {
    noPtr novoNo = new no; // Aloca memória para o novo nó
    if (novoNo == NULL) {
        printf("Erro: memória insuficiente.\n");
        return;
    }
    cin >> novoNo->info; // Atribui o valor ao novo nó
    novoNo->prox = NULL; // O novo nó será o último, portanto seu próximo é NULL

    if (l->inicio == NULL) {
        // Se a lista estiver vazia, o novo nó é tanto o início quanto o fim da lista
        l->inicio = novoNo;
        l->fim = novoNo;
    } else {
        // Caso contrário, adicionamos o novo nó ao final da lista
        l->fim->prox = novoNo;
        l->fim = novoNo;
    }
    l->tamanho++; // Incrementa o tamanho da lista
}

void dequeue(struct lista *lst) {
    if (lst->inicio == NULL) {
        printf("Erro: lista vazia.\n");
        return; // Retorno de erro, pois a lista está vazia
    }

    int valorRemovido = lst->inicio->info;
    noPtr temp = lst->inicio; // Armazena temporariamente o primeiro nó
    lst->inicio = lst->inicio->prox; // Atualiza o início da lista para o próximo nó
    free(temp); // Libera a memória do nó removido
    lst->tamanho--; // Decrementa o tamanho da lista

    if (lst->inicio == NULL) {
        // Se o início é NULL, significa que a lista está vazia, então o fim também deve ser NULL
        lst->fim = NULL;
    }

  
}


void listar()
{
  noPtr aux = l->inicio;
  if (l->inicio == NULL)
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
void desenfileirar()
{
  if(l->fim == NULL)
  {
    cout << "Essa lista não contém elementos";
  }
  else l->inicio = l->inicio->prox;

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
      case 1: enqueue(); break;
     // case 2: desenfileirar(); break;
      case 3: listar(); break;
    }
  } while (op !=0);
}