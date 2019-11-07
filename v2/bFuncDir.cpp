
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <string.h>


//#include "aStruct.h"
#include "bFuncDir.h"
using namespace std;


// FUNCIONES AUX DIRECTORIO


bool existeDir(Directorio DirCol, char nom[]){
  cout << "1" <<endl;
  cout << nom <<endl;
    if(!isEmptyDirectorio(DirCol)){
      cout << DirCol->nombre <<endl;
        if (strcmp(DirCol->nombre, nom) == 0){
          cout << "3" <<endl;
            return true;
        }else{
          cout << "4" <<endl;
            return existeDir(siguienteDir(DirCol), nom);
        }
    }
   return false;
}


//pre: a no es vacio
//post: retorna la direccion del subarbol izquierdo de a.
Directorio siguienteDir(Directorio d){
    return d->izq;
}

bool isEmptyDirectorio(Directorio d){
    return (d == NULL);
}


void Imprimir_directorios(Directorio d, char parametro[]){
  if(parametro == NULL){
    if (!isEmptyDirectorio(d)){
        cout << d->nombre << "     " << "Directorio" << endl; //Imprimo el renglon
        Imprimir_directorios(siguienteDir(d),parametro);
    }
  }else{
    //Imprimo directorios y sub Directorios
  }
}


//pre: a no es vacio
//post: retorna la direccion del subarbol derecho de a.
Directorio subDir(Directorio d){
    return d->der;
}

//pre: n/a
//post: retorna el arbol vacio.
Directorio vacio(){
    return NULL;
}


bool esRutaAbsoluta(char nombreDirectorio[]){

  char barra[] = "/";
  int a;
  a = strspn(nombreDirectorio,barra);
  cout << "esRutaAbsoluta [strspn] : "<< a << endl;
  if (strspn(nombreDirectorio,barra) > 0){
    return true;
  }else{
    return false;
  }

}

void NomDirRutaAbsoluta(char nombreDirectorio[],char retorno[]){
  // int pos, posFin;
  // string strDirNuevo;

  // // pos = strrchr(nombreDirectorio,'/');
  // // posFin = strlen(nombreDirectorio);

  //  pos = nombreDirectorio.find("/"); 

  // string str(nombreDirectorio);
  

  // strDirNuevo = str.substr(pos+1);

  // char Directorio[strDirNuevo.size()+1];
  // strcpy(Directorio,strDirNuevo.c_str());


}


//post: retorna true si a es vacio, false en otro caso.


// //pre: a no es vacio.
// //post: retorna el valor de la raiz de a.
// int valor(Directorio d){
//     return a->valor;
// }




//pre: n/a
//post:retorna la direccion del nodo con valor x;
//     devuelve un Directorio vacio en caso de no encontrar x.
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
