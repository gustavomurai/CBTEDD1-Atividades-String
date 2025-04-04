#include <iostream>
#include <string>
#include <algorithm>

// Código realizado em dupla por Gustavo Murai e Igor Murai

using namespace std;

bool ehPalindromo(string texto) {
    // Remove espaços da string
    texto.erase(remove(texto.begin(), texto.end(), ' '), texto.end());

    // Deixa tudo maiúsculo (opcional, se quiser ignorar diferenças de maiúsculas/minúsculas)
    transform(texto.begin(), texto.end(), texto.begin(), ::toupper);

    // Cria uma cópia invertida
    string invertida = texto;
    reverse(invertida.begin(), invertida.end());

    return texto == invertida;
}

int main() {
    string mensagem;

    cout << "Digite uma mensagem: ";
    getline(cin, mensagem);

    if (ehPalindromo(mensagem)) {
        cout << "A mensagem e um palindromo!" << endl;
    } else {
        cout << "A mensagem nao e um palindromo." << endl;
    }

    return 0;
}
