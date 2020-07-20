#ifndef _LISTA_H_
#define _LISTA_H_

using namespace std;

template<class T>
class NoLDE
{
private:
	T chave;
	NoLDE* ant;
	NoLDE* prox;
public:
	NoLDE(T chave) // construtor
	{
		this->chave = chave;
		this->ant = NULL;
		this->prox = NULL;
	}

	T getChave() // obtem o valor
	{
		return chave;
	}

	NoLDE* getProx() // obtem o proximo no
	{
		return prox;
	}

	NoLDE* getAnt() // obtem o no anterior
	{
		return ant;
	}

	void setProx(NoLDE* p) // seta o proximo no
	{
		prox = p;
	}

	void setAnt(NoLDE* p) // seta o no anterior
	{
		ant = p;
	}

	void setChave(T valor) // seta a chave
	{
		chave = valor;
	}
};

// classe Lista Duplamente Encadeada
template<class T>
class ListaDE
{
private:
    NoLDE<T> *head; // primeiro elemento
	NoLDE<T> *tail; // ultimo elemento
public:
	ListaDE()
	{
		// se nao passar elemento, entao cabeca e cauda sao NULL
		head = NULL;
		tail = NULL;
	}

	ListaDE(T chave)
	{
		// se passar elemento, entao cria novo no
		head = new NoLDE<T>(chave);
		tail = head;
	}

	virtual ~ListaDE() // destrutor
	{
		delete head;
		delete tail;
	}

    int tam()
    {
        if(vazia()) // se for vazia, entao retorna 0
            return 0;

        NoLDE<T>* h = head;
        int tam = 0;
        // percorre a lista
        while(h != NULL){
            h = h->getProx();
            tam++;
        }
        return tam;
    }

    T getChaveTail()
	{
        T chave = tail->getChave();
        return chave;
	}

	void inserir(T chave)
	{
		NoLDE<T>* novo_no = new NoLDE<T>(chave);

		if(vazia())
		{
			head = novo_no;
			tail = novo_no;
        }
		else
		{
			tail->setProx(novo_no);
            novo_no->setAnt(tail);
            tail = novo_no;
		}
	}

	void inserir_inicio(T chave)
	{
		NoLDE<T>* novo_no = new NoLDE<T>(chave);

        novo_no->setProx(head);
        novo_no->setAnt(NULL);
        tail = novo_no;
        if (head != NULL){ // lista não vazia
            head->setAnt(novo_no);
            tail = head;
        }
        head = novo_no;
	}

	void imprime() // imprime todos os elementos da lista
	{
		NoLDE<T>* h = head;

		if(vazia())
			cout << "A lista nao possui elementos!!\n";
		else
		{
			while(h) // percorre a lista
			{
				cout << h->getChave() << " ";
				h = h->getProx();
			}
			cout << endl;
		}
	}

	bool vazia() // verifica se a lista esta vazia
	{
		return (head == NULL);
	}

	// verifica se um elemento existe na lista
	bool contido(T chave)
	{
		NoLDE<T>* h = head;

		while(h)
		{
			if(h->getChave() == chave){
                cout << "Possui o elemento: " << chave << endl;
				return true;
            }
			h = h->getProx();
		}
		cout << "Não possui o elemento: " << chave << endl;
		return false;
	}

	void remover(T chave)
	{
        NoLDE<T>* aux = head;
        if(vazia()){
            cout << "Lista vazia" << endl;
            return;
        }
        while(aux != NULL && aux->getChave() != chave){
                aux = aux->getProx();
        }
        if(aux == NULL){
            cout << "Chave nao encontrada" << endl;
            return;
        }
        if(aux->getAnt() == NULL){ //1 elemento
            head = aux->getProx();
        }
        else{
            aux->getAnt()->setProx(aux->getProx());
        }
        if(aux->getProx()!= NULL){ //nao e o ultimo
            aux->getProx()->setAnt(aux->getAnt());
        }
        delete aux;
    }

    void remover_final()
	{
        NoLDE<T>* aux = head;
        if(vazia()){
            cout << "Lista vazia" << endl;
            return;
        }
        while(aux->getProx() != NULL){
            aux = aux->getProx();
        }
        if(aux->getAnt() == NULL){ //1 elemento
            head = aux->getProx();
        }
        else{
            aux->getAnt()->setProx(NULL);
        }
        delete aux;
    }
};

#endif
