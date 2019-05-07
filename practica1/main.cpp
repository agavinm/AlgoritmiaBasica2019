//******************************************************************************
// File:   main.cpp
// Author: Andrés Gavín Murillo 716358
// Author: Andrew Mackay 737069
// Date:   Mayo 2019
// Coms:   Algoritmia básica - Práctica 1
//******************************************************************************

#include <string>
#include "huffman.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc == 3) {
        string arg(argv[1]);
        if (arg == "-c") {
            comprimir(argv[2]);
        }
        else if (arg == "-d") {
            descomprimir(argv[2]);
        }
    }
}