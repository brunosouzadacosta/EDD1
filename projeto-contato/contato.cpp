#include <iostream>
#include <string>
#include <ctime> 

using namespace std;

class Data {
private:
    int dia;
    int mes;
    int ano;

public:
    Data() : dia(1), mes(1), ano(2000) {}

    // Construtor com parâmetros
    Data(int d, int m, int a) : dia(d), mes(m), ano(a) {}

    // Getter's e Setter's
    int getDia() { return dia; }
    void setDia(int d) { dia = d; }

    int getMes() { return mes; }
    void setMes(int m) { mes = m; }

    int getAno() { return ano; }
    void setAno(int a) { ano = a; }
};

class Contato {
private:
    string email;
    string nome;
    string telefone;
    Data dtnasc;

public:
    Contato() {}

    Contato(string e, string n, string t, Data d) : email(e), nome(n), telefone(t), dtnasc(d) {}

    string getEmail() { return email; }
    void setEmail(string e) { email = e; }

    string getNome() { return nome; }
    void setNome(string n) { nome = n; }

    string getTelefone() { return telefone; }
    void setTelefone(string t) { telefone = t; }

    Data getDtNasc() { return dtnasc; }
    void setDtNasc(Data d) { dtnasc = d; }

    int idade() {
        time_t t = time(nullptr);
        tm* tempoAtual = localtime(&t);

        // tm_year conta os anos a partir de 1900
        int anoAtual = tempoAtual->tm_year + 1900;
        // tm_mon conta os meses de 0 a 11
        int mesAtual = tempoAtual->tm_mon + 1;
        int diaAtual = tempoAtual->tm_mday;

        int idadeCalculada = anoAtual - dtnasc.getAno();

        if (mesAtual < dtnasc.getMes() || (mesAtual == dtnasc.getMes() && diaAtual < dtnasc.getDia())) {
            idadeCalculada--;
        }

        return idadeCalculada;
    }
};

int main() {
    const int TAMANHO = 5;
    Contato agenda[TAMANHO];

    cout << "=======================================" << endl;
    cout << "          CADASTRO DE CONTATOS         " << endl;
    cout << "=======================================" << endl;

    for (int i = 0; i < TAMANHO; i++) {
        string nome, email, telefone;
        int dia, mes, ano;

        cout << "\n--- Digite os dados do Contato " << (i + 1) << " ---" << endl;
        
        cout << "Nome: ";
        getline(cin, nome);
        
        cout << "E-mail: ";
        getline(cin, email);
        
        cout << "Telefone: ";
        getline(cin, telefone);
        
        cout << "Data de Nascimento (Dia): ";
        cin >> dia;
        cout << "Data de Nascimento (Mes): ";
        cin >> mes;
        cout << "Data de Nascimento (Ano): ";
        cin >> ano;

        cin.ignore();

        Data dataNascimento(dia, mes, ano);
        agenda[i] = Contato(email, nome, telefone, dataNascimento);
    }

    cout << "\n\n=======================================" << endl;
    cout << "          CONTATOS CADASTRADOS         " << endl;
    cout << "=======================================" << endl;

    for (int i = 0; i < TAMANHO; i++) {
        cout << "\nContato " << (i + 1) << ":" << endl;
        cout << "Nome:     " << agenda[i].getNome() << endl;
        cout << "E-mail:   " << agenda[i].getEmail() << endl;
        cout << "Telefone: " << agenda[i].getTelefone() << endl;
        cout << "Idade:    " << agenda[i].idade() << " anos" << endl;
    }

    return 0;
}
