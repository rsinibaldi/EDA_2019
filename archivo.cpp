#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

#include "archivo.h"
#include "sistema.h"

// Colocamos esto aqui para poder debugear el codigo
using namespace std;

//PRE: La lista archivos debe estar creada
//POST: Devuelve true si la lista es vacia, false en otro caso
bool isEmptyArchivo(Archivo a){
    return (a == NULL);
}

//PRE: recibe una lista con por lo menos 1 elemento.
//POST: Retorna la lista sin su primer elemento.
Archivo TailArchivo(Archivo a){
    return a->sig;
}

//PRE: la lista de archivos debe contener al menos un archivo
//POST: Compara nom y ext con los archivos de la lista para saber si estan repetidos
bool existeArchivo(Archivo ArchivosCol, char nom[], char ext[]){
    if(!isEmptyArchivo(ArchivosCol)){
        if((strcmp(ArchivosCol->nombre, nom) == 0) && (strcmp(ArchivosCol->extension, ext) == 0)){
            return true;
        }else{
            return existeArchivo(TailArchivo(ArchivosCol), nom, ext);
        }
    }
   return false;
}


//PRE: deben haber archivos sino no imprime
//POST: muestra toda la coleccion de archivos
void Imprimir_archivos(Archivo arch){

    while(arch != NULL){
        cout << arch->nombre <<"."<< arch->extension << "     " << "Archivo     " << arch->tamanio << endl; //Imprimo el renglon
        arch = TailArchivo(arch);
    }
}

//pre: recibe una ListaArchivos creada.
//pos: busca en la lista el archivo y lo devuelve.
Archivo buscarArchivo(Sistema s, char nom[], char ext[]){
    bool encontre = false;
    Archivo auxArchivos = s->dirActual->aprimero;
    Archivo res;


    while(auxArchivos != NULL && !encontre){

      if ((strcmp(auxArchivos->nombre, nom) == 0) && (strcmp(auxArchivos->extension, ext) == 0)){
         encontre = true;
         res = auxArchivos;
       }else{
         auxArchivos = TailArchivo(auxArchivos);
       }

    }

    return res;
}


Archivo crearArchivo(){
    Archivo aux = new struct  nodo_archivo;
    aux->nombre[0]    = '\0';
    aux->extension[0] = '\0';
    aux->tamanio      = 0;
    aux->sig          = NULL;
    aux->ant          = NULL;
    aux->lprimero     = NULL;
    aux->lultimo      = NULL;
    return aux;
}

Linea crearLinea(){
    Linea aux = new struct  nodo_linea;
    aux->renglon[0]   = '\0';
    aux->sig          = NULL;
    aux->ant          = NULL;
    return aux;
}

// Papelera crearPapelera(){
//     Papelera p = new struct str_papelera;
//     p->sig          = NULL;
//     p->deleted_arch = NULL;
//     return p;
// }




//------------------------------------------------------------------------------------------------
//Funciones auxiliares para implementar el DELETE y UNDELET
//REVISAR


// void push(Papelera &p, Archivo aux){
//   Papelera papNuevo = new struct str_papelera;
//   Archivo archNuevo = new struct nodo_archivo;
//
//   strcpy(archNuevo->nombre,aux->nombre);
//   strcpy(archNuevo->extension,aux->extension);
//   archNuevo->tamanio    = aux->tamanio;
//   archNuevo->lprimero   = aux->lprimero;
//   archNuevo->lultimo    = aux->lultimo;
//
//   //guardamos el anterior y el siguiente del archivo que estoy guardando para
//   //el UNDELETE, para saber donde ubcarlo.
//   archNuevo->ant = aux->ant;
//   archNuevo->sig = aux->sig;
//
//   papNuevo->deleted_arch = archNuevo;
//   if(!isEmptyStack(p)){ // Este if no funciona correctamente pero realiza lo que necesito de todas formas
//     papNuevo->sig = p;
//   }else{
//     papNuevo->sig = NULL;
//   }
//
//   p = papNuevo;
//
// }
//
// bool isEmptyStack(Papelera p){
//   return (p == NULL);
// }
// Archivo pop(Papelera &p){
//    Archivo arch = p->deleted_arch;
//    Papelera post = p;
//    p = p->sig;
//    return arch;
//    delete post; //DUDA sobre si hay que borrar este espacio de memory
// }
//
// int height(Papelera p){
//    int cont = 0;
//    while(!isEmptyStack){
//         cont ++;
//         p = p->sig;
//    }
//    return cont;
// }


// TipoRet DIRPAPELERA(Papelera &p/*, char * parametro, char &error[]*/){
//   char mensaje[100];
//   TipoRet Respuesta;
//   Respuesta = OK;
//
//   cout << "\n Dir-Papelera:  " << endl;
//   if(p == NULL){
//     cout << "Error: No hay archivos para mostrar" << endl;
//     Respuesta = ERROR;
//
//   }else{ // Hay que ir recorriendo el sistema hasta NULL
//     Papelera pap = p;
//
//     // Hay que ir recorriendo el sistema hasta NULL
//     while(!isEmptyStack(pap)){
//       cout << pap->deleted_arch->nombre << endl; //Imprimo el renglon
//       pap = pap->sig;
//     };
//
//   }
//
//   cout << "\n " << endl;
//   return Respuesta;
// }
