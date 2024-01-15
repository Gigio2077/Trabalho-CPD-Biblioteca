#include "biblioteca.h"
#include <iostream>
#include <fstream>

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

void csv_to_bin(string nome_arquivo_csv){

    ifstream arquivo_csv (nome_arquivo_csv, ios::binary);
    
    ofstream arquivo_binario ("registros.bin", ios::binary);
    if (!arquivo_binario) {
        cerr << "Falha ao abrir o arquivo para escrita registros.bin" << endl;
    }
    

    string linha;
    
    if(arquivo_csv.is_open())
    {
        getline(arquivo_csv, linha); 
        getline(arquivo_csv, linha);  
        cout << linha << endl;      
    }
    else{
        cerr << "Falha ao abrir o arquivo " + nome_arquivo_csv << endl;
    }
    arquivo_binario.write(linha.c_str(), linha.size());
    arquivo_binario.close();
}
