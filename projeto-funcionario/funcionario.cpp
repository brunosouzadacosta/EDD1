#include <iostream>
#include <string>
#include <vector>
#include <iomanip> 

using namespace std;

class Funcionario {
private:
    int prontuario;
    string nome;
    double salario;

public:
    Funcionario(int p, string n, double s) : prontuario(p), nome(n), salario(s) {}

    int getProntuario() { return prontuario; }
    string getNome() { return nome; }
    double getSalario() { return salario; }
};

// Retorna a posição do funcionário no vetor ou -1 se não encontrar
int buscarFuncionario(vector<Funcionario>& lista, int prontuarioDesejado) {
    for (int i = 0; i < lista.size(); i++) {
        if (lista[i].getProntuario() == prontuarioDesejado) {
            return i;
        }
    }
    return -1;
}

int main() {
    vector<Funcionario> listaFuncionarios;
    int opcao;

    do {
        cout << "\n===================================" << endl;
        cout << "      SISTEMA DE FUNCIONARIOS      " << endl;
        cout << "===================================" << endl;
        cout << " 1. Incluir" << endl;
        cout << " 2. Excluir" << endl;
        cout << " 3. Pesquisar" << endl;
        cout << " 4. Listar" << endl;
        cout << " 0. Sair" << endl;
        cout << "-----------------------------------" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1: { // INCLUIR
                int p;
                string n;
                double s;

                cout << "\n--- INCLUIR FUNCIONARIO ---" << endl;
                cout << "Prontuario: ";
                cin >> p;

                // Regra a: Não permitir prontuário duplicado
                if (buscarFuncionario(listaFuncionarios, p) != -1) {
                    cout << "[ERRO] Ja existe um funcionario com este prontuario!" << endl;
                } else {
                    cin.ignore(); // Limpa o buffer do teclado
                    cout << "Nome: ";
                    getline(cin, n);
                    cout << "Salario: R$ ";
                    cin >> s;

                    listaFuncionarios.push_back(Funcionario(p, n, s));
                    cout << "[SUCESSO] Funcionario cadastrado!" << endl;
                }
                break;
            }
            case 2: { // EXCLUIR
                int p;
                cout << "\n--- EXCLUIR FUNCIONARIO ---" << endl;
                cout << "Digite o Prontuario para exclusao: ";
                cin >> p;

                int indice = buscarFuncionario(listaFuncionarios, p);

                if (indice != -1) {
                    // Remove o item na posição encontrada
                    listaFuncionarios.erase(listaFuncionarios.begin() + indice);
                    cout << "[SUCESSO] Funcionario removido!" << endl;
                } else {
                    cout << "[ERRO] Funcionario nao encontrado." << endl;
                }
                break;
            }
            case 3: { // PESQUISAR
                int p;
                cout << "\n--- PESQUISAR FUNCIONARIO ---" << endl;
                cout << "Digite o Prontuario: ";
                cin >> p;

                int indice = buscarFuncionario(listaFuncionarios, p);

                if (indice != -1) {
                    cout << "\nFuncionario Encontrado:" << endl;
                    cout << "Nome:    " << listaFuncionarios[indice].getNome() << endl;
                    cout << "Salario: R$ " << fixed << setprecision(2) << listaFuncionarios[indice].getSalario() << endl;
                } else {
                    cout << "[ERRO] Funcionario nao encontrado." << endl;
                }
                break;
            }
            case 4: { // LISTAR
                cout << "\n--- LISTA DE FUNCIONARIOS ---" << endl;
                
                if (listaFuncionarios.empty()) {
                    cout << "Nenhum funcionario cadastrado." << endl;
                } else {
                    double totalSalarios = 0;

                    for (int i = 0; i < listaFuncionarios.size(); i++) {
                        cout << "Prontuario: " << listaFuncionarios[i].getProntuario() << " | ";
                        cout << "Nome: " << listaFuncionarios[i].getNome() << " | ";
                        cout << "Salario: R$ " << fixed << setprecision(2) << listaFuncionarios[i].getSalario() << endl;
                        
                        totalSalarios += listaFuncionarios[i].getSalario();
                    }

                    cout << "-----------------------------------" << endl;
                    cout << "TOTAL DE SALARIOS: R$ " << fixed << setprecision(2) << totalSalarios << endl;
                }
                break;
            }
            case 0: // SAIR
                cout << "\nSaindo do sistema... Ate logo!" << endl;
                break;
            default:
                cout << "\n[ERRO] Opcao invalida. Tente novamente." << endl;
        }

    } while (opcao != 0);

    return 0;
}
