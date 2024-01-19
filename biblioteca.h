//Arquivo com definicoes dos Objetos
// Livro e Usuario

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

using namespace std;

#include <string>
#include <vector>

class Livro {
    private:
        int registroSistema;
        std::string titulo;
        std::string subtitulo;
        std::string assunto;
        std::string autor;
        std::string tipoMaterial;
        int quantidade;
        std::string ano;
        std::string editora;
        std::string edicao;

    public:
        void mostrar_info();
        Livro(const string&);


};

class Usuario {
    private:
        std::string nome_de_usuario;
        std::string senha;
        std::vector <Livro> livros_emprestados;
        
    public:

};

//funcoes p/ lidar com arquivos

void csv_to_bin(string nome_arquivo_csv = "exemplares-acervo.csv");




#endif 
