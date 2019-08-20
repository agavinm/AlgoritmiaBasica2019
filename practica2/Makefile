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
ARB = tren

all: ${EJEC}
#---------------------------------------------------------
# "linkar"
${EJEC}: ${MAIN}.o ${ARB}.o 
	${CC} ${MAIN}.o ${ARB}.o -o ${EJEC} ${CPPFLAGS}

#---------------------------------------------------------
# compilar
${MAIN}.o: ${MAIN}.cpp 
	${CC} -c ${MAIN}.cpp ${CPPFLAGS}

${ARB}.o: ${ARB}.hpp ${ARB}.cpp
	${CC} -c ${ARB}.cpp ${CPPFLAGS}

#---------------------------------------------------------
# Cuidado con lo que se pone aquí, que se borra sin preguntar
clean:
	$(RM) ${MAIN}.o ${ARB}.o ${EJEC}
