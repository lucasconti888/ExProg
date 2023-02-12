#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

// Indica o tamanho da tabela;
const int size = 200;
// Cria variáveis para a tabela;
class InsertTable {
public:
  int n;
  int v;
  InsertTable(int n, int v) {
    this->n = n;
    this->v = v;
  }
};

class HashMapTable {
private:
  InsertTable **t;

public:
  // Cria a tabela;
  HashMapTable() {
    t = new InsertTable *[size];
    for (int i = 0; i < size; i++) {
      t[i] = NULL;
    }
  }

  int HashFunc(int n) { return n % size; }
  // Define os valores da tabela;
  void Insert(int n, int v) {
    int h = HashFunc(n);
    while (t[h] != NULL && t[h]->n != n) {
      h = HashFunc(h + 1);
    }
    if (t[h] != NULL)
      delete t[h];
    t[h] = new InsertTable(n, v);
  }
  // Faz a busca pelo valor determinado;
  int SearchKey(int n) {
    int h = HashFunc(n);
    while (t[h] != NULL && t[h]->n != n) {
      h = HashFunc(h + 1);
    }
    if (t[h] == NULL)
      return -1;
    else
      return t[h]->v;
  }
  // Remove da tabela;
  void Remove(int n) {
    int h = HashFunc(n);
    while (t[h] != NULL) {
      if (t[h]->n == n)
        break;
      h = HashFunc(h + 1);
    }
    if (t[h] == NULL) {
      cout << "Não existe " << n << endl;
      return;
    } else {
      delete t[h];
    }

    cout << "Valor deletado" << endl;
  }
  ~HashMapTable() {
    for (int i = 0; i < size; i++) {
      if (t[i] != NULL)
        delete t[i];
      delete[] t;
    }
  }
};
int main() {
  HashMapTable hash;
  int n, v;
  int c;
  while (1) {
    cout << "1.Inserir valor na tabela" << endl;
    cout << "2.Pesquisar pela chave" << endl;
    cout << "3.Deletar elemento" << endl;
    cout << "4.Sair" << endl;
    cout << "Digite o número da ação: ";
    cin >> c;
    switch (c) {
    case 1:
      cout << "Digite o elemento que será inserido: ";
      cin >> v;
      cout << "Digite a chave do elemento que será inserido: ";
      cin >> n;
      hash.Insert(n, v);
      break;
    case 2:
      cout << "Digite a chave do elemento que deseja pesquisar: ";
      cin >> n;
      if (hash.SearchKey(n) == -1) {
        cout << "Não existe elemento com essa chave" << n << endl;
        continue;
      } else {
        cout << "O elemento na chave é " << n << " : ";
        cout << hash.SearchKey(n) << endl;
      }
      break;
    case 3:
      cout << "Digite a chave do elemento que deseja excluir: ";
      cin >> n;
      hash.Remove(n);
      break;
    case 4:
      exit(1);
    default:
      cout << "\nEnter correct option\n";
    }
  }
  return 0;
}
