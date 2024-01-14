#include "biblioteca.h"

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

