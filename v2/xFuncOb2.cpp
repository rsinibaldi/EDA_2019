
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

// #include "aStruct.h"
#include "xFuncOb2.h"


#include "bFuncDir.h"
#include "cFuncArch.h"
#include "dFuncLin.h"
#include "fFuncPap.h"

using namespace std;



TipoRet MKDIR (Sistema &s, char nombreDirectorio[]/*, string &mensaje*/){

  TipoRet Respuesta;
  char mensaje[TEXTO_LARGO]; // para mostrar el error en la pantalla

  bool encontre = false;
  bool insertOk = false;
  char nomDirAct[NOMBRE_MAX];
  char raiz[NOMBRE_MAX]={'\\'};
  char nom[NOMBRE_MAX];

  //Creamos nueva estructura para directorio
  Directorio nuevo = new struct str_directorio;
  Directorio DirCol;

  strcpy(nom,nombreDirectorio);

  //comprobamos que cumpla con las condiciones para ser ingresado
  if(strlen(nom) > (NOMBRE_MAX)){
    strcpy (mensaje, "El largo del Directorio excede los caracteres permitidos");
    Respuesta = ERROR;

  } else if (strcmp(raiz, nom) == 0) {
    strcpy (mensaje, "No puede llamarse como la raiz");
    Respuesta = ERROR;

  } else {

   //Cumple los requisitos minimos, copiamos al dir nuevo :
   strcpy(nuevo->nombre,nom);
   nuevo->tamanio          = 0;
   //nuevo->ruta_absoluta[0] = '\\'; ACA ESTARIA DEPENDIENDO DE DIR ACTUAL
   nuevo->padre = s->dirActual;
   nuevo->aprimero         = NULL;
   nuevo->aultimo          = NULL;
   nuevo->izq              = NULL;
   nuevo->der              = NULL;


   DirCol = s->dirActual->der;

   if (existeDir(DirCol, nom)){
     //el dir existe y por lo tanto no podemos crearlo
     strcpy (mensaje, "Lo lamento, el dir ya existe");
     Respuesta = ERROR;

   } else {
     //el dir no existe y hay que insertarlo ordenadamente
     //reseteamos el dircol
     DirCol = s->dirActual->der;

     while((DirCol != NULL) && (encontre == false)){
       //comparamos en que lugar colocar
       //Armo el nombre completo del DIR para comparar el criterio de ordenamiento
       strcpy(nomDirAct,DirCol->nombre);
       // Compara, si es mayor va despues
       if(strcmp(nom,nomDirAct) > 0){
         encontre = true;
       }else{
         DirCol = siguienteDir(DirCol);
       }
     }

     if((!encontre) && (!isEmptyDirectorio(s->dirActual->der))) {
       //Inserto al comienzo pero ya existen directorio, antonces arreglo en enganche
       nuevo->izq = s->dirActual->der;
       s->dirActual->der = nuevo;
       insertOk = true;

     }else if((!encontre) && (isEmptyDirectorio(s->dirActual->der))) {
       //Inserto al comienzo cuando no existen directorios en el arbol
       s->dirActual->der = nuevo;
       insertOk = true;

     } else {
       //inserto al final o al medio
       nuevo->izq = DirCol->izq;
       DirCol->izq = nuevo;
       s->dirActual->der = DirCol;
       insertOk = true;

     }

     if (insertOk) {
       strcpy (mensaje, "Se ha creado el archivo.");
       Respuesta = OK;
     }else{
       Respuesta = ERROR;
     }

   }
  }

  cout << mensaje << endl;
  return Respuesta;
  }

/*************************************************************************************************************************



*************************************************************************************************************************/

TipoRet RMDIR (Sistema &s, char nombreDirectorio[]){


  TipoRet Respuesta;
  char mensaje[TEXTO_LARGO]; // para mostrar el error en la pantalla

  bool encontre = false;
  char nomDirAct[NOMBRE_MAX];
  char raiz[NOMBRE_MAX]={'\\'};
  char nom[NOMBRE_MAX];
  char nomAux[NOMBRE_MAX];
  Directorio DirCol;

  strcpy(nom,nombreDirectorio);
  std::cout << "RMDIR - A " << '\n';
  //consulto si hay algun otro dir
  DirCol = s->dirActual->der;
  if (!existeDir(DirCol, nom)){
    std::cout << "RMDIR - B " << '\n';
    strcpy (mensaje, "Lo lamento, el dir a eliminar no existe");
    Respuesta = ERROR;

  } else {
    std::cout << "RMDIR - C " << '\n';
    //reseteamos el dircol
    DirCol = s->dirActual->der;
    borrarDir(DirCol,nombreDirectorio);

  }

}
