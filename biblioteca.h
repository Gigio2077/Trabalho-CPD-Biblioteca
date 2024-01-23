//Arquivo com definicoes dos Objetos
// Livro e Usuario

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

using namespace std;

#include <string>
#include <vector>

class Livro {
    /*IMPORTANTE: originalmente eu tinha feito os atributos usando string 
    no entanto na hora de ler do binario como a string possui tamanhos variados 
    nao e possivel ler um objeto identico 1299 foi o tamanho maximo de token 
    (fiz um teste com um loop simples)*/
    


    private:
        int registroSistema;
        char dados[1299];
        string titulo;
        string subtitulo;
        string assunto;
        string autor;
        string tipoMaterial;
        int quantidade;
        string ano;
        string editora;
        string edicao;    

    public:
        
        void mostrar_info();
        Livro(const string&);
        Livro(){}; //coonstrutor vazio - sem argumentos


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
