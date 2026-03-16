#include <iostream>
#include <iomanip>

using namespace std;

const int NUM_FILEIRAS = 15;
const int NUM_POLTRONAS = 40;

int main() {
    char teatro[NUM_FILEIRAS][NUM_POLTRONAS];
    
    int lugaresOcupados = 0;
    double valorBilheteria = 0.0;
    int opcao;

    for (int i = 0; i < NUM_FILEIRAS; i++) {
        for (int j = 0; j < NUM_POLTRONAS; j++) {
            teatro[i][j] = '.';
        }
    }

    do {
        cout << "\n===================================\n";
        cout << "        SISTEMA DE BILHETERIA        \n";
        cout << "===================================\n";
        cout << "0. Finalizar\n";
        cout << "1. Reservar poltrona\n";
        cout << "2. Mapa de ocupacao\n";
        cout << "3. Faturamento\n";
        cout << "===================================\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 0:
                cout << "\nEncerrando o sistema. Ate logo!\n";
                break;

            case 1: {
                int fileira, poltrona;
                cout << "\n--- Reserva de Poltrona ---\n";
                cout << "Informe a fileira (1 a " << NUM_FILEIRAS << "): ";
                cin >> fileira;
                cout << "Informe a poltrona (1 a " << NUM_POLTRONAS << "): ";
                cin >> poltrona;

                if (fileira < 1 || fileira > NUM_FILEIRAS || poltrona < 1 || poltrona > NUM_POLTRONAS) {
                    cout << "ERRO: Fileira ou poltrona invalida! Tente novamente.\n";
                } else {
                    int indiceFileira = fileira - 1;
                    int indicePoltrona = poltrona - 1;

                    if (teatro[indiceFileira][indicePoltrona] == '#') {
                        cout << "ALERTA: Este lugar ja se encontra ocupado!\n";
                    } else {
                        teatro[indiceFileira][indicePoltrona] = '#';
                        lugaresOcupados++;

                        if (fileira >= 1 && fileira <= 5) {
                            valorBilheteria += 50.00;
                        } else if (fileira >= 6 && fileira <= 10) {
                            valorBilheteria += 30.00;
                        } else if (fileira >= 11 && fileira <= 15) {
                            valorBilheteria += 15.00;
                        }

                        cout << "SUCESSO: Reserva efetuada!\n";
                    }
                }
                break;
            }

            case 2:
                cout << "\n--- Mapa de Ocupacao ---\n";
                cout << "Legenda: '.' (Lugar Vago) | '#' (Lugar Ocupado)\n\n";
                
                cout << "     ";
                for (int j = 1; j <= NUM_POLTRONAS; j++) {
                    if (j % 10 == 0) cout << j / 10;
                    else cout << " ";
                }
                cout << "\n     ";
                for (int j = 1; j <= NUM_POLTRONAS; j++) {
                    cout << j % 10;
                }
                cout << "\n";

                for (int i = 0; i < NUM_FILEIRAS; i++) {
                    cout << "F" << setfill('0') << setw(2) << i + 1 << " |";
                    for (int j = 0; j < NUM_POLTRONAS; j++) {
                        cout << teatro[i][j];
                    }
                    cout << "|\n";
                }
                break;

            case 3:
                cout << "\n--- Faturamento ---\n";
                cout << "Qtde de lugares ocupados:\t" << lugaresOcupados << "\n";
                
                cout << fixed << setprecision(2);
                cout << "Valor da bilheteria:\t\tR$ " << valorBilheteria << "\n";
                break;

            default:
                cout << "\nERRO: Opcao invalida! Digite um numero de 0 a 3.\n";
                break;
        }

    } while (opcao != 0);

    return 0;
}