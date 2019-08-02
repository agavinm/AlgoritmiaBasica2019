#*****************************************************************
# File:   Makefile
# Author: Andrés Gavín Murillo 716358
# Author: Andrew Mackay 737069
# Date:   Agosto 2019
# Coms:   Algoritmia básica - Práctica 2
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
EJEC = transporte
MAIN = main
MON = heap
ARB = arbol
PED = pedido
TRE = tren

all: ${EJEC}
#---------------------------------------------------------
# "linkar"
${EJEC}: ${MAIN}.o ${MON}.hpp ${ARB}.o ${PED}.o ${TRE}.o
	${CC} ${MAIN}.o ${MON}.hpp ${ARB}.o ${PED}.o ${TRE}.o -o ${EJEC} ${CPPFLAGS}

#---------------------------------------------------------
# compilar
${MAIN}.o: ${MAIN}.cpp ${MON}.hpp.gch ${ARB}.hpp ${ARB}.cpp ${PED}.hpp ${PED}.cpp ${TRE}.hpp ${TRE}.cpp
	${CC} -c ${MAIN}.cpp ${CPPFLAGS}

${MON}.hpp.gch: ${MON}.hpp
	${CC} -c ${MON}.hpp ${CPPFLAGS}

${ARB}.o: ${ARB}.hpp ${ARB}.cpp
	${CC} -c ${ARB}.cpp ${CPPFLAGS}

${PED}.o: ${PED}.hpp ${PED}.cpp
	${CC} -c ${PED}.cpp ${CPPFLAGS}

${TRE}.o: ${TRE}.hpp ${TRE}.cpp
	${CC} -c ${TRE}.cpp ${CPPFLAGS}

#---------------------------------------------------------
# Cuidado con lo que se pone aquí, que se borra sin preguntar
clean:
	$(RM) ${MON}.hpp.gch ${ARB}.o ${PED}.o ${TRE}.o ${MAIN}.o ${EJEC}
