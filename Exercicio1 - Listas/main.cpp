#include <iostream>
#include "lista.h"

int main(int argc, char *argv[])
{
	cout << "Teste Lista Duplamente Encadeada" << endl;
    ListaDE<int> l;
    l.inserir(10);
    l.inserir(20);
    l.inserir(30);
	l.inserir(40);

	l.imprime();
	l.contido(40);
	l.remover(30);
	l.imprime();
	l.contido(30);

    cout << endl;
	cout << "Teste Fila" << endl;
	Fila<int> fila;
	fila.inserir(10);
	fila.inserir(20);
	fila.inserir(30);
	fila.inserir(40);

	fila.imprime();
	fila.contido(40);
	fila.remover();
	fila.imprime();
	fila.contido(10);

    cout << endl;
	cout << "Teste Pilha" << endl ;
	Pilha<int> pilha;
	pilha.inserir(10);
	pilha.inserir(20);
	pilha.inserir(30);
	pilha.inserir(40);

	pilha.imprime();
	pilha.contido(40);
	pilha.remover();
	pilha.imprime();
	pilha.contido(40);

	cout << endl;
    cout << "Teste Lista Duplamente Encadeada Circular" << endl;
    ListaDECircular<int> lc;
    lc.inserir(10);
    lc.inserir(20);
    lc.inserir(30);
	lc.inserir(40);

	lc.imprime();
	lc.contido(40);
	lc.remover(30);
	lc.imprime();
	lc.contido(70);

	return 0;
}
