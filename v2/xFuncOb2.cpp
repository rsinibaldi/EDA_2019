
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

  Directorio nuevo = new struct str_directorio;
  char nom[NOMBRE_MAX];
  strcpy(nom,nombreDirectorio);

  bool encontre = false;
  char nomDirAct[NOMBRE_MAX];
  char raiz[NOMBRE_MAX]={'\\'};
  // strcpy(raiz, '\\');


  Directorio DirCol;

cout << "B" <<endl;


  //comprobamos que cumpla con las condiciones para ser ingresado
  if(strlen(nom) > (NOMBRE_MAX)){
    strcpy (mensaje, "El largo del Directorio excede los caracteres permitidos");
    Respuesta = ERROR;
  } else if (strcmp(raiz, nom) == 0) {
    strcpy (mensaje, "No puede llamarse como la raiz");
    Respuesta = ERROR;
  } else {

cout << "C" <<endl;
   //Cumple los requisitos minimos, copiamos al dir nuevo :
   strcpy(nuevo->nombre,nom);
   nuevo->tamanio          = 0;
   //nuevo->ruta_absoluta[0] = '\\'; ACA ESTARIA DEPENDIENDO DE DIR ACTUAL
   nuevo->padre = s->dirActual;
   nuevo->aprimero         = NULL;
   nuevo->aultimo          = NULL;
   nuevo->izq              = NULL;
   nuevo->der              = NULL;

   //---------------------------------------------------------------

cout << "D" <<endl;
   if (isEmptyDirectorio(s->dirActual->padre)) {
     cout << "E" <<endl;
     //estoy en el nivel de la raiz
     //consulto si hay algun otro dir
     DirCol = s->dirActual->izq;

      cout << "T" <<endl;
      if (!isEmptyDirectorio(DirCol)){
        cout << DirCol->nombre <<endl;
      }

      cout << nom <<endl;

     if (existeDir(DirCol, nom)){
       cout << "F" <<endl;
       //el dir existe y por lo tanto no podemos crearlo
       strcpy (mensaje, "Lo lamento, el dir ya existe");
       Respuesta = ERROR;
     } else {

       cout << "G" <<endl;
       //el dir no existe y hay que insertarlo ordenadamente
       //reseteamos el dircol
       DirCol = s->dirActual->izq;
       cout << "H" <<endl;


       while((DirCol != NULL) && (encontre == false)){
         cout << "I" <<endl;
         //comparamos en que lugar colocar
         //Armo el nombre completo del DIR para comparar el criterio de ordenamiento
         strcpy(nomDirAct,DirCol->nombre);
         // Compara, si es mayor va despues
         if(strcmp(nom,nomDirAct) > 0){
           encontre = true;
           cout << "J" <<endl;
         }else{
           DirCol = siguienteDir(DirCol);
           cout << "K" <<endl;
         }
       }

       if(!encontre) {

         //DirCol = nuevo;
         s->dirActual->izq = nuevo;
         cout << "L" <<endl;

       } else {
         cout << "M" <<endl;
         nuevo->izq = DirCol->izq;
         DirCol->izq = nuevo;

       }
       strcpy (mensaje, "Se ha creado el archivo.");
       Respuesta = OK;
     }
   } //cierra estoy en en nivel de la raiz

   //ahora estoy en el arbol
   else {

       //consulto si hay algun otro dir
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

         if(!encontre) {
           //DirCol->izq = nuevo;
           s->dirActual->der = nuevo;

         } else {
           nuevo->izq = DirCol->izq;
           DirCol->izq = nuevo;
           s->dirActual->der = DirCol;
         }
         strcpy (mensaje, "Se ha creado el archivo.");
         Respuesta = OK;
       }

   }


  }

  cout << mensaje << endl;
  return Respuesta;
  }
