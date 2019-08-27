#*****************************************************************
# File:   Makefile
# Author: Andrés Gavín Murillo 716358
# Author: Andrew Mackay 737069
# Date:   Mayo 2019
# Coms:   Algoritmia básica - Práctica 1
#         Ejecutar "make" para compilar (o "make -f Makefile")
#         Ejecutar "make clean" para limpiar (borrar lo que genere)
#*****************************************************************

#---------------------------------------------------------
# macros
RM = /bin/rm -f  # para limpiar
CC = g++         # compilador
#---------------------------------------------------------
# compilación y enlazado ("linkado")
CPPFLAGS=-I. -O2 -std=c++11 -fmax-errors=1 # opciones compilación
#---------------------------------------------------------
# vars
MAIN = main
EJEC = main
TREN = tren
PEDIDO = pedido

all: ${EJEC}
#---------------------------------------------------------
# "linkar"
${EJEC}: ${MAIN}.o  ${TREN}.o ${PEDIDO}.o
	${CC} ${MAIN}.o ${TREN}.o  ${PEDIDO}.o -o ${EJEC} ${CPPFLAGS}

#---------------------------------------------------------
# compilar
${MAIN}.o: ${MAIN}.cpp 
	${CC} -c ${MAIN}.cpp ${CPPFLAGS}

${TREN}.o: ${TREN}.hpp ${TREN}.cpp
	${CC} -c ${TREN}.cpp ${CPPFLAGS}

${PEDIDO}.o: ${PEDIDO}.hpp ${PEDIDO}.cpp
	${CC} -c ${PEDIDO}.cpp ${CPPFLAGS}

#---------------------------------------------------------
# Cuidado con lo que se pone aquí, que se borra sin preguntar
clean:
	$(RM) ${MAIN}.o ${TREN}.o ${PEDIDO}.o ${EJEC}
