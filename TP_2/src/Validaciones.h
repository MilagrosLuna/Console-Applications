#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LLENO 1
#define VACIO 0


int validarTexto(char* cadena);
void ValidarCadena(char* cadena,char* mensaje);
void PedirTexto(char* cadena,char* mensaje);
int PedirYValidarNumero(char* mensaje, char* mensajeError, int limiteInferior, int limiteSuperior);
int PedirEntero(char* mensaje);
int ValidarNumero(char* numero);
void firstToUpper(char* cadena);
float PedirPrecio(char* mensaje,char* mensajeError);
int isFloat(char* cadena);

