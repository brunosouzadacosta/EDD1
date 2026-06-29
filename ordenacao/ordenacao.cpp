#include <iostream>

using namespace std;

void imprimirVetor(int arr[], int tamanho) {
    cout << "[ ";
    for (int i = 0; i < tamanho; i++) {
        cout << arr[i] << (i < tamanho - 1 ? ", " : " ");
    }
    cout << "]" << endl;
}

void insertionSort(int arr[], int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        int chave = arr[i]; 
        int j = i - 1;

        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        
        arr[j + 1] = chave;
    }
}

int main() {
    int v[] = {49, 38, 58, 87, 34, 93, 26, 13};
    
    int tamanho = sizeof(v) / sizeof(v[0]);

    cout << "=======================================" << endl;
    cout << "          ORDENACAO DE VETOR           " << endl;
    cout << "=======================================\n" << endl;

    cout << "Vetor ANTES da ordenacao:" << endl;
    imprimirVetor(v, tamanho);

    insertionSort(v, tamanho);

    cout << "\nVetor APOS a ordenacao (Insertion Sort):" << endl;
    imprimirVetor(v, tamanho);
    
    cout << "\nProcesso finalizado." << endl;

    return 0;
}
