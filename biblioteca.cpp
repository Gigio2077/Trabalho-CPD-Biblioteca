#include "biblioteca.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

void Livro::mostrar_info() {
    std::cout << "Registro do Sistema: " << registroSistema << "\n"
              << "Título: " << titulo << "\n"
              << "Subtítulo: " << subtitulo << "\n"
              << "Assunto: " << assunto << "\n"
              << "Autor: " << autor << "\n"
              << "Tipo de Material: " << tipoMaterial << "\n"
              << "Quantidade: " << quantidade << "\n"
              << "Ano: " << ano << "\n"
              << "Editora: " << editora << "\n"
              << "Edição: " << edicao << "\n";
}

Livro::Livro(const string& linha){

    istringstream ss(linha);
    string token;
    vector<string> tokens;

    while (getline(ss, token, ';')) {
        token.erase(remove( token.begin(), token.end(), '\"' ),token.end());

        tokens.push_back(token);
        cout << token << endl;
    }

    if (!tokens.empty()) {

        int number = stoi(tokens[0]);

        std::cout << "The number is: " << number << std::endl;
    }
}
    
void csv_to_bin(string nome_arquivo_csv){

}
