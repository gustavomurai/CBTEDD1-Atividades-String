#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>

// Código realizado em dupla por Gustavo Murai e Igor Murai

using namespace std;

// Função para converter uma string para maiúsculas
string toUpper(string str) {
    for (char &c : str) {
        c = toupper(c);
    }
    return str;
}

// Função para formatar nome em citação bibliográfica
string formatarNome(string nome) {
    stringstream ss(nome);
    vector<string> palavras;
    string palavra;

    // Separar nome completo em palavras
    while (ss >> palavra) {
        palavras.push_back(palavra);
    }

    if (palavras.size() < 2) return nome; // Caso não tenha sobrenome

    // Último nome (sobrenome) fica em maiúsculas
    string sobrenome = toUpper(palavras.back());
    
    // Primeiro nome e nomes do meio abreviados
    string nomeFormatado = sobrenome + ", " + palavras[0][0] + ".";  
    for (size_t i = 1; i < palavras.size() - 1; i++) {
        nomeFormatado += " " + string(1, palavras[i][0]) + ".";
    }

    return nomeFormatado;
}

int main() {
    ifstream arquivo("Nomes.txt");
    if (!arquivo) {
        cerr << "Erro ao abrir o arquivo Nomes.txt" << endl;
        return 1;
    }

    string linha;
    cout << "Nomes formatados para citacao bibliografica:\n";

    while (getline(arquivo, linha)) {
        cout << formatarNome(linha) << endl;
    }

    arquivo.close();
    return 0;
}
