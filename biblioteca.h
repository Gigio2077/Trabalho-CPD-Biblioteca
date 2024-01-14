//Arquivo com definicoes dos Objetos
// Livro e Usuario

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <string>

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

};

class Usuario {
    private:
        std::string nome_de_usuario;
        std::string senha;
        std::vector <Livro> livros_emprestados;
        
    public:

};

#endif // BIBLIOTECA_H
