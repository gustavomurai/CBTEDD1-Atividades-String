#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

// Código realizado em dupla por Gustavo Murai e Igor Murai

using namespace std;

string formatarNome(string linha) {
    vector<string> palavras;
    stringstream ss(linha);
    string palavra;

    // Quebra a linha em palavras
    while (ss >> palavra) {
        palavras.push_back(palavra);
    }

    if (palavras.size() < 2) {
        return linha; // Se só tiver um nome, retorna como está
    }

    string sobrenome = palavras.back(); // Última palavra
    palavras.pop_back(); // Remove o sobrenome do vetor

    // Junta o restante do nome
    string restante;
    for (size_t i = 0; i < palavras.size(); ++i) {
        restante += palavras[i];
        if (i < palavras.size() - 1) restante += " ";
    }

    return sobrenome + ", " + restante;
}

int main() {
    ifstream arquivo("Nomes.txt"); // Certifique-se de que o arquivo está no mesmo diretório
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo 'Nomes.txt'." << endl;
        return 1;
    }

    string linha;
    cout << "Nomes formatados para estilo de agenda:\n" << endl;
    
    while (getline(arquivo, linha)) {
        if (!linha.empty()) {
            cout << formatarNome(linha) << endl;
        }
    }

    arquivo.close();
    return 0;
}
