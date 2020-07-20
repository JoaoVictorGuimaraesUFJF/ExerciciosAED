#include <iostream>
#include "lista.h"

using namespace std;

ListaDE<int> soma (ListaDE<int> l1, ListaDE<int> l2){
    ListaDE<int> l3;
    int aux, i, somador = 0;
    bool vai1 = false;
    for(i = l1.tam(); i > 0; i--){
        somador = l1.getChaveTail() + l2.getChaveTail();
        if(vai1)
            somador+=1;
        if(somador >= 10){
            aux = somador % 10;
            vai1 = true;
        }
        else{
           aux = somador;
           vai1 = false;
        }
        l1.remover_final();
        l2.remover_final();
        l3.inserir_inicio(aux);
        somador = 0;
    }
    if(vai1)
        l3.inserir_inicio(1);
    return l3;
}

int main()
{
    ListaDE<int> l1;
    ListaDE<int> l2;
    ListaDE<int> l3;

    cout << "Preenchendo as duas listas"<< endl;;
    for (int i = 0; i < 10; i++){
        l1.inserir(rand() % 10);
        l2.inserir(rand() % 10);
    }
    l1.imprime();
    l2.imprime();


    l3 = soma(l1,l2);
    cout << "Resultado da soma:" << endl;;
    l3.imprime();
    return 0;
}
