#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <iomanip>

using namespace std;

string formatarNotacao(string carta) {
    return string(1, carta[0]) + "-" + carta.substr(1, 2) + "-" + string(1, carta[3]);
}

string descreverCarta(string carta) {
    string naipes[] = {"", "Copas", "Paus", "Ouro", "Espada"};
    int n = carta[0] - '0';
    int num = stoi(carta.substr(1, 2));
    string b = string(1, carta[3]);

    string numStr;
    if (num == 1) numStr = "Ás";
    else if (num == 11) numStr = "Valete";
    else if (num == 12) numStr = "Dama";
    else if (num == 13) numStr = "Rei";
    else numStr = to_string(num);

    return numStr + " de " + naipes[n] + " (Baralho " + b + ")";
}

int main() {
    string baralho[2][52];
    string mao[4][11];
    
    bool disponivel[2][52]; 

    for (int b = 0; b < 2; ++b) {
        int cardIndex = 0;
        for (int naipe = 1; naipe <= 4; ++naipe) {
            for (int num = 1; num <= 13; ++num) {
                // Montando a string N-XX-B sem os traços (ex: 1011)
                string strNaipe = to_string(naipe);
                string strNum = (num < 10 ? "0" : "") + to_string(num);
                string strBaralho = to_string(b + 1);
                
                baralho[b][cardIndex] = strNaipe + strNum + strBaralho;
                disponivel[b][cardIndex] = true; 
                cardIndex++;
            }
        }
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distBaralho(0, 1);
    uniform_int_distribution<> distCarta(0, 51);

    for (int j = 0; j < 4; ++j) {
        for (int c = 0; c < 11; ++c) {
            int bSorteado, cSorteada;
            
            do {
                bSorteado = distBaralho(gen);
                cSorteada = distCarta(gen);
            } while (!disponivel[bSorteado][cSorteada]);

            mao[j][c] = baralho[bSorteado][cSorteada];
            disponivel[bSorteado][cSorteada] = false;
        }
    }

    cout << "=======================================" << endl;
    cout << "          PROJETO BURACO               " << endl;
    cout << "=======================================\n" << endl;

    for (int j = 0; j < 4; ++j) {
        cout << "--- Mão do Jogador " << (j + 1) << " ---" << endl;
        for (int c = 0; c < 11; ++c) {
            string cartaMao = mao[j][c];
            cout << "Carta " << setw(2) << setfill('0') << (c + 1) << ": " 
                 << "[" << cartaMao << "] -> " 
                 << formatarNotacao(cartaMao) << " (" 
                 << descreverCarta(cartaMao) << ")" << endl;
        }
        cout << endl;
    }

    return 0;
}