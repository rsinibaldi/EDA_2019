#ifndef ARCHIVO_H
#define ARCHIVO_H

#include "constantes.h"
#include "linea.h"
//#include "sistema.h"




// DEFINIMOS NODO ARCH CON EL CABEZAL DE LINEA
struct nodo_archivo{
char nombre[NOMBRE_MAX];
 char extension[EXT_MAX];
int tamanio;
 struct nodo_archivo *sig;
 struct nodo_archivo *ant;
    // Cabezal linea
  Linea lprimero;
 Linea lultimo;

};
typedef struct nodo_archivo * Archivo;


Archivo crearArchivo();
Linea crearLinea();



//PRE: La lista archivos debe estar creada
//POST: Devuelve true si la lista es vacia, false en otro caso
bool isEmptyArchivo(Archivo a);

//PRE: recibe una lista con por lo menos 1 elemento.
//POST: Retorna la lista sin su primer elemento.
Archivo TailArchivo(Archivo a);

//PRE: la lista de archivos debe contener al menos un archivo
//POST: Compara nom y ext con los archivos de la lista para saber si estan repetidos
bool existeArchivo(Archivo ArchivosCol, char nom[], char ext[]);

//PRE: deben haber archivos sino no imprime
//POST: muestra toda la coleccion de archivos
void Imprimir_archivos(Archivo arch);




#endif //ARCHIVO_H
