#include <iostream>
#include <fstream>

using namespace std;
    
int main(){
    
    string nome_arquivo_csv = {"exemplares-acervo.csv"};
    
    fstream arquivo (nome_arquivo_csv, ios::in);
    
    string linha;
    
    if(arquivo.is_open())
    {
        getline(arquivo, linha);        
        getline(arquivo, linha);        

    }
    
    cout << linha;
    
    return 0;
}