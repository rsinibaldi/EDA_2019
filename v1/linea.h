#ifndef LINEA_H
#define LINEA_H

#include "constantes.h"

// DEFINIMOS EL NODO LINEA
struct nodo_linea{
    char renglon[RENGLON_LARGO_MAX];
    int cantCaracteres;
    struct nodo_linea *ant;
    struct nodo_linea *sig;
};
typedef struct nodo_linea * Linea;





//PRE:El archivo debe estar creado
//POST:Devulve la cantidad de filas de un archivo
int CantLineas(Linea l);


//PRE: La lista de lineas debe estar creada
//POST: Devuelve true si la lista es vacia, false en otro caso
bool isEmptyArchivoLineas(Linea l);




#endif //LINEA_H