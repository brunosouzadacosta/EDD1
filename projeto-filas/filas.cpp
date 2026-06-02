#include <iostream>

using namespace std;

class FilaVetor {
private:
    int dados[100]; 
    int frente;
    int tras;
    int quantidade;

public:
    FilaVetor() {
        frente = 0;
        tras = -1;
        quantidade = 0;
    }

    void enqueue(int valor) {
        if (quantidade < 100) {
            tras++;
            dados[tras] = valor;
            quantidade++;
        } else {
            cout << "[ERRO] Capacidade maxima da fila atingida!" << endl;
        }
    }

    int dequeue() {
        if (!isEmpty()) {
            int valor = dados[frente];
            frente++;
            quantidade--;
            return valor;
        }
        return -1;
    }

    bool isEmpty() {
        return quantidade == 0;
    }

    int size() {
        return quantidade;
    }
};

struct No {
    int dado;
    No* prox;
};

class FilaPonteiro {
private:
    No* frente;
    No* tras;
    int quantidade;

public:
    FilaPonteiro() {
        frente = nullptr;
        tras = nullptr;
        quantidade = 0;
    }

    void enqueue(int valor) {
        No* novoNo = new No;
        novoNo->dado = valor;
        novoNo->prox = nullptr;

        if (isEmpty()) {
            frente = novoNo;
        } else {
            tras->prox = novoNo;
        }
        tras = novoNo;
        quantidade++;
    }

    bool isEmpty() {
        return frente == nullptr;
    }

    int size() {
        return quantidade;
    }
};

int main() {
    FilaVetor senhasGeradas;      
    FilaPonteiro senhasAtendidas;  
    
    int opcao;
    int contadorSenhas = 0;

    do {
        cout << "\n===================================" << endl;
        cout << "      SISTEMA DE ATENDIMENTO       " << endl;
        cout << "===================================" << endl;
        
        cout << "Senhas aguardando: " << senhasGeradas.size() << endl;
        cout << "-----------------------------------" << endl;
        cout << " 1. Gerar senha" << endl;
        cout << " 2. Realizar atendimento" << endl;
        cout << " 0. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                contadorSenhas++;
                senhasGeradas.enqueue(contadorSenhas);
                cout << "[SUCESSO] Senha " << contadorSenhas << " gerada e enfileirada!" << endl;
                break;
            
            case 2:
                if (!senhasGeradas.isEmpty()) {
                    int senhaDaVez = senhasGeradas.dequeue();
                    senhasAtendidas.enqueue(senhaDaVez);
                    cout << "\n***********************************" << endl;
                    cout << "   CHAMANDO PARA ATENDIMENTO: " << senhaDaVez << endl;
                    cout << "***********************************" << endl;
                } else {
                    cout << "[AVISO] Nao ha senhas aguardando atendimento no momento." << endl;
                }
                break;
            
            case 0:
                if (!senhasGeradas.isEmpty()) {
                    cout << "[ERRO] O sistema nao pode ser encerrado! Ainda ha " << senhasGeradas.size() << " pessoa(s) na fila." << endl;
                    opcao = -1; 
                } else {
                    cout << "\n===================================" << endl;
                    cout << "   ENCERRANDO O EXPEDIENTE...      " << endl;
                    cout << "   Total de senhas atendidas: " << senhasAtendidas.size() << endl;
                    cout << "===================================" << endl;
                }
                break;
            
            default:
                cout << "[ERRO] Opcao invalida." << endl;
        }
    } while (opcao != 0);

    return 0;
}
