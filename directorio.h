#ifndef DIRECTORIO_H
#define DIRECTORIO_H


#include "constantes.h"
#include "archivo.h"
#include "sistema.h"

typedef struct nodo_archivo * Archivo;
struct str_directorio{
  char nombre[NOMBRE_MAX];
  int cota;
  int tamanio;
  char ruta_absoluta[RUTA];
  Archivo aprimero;
  Archivo aultimo;

  struct str_directorio * padre;
  struct str_directorio * izq;
  struct str_directorio * der;

};typedef struct str_directorio * Directorio;



//pre: n/a
//post: retorna el arbol vacio.
Directorio vacio();

//post: retorna true si a es vacio, false en otro caso.
bool esVacio(Directorio d);

//post: retorna el valor de la raiz de a.
int valor(Directorio d);

//pre: a no es vacio
//post: retorna la direccion del subarbol izquierdo de a.
Directorio hijoIzq(Directorio d);

//pre: a no es vacio
//post: retorna la direccion del subarbol derecho de a.
Directorio hijoDer(Directorio d);

//pre: n/a
//post:retorna la direccion del nodo con nombre de directorio.
Directorio Buscar(Directorio d, char NombreDir[]);

//pre: a no es vacio
//post: retorna la direccion del nodo con menor nombre
//      en el arbol
Directorio buscarMinimo(Directorio d);

//pre: a no es vacio
//post: retorna la direccion del nodo con mayor nombre
//      en el arbol
Directorio buscarMaximo(Directorio d);

//pre: n/a
//post: inserta un nodo con valor x en el arbol a.
//      La insercion respeta la propiedad de que
//      el arbol es de busqueda.
void insertar(Directorio &d, char NombreDir[], int cota);

//pre: a no es vacio
//post: borra el directorio con nombre NombreDir[] del arbol a.
void borrar(Directorio &d, char NombreDir[]);

//pre: n/a
//post: lista los valores de los nodos de a,
//      cuando recorremos el arbol en inorden.
void inOrden(Directorio d);

//pre: n/a
//post: lista los valores de los nodos de a,
//      cuando recorremos en arbol en preorden.
void preOrden(Directorio d);

//pre: n/a
//post: lista los valores de los nodos de a,
//      cuando recorremos el arbol en postorden.
void postOrden(Directorio d);



#endif //DIRECTORIO_H
