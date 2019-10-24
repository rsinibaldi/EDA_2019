#ifndef ARCHIVO_H
#define ARCHIVO_H

#include "constantes.h"
#include "sistema.h"



// DEFINIMOS EL NODO LINEA
struct nodo_linea{
    char renglon[RENGLON_LARGO_MAX];
    int cantCaracteres;
    struct nodo_linea *ant;
    struct nodo_linea *sig;
};
typedef struct nodo_linea * Linea;


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


//DEFINIMOS PAPELERA
struct str_papelera{
  Archivo deleted_arch;
  struct str_papelera * sig;
};
typedef struct str_papelera * Papelera;


Papelera crearPapelera();
Archivo crearArchivo();
Linea crearLinea();


//------------------------------------------------------
//funciones auxiliares para el delete/undelete


//pre: n/a
//post: inserta un Archivo al stack (papelera).
void push(Papelera &p, Archivo aux);

//pre: n/a
//post: devuelve true si la papelera esta vacia, sino es false.
bool isEmptyStack(Papelera p);

//pre: n/a - que la papelera tenga un archivo por lo menos.
//post: extrae un archivo de la papelera.
Archivo pop(Papelera &p);

//pre: n/a - que la papelera tenga un archivo por lo menos.
//post: Nos devuelve un entero representando la cantidad de Archivos en la papelera
int height(Papelera p);


TipoRet DIRPAPELERA(Papelera &p/*, char * parametro, char &error[]*/);


#endif //ARCHIVO_H
