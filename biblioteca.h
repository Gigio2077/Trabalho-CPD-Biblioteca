//Arquivo com definicoes dos Objetos
// Livro e Usuario

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

using namespace std;

#include <string>
#include <vector>

class Livro {
    /*IMPORTANTE: originalmente eu tinha feito os atributos usando string 
    no entanto na hora de ler do binario como a string tem tamanho variado 
    nao e possivel ler um objeto padrao 1024 foi o tamanho maximo de token 
    (fiz um teste com um loop simples)*/

    private:
        int registroSistema;
        char titulo[1024];
        char subtitulo[1024];
        char assunto[1024];
        char autor[1024];
        char tipoMaterial[1024];
        int quantidade;
        char ano[1024];
        char editora[1024];
        char edicao[1024];

    public:
        void mostrar_info();
        Livro(const string&);
        Livro(){};


};

class Usuario {
    private:
        string nome_de_usuario;
        string senha;
        vector <Livro> livros_emprestados;
        
    public:

};

//funcoes p/ lidar com arquivos

void csv_to_bin(string nome_arquivo_csv = "exemplares-acervo.csv");

void bin_to_mem(string livros_binario = "example.bin");


#endif 
