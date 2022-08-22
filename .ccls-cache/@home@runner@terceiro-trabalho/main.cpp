#include <iostream>
#include <vector>
#include <chrono>
using namespace std;


class fila {
public:
  vector<int> popula(){
    vector<int> fila;
    for (int i=0;i<1000000;i++){
      int v1 = rand() % 100;
      fila.push_back(v1);
    }
    return fila;
  }
  void soma(vector<int> fila){
    int v1 = fila.at(0);
    int v2 = fila.at(1);
    fila.erase(fila.begin(),fila.begin()+1);
    fila.push_back(v1+v1);
  }
  void procura(vector<int> fila){
    int v1 = rand() % 1000;
    for (int i=0;i<fila.size();i++){
      if (fila[i]==v1) break;
    }
  }
  void soma_inverte(vector<int> fila){
    vector<int> tmp;
    int size = fila.size();
    for (int i=0;i<size;i++){
      tmp.push_back(fila.back());
      fila.pop_back();
    }
    int v1 = tmp.at(0);
    int v2 = tmp.at(1);
    tmp.erase(tmp.begin(),tmp.begin()+1);
    tmp.push_back(v1+v1);
  }
};

int main() {
  auto inicio = std::chrono::high_resolution_clock::now();
  for (int i=0;i<50;i++){
    vector<int> v1 = fila().popula();
    fila().soma(v1);
    fila().procura(v1);
    fila().soma_inverte(v1);
  }
  auto resultado = std::chrono::high_resolution_clock::now() - inicio;
  long long liliseconds =std::chrono::duration_cast<std::chrono::milliseconds>(resultado).count();

  cout << "tempo passado: " << liliseconds <<" milisegundos"<< endl;
}
