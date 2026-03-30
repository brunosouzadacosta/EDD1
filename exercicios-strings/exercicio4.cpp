#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>

using namespace std;

int main() {
    ifstream arquivo("nomes.txt");
    
    if (!arquivo.is_open()) {
        cout << "Erro: Arquivo 'nomes.txt' nao encontrado!" << endl;
        return 1;
    }

    string linha;
    cout << "--- FORMATO CITACAO BIBLIOGRAFICA ---" << endl;
    
    while (getline(arquivo, linha)) {
        if (linha.empty()) continue;

        stringstream ss(linha);
        string palavra;
        vector<string> palavras;

        while (ss >> palavra) {
            palavras.push_back(palavra);
        }

        if (palavras.size() > 1) {
            // Pega o último nome e transforma em MAIÚSCULO
            string ultimo = palavras.back();
            for (char &c : ultimo) {
                c = toupper(c);
            }
            
            // Imprime o "SOBRENOME, Nome "
            cout << ultimo << ", " << palavras[0] << " ";
            
            // Abrevia os nomes do meio
            for (size_t i = 1; i < palavras.size() - 1; ++i) {
                cout << (char)toupper(palavras[i][0]) << ". ";
            }
            cout << endl;
            
        } else if (palavras.size() == 1) {
            // Se tiver só um nome, deixa ele todo maiúsculo
            string unico = palavras[0];
            for (char &c : unico) c = toupper(c);
            cout << unico << endl;
        }
    }
    
    arquivo.close();
    return 0;
}