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
                 << "Título: " << string(dados) << "\n";


    
    istringstream ss(string(this->dados));
    string token;
    for (int i = 0; i < 9; i++){
        getline(ss, token, ';');
        token.erase(remove( token.begin(), token.end(), '\"' ),token.end());
        switch(i){
            case 0:
                titulo = token;
                break;
            case 1:
                subtitulo = token;
                break;
            case 2:
                assunto = token;
                break;
            case 3:
                autor = token;
                break;
            case 4:
                tipoMaterial = token;
                break;
            case 5:
                try{
                int quantidade = stoi(token);
                }
                catch (const std::invalid_argument& e){
                std::cerr << "Error: " << e.what() << std::endl;
                cout << "Falhou em ser registrado: " << token << endl;
                }
                break;
            case 6:
                ano = token;
                break;
            case 7:
                editora = token;
                break;
            case 8:
                edicao = token;
                break;
        }
    }
    // token.erase(remove( token.begin(), token.end(), '\"' ),token.end());
    // // tokens.push_back(token);   
    // try{
    //     registroSistema = stoi(token);
    //     }
    // catch (const std::invalid_argument& e){
    //     std::cerr << "Error: " << e.what() << std::endl;
    //     cout << "Falhou em ser registrado: " << token << endl;
    //}
    //           << "Título: " << titulo << "\n"
    //           << "Subtítulo: " << subtitulo << "\n"
    //           << "Assunto: " << assunto << "\n"
    //           << "Autor: " << autor << "\n"
    //           << "Tipo de Material: " << tipoMaterial << "\n"
    //           << "Quantidade: " << quantidade << "\n"
    //           << "Ano: " << ano << "\n"
    //           << "Editora: " << editora << "\n"
    //           << "Edição: " << edicao << "\n";
}

Livro::Livro(const string& linha){

    istringstream ss(linha);
    string token;

    //================================
    // numero    
    getline(ss, token, ';');
    token.erase(remove( token.begin(), token.end(), '\"' ),token.end());
    // tokens.push_back(token);   
    try{
        registroSistema = stoi(token);
        }
    catch (const std::invalid_argument& e){
        std::cerr << "Error: " << e.what() << std::endl;
        cout << "Falhou em ser registrado: " << token << endl;
    }
    //================================
    // dados
    getline(ss, token, '\n');
    token.erase(remove( token.begin(), token.end(), '\"' ),token.end());
    strcpy(dados, token.c_str());  
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
//================================
// loop pega livro por livro e escreve o obj 
    string linha;
    int linhas_lidas = 0;
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
    //getline(arquivo_csv,linha);
    Livro livro_atual(linha);
    linhas_lidas++;
    arquivo_binario.write(reinterpret_cast<char*>(&livro_atual),sizeof(livro_atual));
    }







//================================
// fechando arquivos
    arquivo_csv.close();
    arquivo_binario.close();
    if (!arquivo_csv.is_open()&&!arquivo_binario.is_open()){
    cout << "\nDados de " << linhas_lidas << " linhas escritos com sucesso." << endl;
    }else{
    cerr << "\nErro ao fechar um dos arquivos." << endl;
    }
}

void bin_to_mem(string livros_binario){

    ifstream arquivo_binario("registros.bin", std::ios::binary);
    if (!arquivo_binario.is_open()) {
        cerr << "Erro ao abrir arquivo binario" << std::endl;
    }

    Livro livro_do_arquivo;
    arquivo_binario.read(reinterpret_cast<char*>(&livro_do_arquivo), sizeof(livro_do_arquivo));
    //livro_do_arquivo.mostrar_info();
    
    // while (arquivo_binario.read(reinterpret_cast<char*>(&livro_do_arquivo), sizeof(livro_do_arquivo))) {
    //     livro_do_arquivo.mostrar_info();
    // }

    arquivo_binario.close();

}