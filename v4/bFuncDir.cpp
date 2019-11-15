
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <string.h>


//#include "aStruct.h"
#include "bFuncDir.h"
using namespace std;


// FUNCIONES AUX DIRECTORIO


bool esRuta(char nom[]){
 char nomruta[200];
 // aca cargarmos el nom en algo manejable
 strcpy(nomruta, nom);
 //contador parametros
 //vemos si tiene mas de un parametro
 int i=0;
 int cont=0;
 while (nomruta[i] != '\0') {
   if (nomruta[i] == '/') {
     i++;
     cont++;
   }
 }

 if (cont == 1){
   std::cout << "esRuta A " << '\n';
   //procedimiento normal
   return false;
 }else if (cont == 2){
   std::cout << "esRuta B " << '\n';
     if (PrimerCBarra(nomruta)){

         std::cout << "esRuta C " << '\n';
       return false;
     } else {
       std::cout << "esRuta D " << '\n';
       return true;
     }
 }else{

     std::cout << "esRuta E " << '\n';
   return true;
 }

}

void DameArchivoRuta(char nombreaux[], char nombreArch[], char ruta[]){

  char nombreRuta[200];
  char rest[200],aux[200];
  bool esAbsoluta;

  strcpy(nombreRuta, nombreaux);

  char * pch;
  ruta[0] = '\0';

  if(PrimerCBarra(nombreRuta)){
    strcat(ruta,"/");
  }

  pch = strtok (nombreRuta,"/");

  strcat(ruta,pch);
  while(strcmp(pch,strtok(pch,"/"))!=0){
    strcpy(aux,pch);
    strcat(ruta,pch);
    strcat(ruta,"/");
    pch = strtok (NULL, "/");
  }

  strcat(ruta,"*");
  strcpy(nombreArch,pch);

}

//PARA COMPROBAR EXISTENCIA
bool existeDir(Directorio DirCol, char nom[]){
    if(!isEmptyDirectorio(DirCol)){
        if (strcmp(DirCol->nombre, nom) == 0){
            return true;
        }else{
            return existeDir(siguienteDir(DirCol), nom);
        }
    }
   return false;
}


//PARA CD
bool existeDir2(Sistema &s, char nom[]){

  char nombred[100],nombreDirCol[100];
  nombred[0]= '\0';
  nombreDirCol[0]= '\0';

  //paso nom de lo que voy a buscar a algo manejable
  strcpy(nombred, nom);

  //seteo el dircol en donde estamos parados
  Directorio DirCol = s->dirActual;

  if (isEmptyDirectorio(DirCol)) {
    return false;

  } else if (strcmp(DirCol->nombre, nombred) == 0){
        return true;

  }else{
    DirCol = DirCol->izq;
    s->dirActual = DirCol;
    return existeDir2(s, nombred);

  }
}


//PARA CD TAMBIEN
bool buscoDir(Sistema &s, char nom[]){

  char nombreaux[300],aux[100], resto[200];
  nombreaux[0]= '\0';
  aux[0]= '\0';
  resto[0]= '\0';

  // aca cargarmos el nom en algo manejable
  strcpy (nombreaux, nom);

  // Se le agrega la barra y el tope para poder frenar
  //no puede ir aca por el llamado recursivo
  //agregarBarraFinal(nombreaux);

  //CON ESTO PARAMOS LA CARRERA
  if(strcmp(nombreaux, "*") != 0){
    //baja de nivel
    s->dirActual = s->dirActual->der;
    strcpy(aux, strtok(nombreaux, "/"));
    strcpy(resto,  strtok(NULL, "\0"));

        if(existeDir2(s, aux)) {
          return buscoDir(s, resto);

        } else {
          return false;

        }

  } else {
    return true;

  }
}




void agregarBarraFinal(char nom[]){
  int i = 0;
  // aca cargarmos el nom en algo manejable
  char nomruta[200];
  nomruta[0] = '\0';
  strcpy (nomruta, nom);
  //agregar barra al final de nomruta
  while (nomruta[i] !='\0'){
    i++;
  }
  nomruta[i] = '/';
  nomruta[i+1] = '*';
  nomruta[i+2] = '\0';

  strcpy (nom, nomruta);

}


bool PrimerCBarra(char nombreDirS[]){

      char nomd[200];
      //aux[0] = '\0';

      //copiamos para poder manejarlo y no tener problemas
      strcpy(nomd, nombreDirS);
      //aca nos quedamos con lo primero hasta la barra
      //strcpy(aux, strtok(nombre, "/"));
      // consultamos si efectivamente es abs o no

      if(nomd[0] == '/') {
        return true;
      }else{
        return false;
      }

}



// PARA PWD
void imprimoPadres(Directorio d){
      if(d->padre != NULL) {

            imprimoPadres(d->padre);
            cout << "/" << d->nombre ;
      } else {
        cout << "/" ;
      }
}

//DIR
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





//PARA MOVERSE
Directorio siguienteDir(Directorio d){
    return d->izq;
}
Directorio subDir(Directorio d){
    return d->der;
}
bool isEmptyDirectorio(Directorio d){
    return (d == NULL);
}





bool ultimaVuelta(char nombreDirectorio[]){
      char nom[100];
      strcpy(nom, nombreDirectorio);
      if(nom[0] == '/'){
        return true;
      }else{
        return false;
      }

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



//pre: a no es vacio
//post: borra el valor x del arbol a.
void borrarDir(Directorio &d, char NombreDir[]){
  if (!isEmptyDirectorio(d)){
      //Si mi dir no es
      if (strcmp(NombreDir,d->nombre) != 0){
        //Me fijo si el siguiente al mio es el que tengo q borrar
        if (strcmp(NombreDir,d->izq->nombre) == 0){
          // lo encontre, guardo aux con el dir que tengo q eliminar
          Directorio aux = d->izq;

          //llamo a borrar los archivos
          Archivo archaux = aux->aprimero;
          Directorio dirDer = aux->der;
          borrarArchivos(aux->aprimero);
          borrarSubDir(aux->der);
          // si el siguiente de mi aux no es null apunto en dir en el que estoy al siguiente que quiero.
          //osea que asalteo el que voy a borrar
          if (!isEmptyDirectorio(aux->izq)){
            d->izq = aux->izq;
          }else{
            //ya que el directorio siguiente al que borro no existe apunto el actual a null.
            //osea, estoy borrando el ultimo dir
            d->izq = NULL;
          }
          delete aux;


        }else{
          //Si el siguiente al que estoy verificando no es el dir, llamo a la fubncion recursiva
          borrarDir(d->izq, NombreDir);
        }

      }else{ // lo encontre y es el primer nodo, osea que apunto el padre al siquiente de la lista y elimino el aux
             // que es el dir actual
          Directorio aux = d;
          //llamo a borrar los archivos
          Archivo archaux = d->aprimero;
          Directorio dirDer = d->der;
          borrarArchivos(archaux);
          borrarSubDir(dirDer);

          if(!isEmptyDirectorio(d->izq)){
            d->padre->der = d->izq;

          }else{
            d->padre->der = NULL;
          }
          delete aux;
      }
  }
}

void borrarArchivos(Archivo &a){
  //En teoria llego al final de los archivos y ahi los comienza eliminar, hasta llegar al primero
  if (!isEmptyArchivo(a)){
    borrarArchivos(a->sig);
    delete a;
    a = NULL;
  }

}

void borrarSubDir(Directorio &d){
  //En teoria llego al final de los archivos y ahi los comienza eliminar, hasta llegar al primero
  if (!isEmptyDirectorio(d)){
    borrarSubDir(d->der);
    borrarSubDir(d->izq);
    delete d;
    d = NULL;
  }

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
