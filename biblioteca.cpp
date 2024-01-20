#include "biblioteca.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <cstring>


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
    }
    try{
        registroSistema = stoi(tokens[0]);
        quantidade = stoi(tokens[6]);
        }
    catch (const std::invalid_argument& e){
        std::cerr << "Error: " << e.what() << std::endl;
        cout << "Falhou em ser registrado: " << tokens[1] << endl;
    }

    strcpy(titulo, tokens[1].c_str());
    strcpy(subtitulo, tokens[2].c_str());
    strcpy(assunto, tokens[3].c_str());
    strcpy(autor, tokens[4].c_str());
    strcpy(tipoMaterial, tokens[5].c_str());
    strcpy(ano, tokens[7].c_str());
    strcpy(editora, tokens[8].c_str());
    strcpy(edicao, tokens[9].c_str());
    //mostrar_info();
    //cout << "======================" << endl;
    
}
    
void csv_to_bin(string nome_arquivo_csv){
    
    ifstream arquivo_csv(nome_arquivo_csv); 
    if (!arquivo_csv.is_open()) {
        cerr << "Erro ao abrir arquivo CSV" << endl;
    }

    ofstream arquivo_binario("registros.bin", ios::binary);
    if (!arquivo_binario.is_open()) {
        cerr << "Erro ao abrir arquivo binario" << endl;
    }

    string linha;
    
    while (getline(arquivo_csv, linha)) {
        //algumas linhas defeituosas, entao testar se
        // e vazia ou se contem o numero incorreto de ';' (sao 11)
        if(linha.empty()){
            continue;
        }
        int ponto_e_virgula = 0;
        for(int i = 0; i < linha.length(); i++){
            if(linha.at(i) == ';')
                ponto_e_virgula++;
        }
        if(ponto_e_virgula != 11){
            continue;
        }

        Livro livro_atual(linha);
        arquivo_binario.write(reinterpret_cast<char*>(&livro_atual),sizeof(livro_atual));
    }

    arquivo_csv.close();
    arquivo_binario.close();

    cout << " \nDados escritos com sucesso." << endl;

}

void bin_to_mem(string livros_binario){

    ifstream arquivo_binario("registros.bin", std::ios::binary);
    if (!arquivo_binario.is_open()) {
        cerr << "Erro ao abrir arquivo binario" << std::endl;
    }

    Livro livro_do_arquivo;
    arquivo_binario.read(reinterpret_cast<char*>(&livro_do_arquivo), sizeof(livro_do_arquivo));
    livro_do_arquivo.mostrar_info();
    
    // while (arquivo_binario.read(reinterpret_cast<char*>(&livro_do_arquivo), sizeof(livro_do_arquivo))) {
    //     livro_do_arquivo.mostrar_info();
    // }

    arquivo_binario.close();

}