#*****************************************************************
# File:   Makefile
# Author: Andrés Gavín Murillo 716358
# Author: Andrew Mackay
# Date:   Marzo 2019
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
EJEC = huf
MAIN = main
MON = heap
ARB = arbol

all: ${EJEC}
#---------------------------------------------------------
# "linkar"
${EJEC}: ${MAIN}.o ${MON}.o ${ARB}.o
	${CC} ${MAIN}.o ${MON}.o ${ARB}.o -o ${EJEC} ${CPPFLAGS}

#---------------------------------------------------------
# compilar
${MAIN}.o: ${MAIN}.cpp ${MON}.hpp ${MON}.cpp ${ARB}.hpp ${ARB}.cpp
	${CC} -c ${MAIN}.cpp ${CPPFLAGS}

${MON}.o: ${MON}.hpp ${MON}.cpp
	${CC} -c ${MON}.cpp ${CPPFLAGS}

${ARB}.o: ${ARB}.hpp ${ARB}.cpp
	${CC} -c ${ARB}.cpp ${CPPFLAGS}

#---------------------------------------------------------
# Cuidado con lo que se pone aquí, que se borra sin preguntar
clean:
	$(RM) ${MON}.o ${ARB}.o ${MAIN}.o ${EJEC}
