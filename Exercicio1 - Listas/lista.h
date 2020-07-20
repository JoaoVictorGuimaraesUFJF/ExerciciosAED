#ifndef _LISTA_H_
#define _LISTA_H_

using namespace std;

// classe no
template<class T>
class NoLSE
{
private:
	T chave;
	NoLSE* prox;
public:
	NoLSE(T chave) // construtor
	{
		this->chave = chave;
		this->prox = NULL;
	}

	T getChave() // obtem o chave
	{
		return chave;
	}

	NoLSE* getProx() // obtem o proximo no
	{
		return prox;
	}

	void setProx(NoLSE* p) // seta o proximo no
	{
		prox = p;
	}

	void setChave(T valor) // seta a chave
	{
		chave = valor;
	}
};

// classe Fila com Lista Simplesmente Encadeada
template<class T>
class Fila
{
private:
	NoLSE<T> *head; // primeiro elemento
	NoLSE<T> *tail; // ultimo elemento
public:
	Fila()
	{
		// se nao passar elemento, entao cabeca e cauda sao NULL
		head = NULL;
		tail = NULL;
	}

	Fila(T chave)
	{
		// se passar elemento, entao cria novo no
		head = new NoLSE<T>(chave);
		tail = head;
	}

	virtual ~Fila() // destrutor
	{
		delete head;
		delete tail;
	}

	void imprime() // imprime todos os elementos da fila
	{
		NoLSE<T>* h = head;
		if(vazia())
			cout << "A fila esta vazia!\n";
		else
		{
			while(h) // percorre a fila
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

    // verifica se um elemento existe na fila
	bool contido(T chave)
	{
		NoLSE<T>* h = head;

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

	void inserir(T chave)
	{
		NoLSE<T>* novo_no = new NoLSE<T>(chave);

		if(vazia())
		{
			head = novo_no;
			tail = novo_no;
		}
		else
		{
			tail->setProx(novo_no);
			tail = novo_no;
		}
	}

	void remover()
	{
		if(!vazia())
		{
			if(head->getProx() == NULL) // 1 elemento
				head = NULL;
			else { // 2 elementos
                NoLSE<T>* h = head;
                head = h->getProx();
                delete h;
            }

		}
	}

};

// classe Pilha com Lista Simplesmente Encadeada
template<class T>
class Pilha
{
private:
	NoLSE<T> *head; // primeiro elemento
	NoLSE<T> *tail; // ultimo elemento
public:
	Pilha()
	{
		// se nao passar elemento, entao cabeca e cauda sao NULL
		head = NULL;
		tail = NULL;
	}

	Pilha(T chave)
	{
		// se passar elemento, entao cria novo no
		head = new NoLSE<T>(chave);
		tail = head;
	}

	virtual ~Pilha() // destrutor
	{
		delete head;
		delete tail;
	}

	void imprime() // imprime todos os elementos da fila
	{
		NoLSE<T>* h = head;
		if(vazia())
			cout << "A pilha esta vazia!\n";
		else
		{
			while(h) // percorre a fila
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

    // verifica se um elemento existe na pilha
	bool contido(T chave)
	{
		NoLSE<T>* h = head;

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

	void inserir(T chave)
	{
		NoLSE<T>* novo_no = new NoLSE<T>(chave);

		if(vazia())
		{
			head = novo_no;
			tail = novo_no;
		}
		else
		{
			tail->setProx(novo_no);
			tail = novo_no;
		}
	}

	void remover()
	{
		if(!vazia())
		{
            NoLSE<T>* aux = head;
			if(aux->getProx() == NULL) //1 elemento
				aux = NULL;
			else {
                while(aux->getProx()->getProx() != NULL){ // Percorre até chegar no penultimo
                    aux = aux->getProx();
                }
                aux->setProx(NULL);
            }
            delete aux->getProx();
		}
	}
};

//No Lista Duplamente Encadeada
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
};

// classe Lista Duplamente Encadeada Circular
template<class T>
class ListaDECircular
{
private:
	NoLDE<T> *head; // primeiro elemento
	NoLDE<T> *tail; // Ultimo elemento

public:
	ListaDECircular()
	{
		// se nao passar elemento, entao cabeca e cauda sao NULL
		head = NULL;
		tail = NULL;
	}

	ListaDECircular(T chave)
	{
		// se passar elemento, entao cria novo no
		head = new NoLDE<T>(chave);
		tail = head;
	}

	virtual ~ListaDECircular() // destrutor
	{
		delete head;
		delete tail;
	}

	void inserir(T chave)
	{
		NoLDE<T>* novo_no = new NoLDE<T>(chave);

		if(vazia())
		{
			head = novo_no;
			tail = novo_no;
			novo_no->setAnt(novo_no);
			novo_no->setProx(novo_no);
        }
		else
		{
			tail->setProx(novo_no);
			novo_no->setAnt(tail);
			tail = novo_no;
            novo_no->setProx(head);
		}
	}

	void imprime() // imprime todos os elementos da lista
	{
		NoLDE<T>* h = head;

		if(vazia())
			cout << "A lista nao possui elementos!\n";
		else
		{
			while(h) // percorre a lista
			{
				cout << h->getChave() << " ";
				h = h->getProx();
				if(h == head){
                    cout << endl;
                    return;
                }
			}

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
			if(h == head){
                cout << "Não possui o elemento: " << chave << endl;
                return false;
            }
		}
	}

	void remover(T chave)
	{
        NoLDE<T>* aux = head;
        if(vazia()){
            cout << "Lista vazia" << endl;
            return;
        }
        if(aux->getChave() == chave){ //Valor no 1 elemento
            if(aux == aux->getProx()){ //Lista fica vazia após a remoção ?
                head = NULL;
            }
            else{
                tail->setProx(head->getProx());
                head = head->getProx();
            }
            delete aux;
        }

        NoLDE<T>* ant = aux;
        aux = aux->getProx();

        while(aux != head && aux->getChave() != chave){
            ant = aux;
            aux = aux->getProx();
        }
        if(aux == head){
            cout << "Chave nao encontrada" << endl;
            return;
        }
        ant->setProx(aux->getProx());
        delete aux;
    }
};
#endif
