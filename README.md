# Práctica 1

### Funcionamiento:  
<space>1. Leer todos los bytes (unsigned char) del fichero (En lugar de caracteres se utilizan bytes) y almacenarlos en vector C, y contar su frecuencia en vector f.  
 
 * Nota: Podrían usarse 2B (short int) si las frecuencias con 1B son parecidas.

#### Algoritmo de Huffman
<space>2. Crear montículo Q con las frecuencias obtenidas, cuya cima tenga la clave mayor (un nodo estará representado por un árbol lexicográfico x con un sólo nodo compuesto por CLAVE=frecuencia y VALOR=byte).  

<space>3. Continuar  
<br>
  
* Nota: Notación de diapositiva 62.

### TADs necesarios
<space>1. Montículo:

* crear(): crea un montículo
* destruir(): destruye el montículo
* arbol cima(): devuelve el arbol en la cima y lo elimina del montículo
* anyadir(arbol a): anyade a al montículo

<space>2. Árbol lexicográfico:

* crear(nodo raiz, arbol hijoI, arbol hijoD): crea un árbol lexicográfico
* destruir(): destruye el árbol lexicográfico
* tabla devolverTabla(): devuelve la tabla (hash?) resultante de asociar a cada byte su código lexicográfico.
* byte devolverByteDescodificado(codigo_codificado c): devuelve el byte descodificado asociado a c.

<space>3. Tabla hash?

