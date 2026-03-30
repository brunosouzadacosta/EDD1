#include <iostream>
#include <string>
#include <algorithm> // Necessário para a função reverse()

using namespace std;

int main() {
    string msg, limpa, reversa;
    
    cout << "Digite uma mensagem: ";
    getline(cin, msg);

    // Remove os espaços e converte tudo para maiúsculo
    for (char c : msg) {
        if (c != ' ') {
            limpa += toupper(c);
        }
    }

    // Cria uma cópia da string limpa e inverte ela
    reversa = limpa;
    reverse(reversa.begin(), reversa.end());

    cout << "\nMensagem original: " << msg << endl;
    
    // Verifica se a string limpa é igual a ela mesma invertida
    if (limpa == reversa && !limpa.empty()) {
        cout << "Resultado: EH UM PALINDROMO!" << endl;
    } else {
        cout << "Resultado: NAO EH UM PALINDROMO." << endl;
    }

    return 0;
}