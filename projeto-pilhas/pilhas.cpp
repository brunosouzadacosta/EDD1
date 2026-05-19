#include <iostream>

using namespace std;

class PilhaVetor {
private:
    int dados[30]; 
    int topo_idx;

public:
    PilhaVetor() {
        topo_idx = -1; 
    }

    void push(int valor) {
        if (topo_idx < 29) {
            dados[++topo_idx] = valor;
        }
    }

    int pop() {
        if (!isEmpty()) {
            return dados[topo_idx--];
        }
        return -1;
    }

    int top() {
        if (!isEmpty()) {
            return dados[topo_idx];
        }
        return -1;
    }

    bool isEmpty() {
        return topo_idx == -1;
    }
};

struct No {
    int dado;
    No* prox;
};

class PilhaLista {
private:
    No* topo_ptr;

public:
    PilhaLista() {
        topo_ptr = nullptr; 
    }

    void push(int valor) {
        No* novoNo = new No;
        novoNo->dado = valor;
        novoNo->prox = topo_ptr;
        topo_ptr = novoNo;
    }

    int pop() {
        if (!isEmpty()) {
            int valor = topo_ptr->dado;
            No* noRemovido = topo_ptr;
            topo_ptr = topo_ptr->prox;
            delete noRemovido; 
            return valor;
        }
        return -1;
    }

    int top() {
        if (!isEmpty()) {
            return topo_ptr->dado;
        }
        return -1;
    }

    bool isEmpty() {
        return topo_ptr == nullptr;
    }
};

int main() {

    const int TOTAL_NUMEROS = 30; 

    PilhaVetor pilhaPares;   
    PilhaLista pilhaImpares;  

    int numeroAtual;
    int numeroAnterior = 0; 

    cout << "=======================================" << endl;
    cout << "      PILHAS: CRESCENTE E DECRESCENTE  " << endl;
    cout << "=======================================\n" << endl;

    for (int i = 0; i < TOTAL_NUMEROS; i++) {
        bool valido = false;

        do {
            cout << "Digite o " << (i + 1) << "o numero inteiro: ";
            cin >> numeroAtual;

            if (i > 0 && numeroAtual <= numeroAnterior) {
                cout << "[ERRO] O numero deve ser estritamente maior que " << numeroAnterior << ". Tente novamente.\n";
            } else {
                valido = true;
            }
        } while (!valido);

        numeroAnterior = numeroAtual;

        if (numeroAtual % 2 == 0) {
            pilhaPares.push(numeroAtual);
        } else {
            pilhaImpares.push(numeroAtual);
        }
    }

    cout << "\n=======================================" << endl;
    cout << "   NUMEROS DESEMPILHADOS (DECRESCENTE) " << endl;
    cout << "=======================================" << endl;

    while (!pilhaPares.isEmpty() || !pilhaImpares.isEmpty()) {
        
        if (!pilhaPares.isEmpty() && !pilhaImpares.isEmpty()) {
            if (pilhaPares.top() > pilhaImpares.top()) {
                cout << pilhaPares.pop() << " ";
            } else {
                cout << pilhaImpares.pop() << " ";
            }
        } 

        else if (!pilhaPares.isEmpty()) {
            cout << pilhaPares.pop() << " ";
        } 

        else {
            cout << pilhaImpares.pop() << " ";
        }
    }

    cout << "\n\nProcesso finalizado com sucesso." << endl;

    return 0;
}
