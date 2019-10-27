#ifndef PAPELERA_H
#define PAPELERA_H


#include "enum.h"
#include "archivo.h"


//DEFINIMOS PAPELERA
struct str_papelera{
  Archivo deleted_arch;
  struct str_papelera * sig;
};
typedef struct str_papelera * Papelera;



Papelera crearPapelera();

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




#endif //PAPELERA_H