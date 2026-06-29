#include <iostream>

using namespace std;
struct NoSenha {
    int senha;
    NoSenha* prox;
};

class FilaPonteiro {
private:
    NoSenha* frente;
    NoSenha* tras;
    int quantidade;

public:
    FilaPonteiro() {
        frente = nullptr;
        tras = nullptr;
        quantidade = 0;
    }

    void enqueue(int valor) {
        NoSenha* novo = new NoSenha;
        novo->senha = valor;
        novo->prox = nullptr;
        if (isEmpty()) {
            frente = novo;
        } else {
            tras->prox = novo;
        }
        tras = novo;
        quantidade++;
    }

    int dequeue() {
        if (!isEmpty()) {
            int valor = frente->senha;
            NoSenha* removido = frente;
            frente = frente->prox;
            if (frente == nullptr) tras = nullptr; 
            delete removido;
            quantidade--;
            return valor;
        }
        return -1;
    }

    bool isEmpty() { return frente == nullptr; }
    int size() { return quantidade; }

    void listar() {
        if (isEmpty()) {
            cout << " Nenhuma senha atendida por este guiche ainda." << endl;
            return;
        }
        NoSenha* atual = frente;
        cout << " Senhas: ";
        while (atual != nullptr) {
            cout << atual->senha << " ";
            atual = atual->prox;
        }
        cout << endl;
    }
};

struct Guiche {
    int id;
    FilaPonteiro senhasAtendidas; 
    Guiche* prox;
};

class ListaGuiches {
private:
    Guiche* inicio;
    int qtdGuiches;

public:
    ListaGuiches() {
        inicio = nullptr;
        qtdGuiches = 0;
    }

    bool existe(int id) {
        Guiche* atual = inicio;
        while (atual != nullptr) {
            if (atual->id == id) return true;
            atual = atual->prox;
        }
        return false;
    }

    void adicionarGuiche(int id) {
        if (existe(id)) {
            cout << "[ERRO] Ja existe um guiche com o ID " << id << "!" << endl;
            return;
        }

        Guiche* novo = new Guiche;
        novo->id = id;
        novo->prox = inicio; 
        inicio = novo;
        qtdGuiches++;
        cout << "[SUCESSO] Guiche " << id << " aberto com sucesso!" << endl;
    }

    Guiche* buscarGuiche(int id) {
        Guiche* atual = inicio;
        while (atual != nullptr) {
            if (atual->id == id) return atual;
            atual = atual->prox;
        }
        return nullptr;
    }

    int size() { return qtdGuiches; }

    int totalAtendimentosGeral() {
        int total = 0;
        Guiche* atual = inicio;
        while (atual != nullptr) {
            total += atual->senhasAtendidas.size();
            atual = atual->prox;
        }
        return total;
    }
};

int main() {
    FilaPonteiro senhasGeradas;
    ListaGuiches listaGuiches;
    
    int opcao;
    int contadorSenhas = 0;

    do {
        cout << "\n=========================================" << endl;
        cout << "      SISTEMA DE ATENDIMENTO V2.0        " << endl;
        cout << "=========================================" << endl;
        cout << " Senhas aguardando: " << senhasGeradas.size() << endl;
        cout << " Guiches abertos:   " << listaGuiches.size() << endl;
        cout << "-----------------------------------------" << endl;
        cout << " 1. Gerar senha" << endl;
        cout << " 2. Abrir guiche" << endl;
        cout << " 3. Realizar atendimento" << endl;
        cout << " 4. Listar senhas atendidas" << endl;
        cout << " 0. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                contadorSenhas++;
                senhasGeradas.enqueue(contadorSenhas);
                cout << "[SUCESSO] Senha " << contadorSenhas << " gerada e enfileirada!" << endl;
                break;
            
            case 2: { 
                int id;
                cout << "\n--- ABRIR GUICHE ---" << endl;
                cout << "Digite o ID numérico do novo guiche: ";
                cin >> id;
                listaGuiches.adicionarGuiche(id);
                break;
            }
            
            case 3: {
                cout << "\n--- REALIZAR ATENDIMENTO ---" << endl;
                if (senhasGeradas.isEmpty()) {
                    cout << "[AVISO] Nao ha senhas aguardando atendimento." << endl;
                    break;
                }
                if (listaGuiches.size() == 0) {
                    cout << "[ERRO] Nenhum guiche aberto. Abra um guiche primeiro (Opcao 2)." << endl;
                    break;
                }
                
                int id;
                cout << "Digite o ID do guiche que vai chamar a senha: ";
                cin >> id;
                
                Guiche* guicheAtual = listaGuiches.buscarGuiche(id);
                if (guicheAtual != nullptr) {
                    int senhaDaVez = senhasGeradas.dequeue(); 
                    guicheAtual->senhasAtendidas.enqueue(senhaDaVez); 
                    
                    cout << "\n***********************************" << endl;
                    cout << " GUICHE " << id << " CHAMANDO A SENHA: " << senhaDaVez << endl;
                    cout << "***********************************" << endl;
                } else {
                    cout << "[ERRO] Guiche ID " << id << " nao encontrado." << endl;
                }
                break;
            }
            
            case 4: {
                int id;
                cout << "\n--- LISTAR SENHAS ATENDIDAS ---" << endl;
                cout << "Digite o ID do guiche: ";
                cin >> id;
                
                Guiche* guicheBusca = listaGuiches.buscarGuiche(id);
                if (guicheBusca != nullptr) {
                    cout << "\n[ Relatorio do Guiche " << id << " ]" << endl;
                    guicheBusca->senhasAtendidas.listar();
                    cout << "Total atendido pelo guiche: " << guicheBusca->senhasAtendidas.size() << endl;
                } else {
                    cout << "[ERRO] Guiche ID " << id << " nao encontrado." << endl;
                }
                break;
            }
            
            case 0:
                if (!senhasGeradas.isEmpty()) {
                    cout << "[ERRO] O sistema nao pode ser encerrado! Ainda ha " << senhasGeradas.size() << " pessoa(s) na fila." << endl;
                    opcao = -1; 
                } else {
                    cout << "\n=========================================" << endl;
                    cout << "       ENCERRANDO O EXPEDIENTE...        " << endl;
                    cout << "   Total GERAL de senhas atendidas: " << listaGuiches.totalAtendimentosGeral() << endl;
                    cout << "=========================================" << endl;
                }
                break;
            
            default:
                cout << "[ERRO] Opcao invalida." << endl;
        }
    } while (opcao != 0);

    return 0;
}
