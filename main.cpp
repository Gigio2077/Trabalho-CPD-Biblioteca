#include <iostream>
#include "biblioteca.h"
#include <fstream>
#include <string>
using namespace std;


int main(){



    csv_to_bin();

    //bin_to_mem();
    
    return 0;
}








//Teste maior linha do arquivo 1256 ≃ 1299
    // int max = 0;
    // ifstream arquivo_csv("exemplares-acervo.csv"); 
    // string linha;
    // int i = 0;
    // while (getline(arquivo_csv,linha)){
    //     i++;
    //     if(linha.length() > max){
    //         max = linha.length();
    //         cout << linha << "\n\n\n";
        
    //     }
    // }
    // cout << max << "linha :" << i;

