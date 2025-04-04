#include <iostream>
#include <windows.h>
#include <string>
#include <thread>

// Código realizado em dupla por Gustavo Murai e Igor Murai

using namespace std;

// Função para posicionar o cursor no console
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    string mensagem;

    // Entrada da mensagem
    cout << "Digite uma mensagem: ";
    getline(cin, mensagem);

    int larguraConsole = 80;
    int posicaoInicialX = (larguraConsole - mensagem.length()) / 2;

    // Efeito cascata REAL: uma letra de cada vez, descendo da linha 5 até a 20
    for (size_t i = 0; i < mensagem.length(); i++) {
        for (int linha = 5; linha <= 20; linha++) {
            if (linha > 5) {
                gotoxy(posicaoInicialX + i, linha - 1);
                cout << " "; // Limpa posição anterior
            }

            gotoxy(posicaoInicialX + i, linha);
            cout << mensagem[i];
            this_thread::sleep_for(chrono::milliseconds(80));
        }
    }

    gotoxy(0, 22); // Move o cursor para fora do caminho
    return 0;
}
