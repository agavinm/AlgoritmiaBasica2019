//*****************************************************************
// File:   huffman.hpp
// Author: Andrés Gavín Murillo 716358
// Author: Andrew Mackay 737069
// Date:   Mayo 2019
// Coms:   Algoritmia básica - Práctica 1
//*****************************************************************

#ifndef PRACTICA1_HUFFMAN_HPP
#define PRACTICA1_HUFFMAN_HPP

/* Dado el nombre de un fichero nombreFichero, genera un fichero nombreFichero.huf comprimido mediante el algoritmo
 * de Huffman.
 * El fichero tiene el siguiente formato:
 *      1º: Árbol lexicográfico de código libre.
 *      2º: Símbolos codificados.
 *      3º: Número de símbolos descolocados en el anterior byte. */
void comprimir(const char *nombreFichero);

/* Dado el nombre de un fichero comprimido (mediante la función comprimir()) nombreFichero = nombre.huf, genera el
 * fichero original nombre. */
void descomprimir(const char *nombreFichero);


#endif //PRACTICA1_HUFFMAN_HPP
