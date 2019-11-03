#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

#include "sistema.h"

// Colocamos esto aqui para poder debugear el codigo
using namespace std;

//pre: n/a
//post: retorna el arbol vacio. (Inicializado)
Directorio crearDirectorio(){
  Directorio aux = new struct  str_directorio;
  aux->nombre[0]        = '\\';
  aux->cota             = 0;
  aux->tamanio          = 0;
  aux->ruta_absoluta[0] = '\\';
  aux->aprimero         = NULL;
  aux->aultimo          = NULL;

  return aux;
}

//pre: n/a
//post: retorna el arbol vacio.
Directorio vacio(){
    return NULL;
}

//post: retorna true si a es vacio, false en otro caso.
bool isEmptyDirectorio(Directorio d){
    return d == NULL;
}

// //pre: a no es vacio.
// //post: retorna el valor de la raiz de a.
// int valor(Directorio d){
//     return a->valor;
// }

//pre: a no es vacio
//post: retorna la direccion del subarbol izquierdo de a.
Directorio siguienteDir(Directorio d){
    return d->izq;
}

//pre: a no es vacio
//post: retorna la direccion del subarbol derecho de a.
Directorio subDir(Directorio d){
    return d->der;
}

// //pre: n/a
// //post:retorna la direccion del nodo con valor x;
// //     devuelve un Directorio vacio en caso de no encontrar x.
// Directorio Buscar(Directorio d, char NombreDir[]){
//     if (esVacio(a)){
//         return vacio();
//     }else if (valor(a) == x){
//         return a;
//     }else if (x < valor(a)){ //para la izq
//         return Buscar(hijoIzq(a), x);
//     }else{
//         return Buscar(a->der, x);
//     }
// }
//
// //pre: a no es vacio
// //post: retorna la direccion del nodo con menor valor
// //      en el arbol
// Directorio buscarMinimo(Directorio d){
//     if (esVacio(hijoIzq(a))){
//         return a;
//     }else{
//         return buscarMinimo(hijoIzq(a));
//     }
// }
//
// //pre: a no es vacio
// //post: retorna la direccion del nodo con mayor valor
// //      en el arbol
// Directorio buscarMaximo(Directorio d){
//     if (esVacio(hijoDer(a))){
//         return a;
//     }else{
//         return buscarMaximo(hijoDer(a));
//     }
// }
//
// //pre: n/a
// //post: inserta un nodo con valor x en el arbol a.
// //      La insercion respeta la propiedad de que
// //      el arbol es de busqueda.
// void insertar(Directorio &d, char NombreDir[], int cota){
//     if (esVacio(a)){
//         a = new struct str_nodo;
//         a->valor = x;
//         a->izq = NULL;
//         a->der = NULL;
//     }else if (x < valor(a)){ // para la izquierda
//         insertar(a->izq, x);
//     }else if (valor(a) < x){ // para la derecha
//         insertar(a->der, x);
//     } // el caso que quieren insertar un x que ya existe, por lo que no hago nada.
// }
//
// //pre: a no es vacio
// //post: borra el valor x del arbol a.
// void borrar(Directorio &d, char NombreDir[]){
//     if (!esVacio(a)){
//         if (x < valor(a)){
//             borrar(a->izq, x);
//         }else if (valor(a) < x){
//             borrar(a->der, x);
//         }else{ // lo encontre
//             Directorio dux = a;
//             if (esVacio(hijoIzq(a))){
//                 a = a->der;
//                 delete aux;
//             }else if (esVacio(hijoDer(a))){
//                 a = a->izq;
//                 delete aux;
//             }else{
//                 aux =buscarMinimo(a->der);
//                 a->valor = aux->valor;
//                 borrar(a->der, aux->valor);
//             }
//         }
//     }
// }
//
// //pre: n/a
// //post: lista los valores de los nodos de a,
// //      cuando recorremos el arbol en inorden.
// void inOrden(Directorio d){
//     if (!esVacio(a)){
//         inOrden(hijoIzq(a));
//         printf(" %d ", valor(a));
//         inOrden(hijoDer(a));
//     }
// }

//pre: n/a
//post: lista los valores de los nodos de a,
//      cuando recorremos en arbol en preorden.
// void preOrden(Directorio d){
//     if (!esVacio(a)){
//         printf(" %d ", valor(a));
//         preOrden(hijoIzq(a));
//         preOrden(hijoDer(a));
//     }
// }
void Imprimir_directorios(Directorio d, char parametro[]){
  if(parametro == NULL){
    if (!isEmptyDirectorio(d)){
        cout << d->nombre << "     " << "Directorio" << endl; //Imprimo el renglon
        Imprimir_directorios(siguienteDir(d),parametro);
    }
  }else{
  //Imprimo directorios y sub Directorios
    if (!isEmptyDirectorio(d)){
        Imprimir_archivos(aux_archivo);
        Imprimir_directorios(siguienteDir(d),parametro);
        cout << d->nombre << "     " << "Directorio" << endl; //Imprimo el renglon
        Imprimir_directorios(subDir(d),parametro);
    }
  }
}

// //pre: n/a
// //post: lista los valores de los nodos de a,
// //      cuando recorremos el arbol en postorden.
// void postOrden(Directorio d){
//     if (!esVacio(a)){
//         postOrden(hijoIzq(a));
//         postOrden(hijoDer(a));
//         printf(" %d ", valor(a));
//     }
// }
//
// void borrarTodo(Directorio &d){
//     if (!esVacio(a)){
//         borrarTodo(a->izq);
//         borrarTodo(a->der);
//         delete a;
//         a = NULL;
//     }
// }
