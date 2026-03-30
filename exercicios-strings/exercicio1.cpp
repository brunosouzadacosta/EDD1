#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

// Função clássica para mover o cursor no console do Windows
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    string msg;
    
    // Limpa a tela
    system("cls"); 
    
    cout << "Digite uma mensagem: ";
    getline(cin, msg);
    
    system("cls");

    // O console padrão geralmente tem 80 colunas de largura. 
    // Calculamos o 'x' para centralizar a mensagem.
    int startX = (80 - msg.length()) / 2;
    if (startX < 0) startX = 0;

    // Apresenta a mensagem na linha 5
    gotoxy(startX, 5);
    cout << msg;
    
    // Pequena pausa antes de começar a cair
    Sleep(1000); 

    // Efeito cascata: desce letra por letra
    for (int i = 0; i < msg.length(); i++) {
        if (msg[i] == ' ') {
            // Se for espaço, apenas posiciona na linha 20 e segue
            gotoxy(startX + i, 20);
            cout << " ";
            continue; 
        }

        // Faz a letra atual cair da linha 5 até a 20
        for (int y = 5; y < 20; y++) {
            // Apaga a letra na posição atual
            gotoxy(startX + i, y);
            cout << " ";
            
            // Desenha a letra na linha de baixo
            gotoxy(startX + i, y + 1);
            cout << msg[i];
            
            // Pausa de 40 milissegundos para dar o efeito visual de animação
            Sleep(40); 
        }
    }

    // Joga o cursor lá para baixo para o programa não encerrar em cima da mensagem
    gotoxy(0, 22);
    return 0;
}