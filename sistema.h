#ifndef SISTEMA_H 
#define SISTEMA_H


#define MAX 50
#define NOMBRE_MAX 16
#define EXT_MAX 4
#define ARCH_NOM_MAX 21
#define RENGLON_LARGO_MAX 50
#define TEXTO_LARGO 100


// DEFINIMOS FUNCION ERROR
enum retorno{
    OK, ERROR, NO_IMPLEMENTADA
};typedef enum retorno TipoRet;


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

// DEFINIMOS SISTEMA (CABZL ARCHIVO)
struct str_sistema{
    Archivo aprimero;
    Archivo aultimo;

    //Papelera
    Papelera papelera;

};typedef str_sistema * Sistema;




// CREACIÓN SISTEMA
// -----------------
Sistema crearSistema();
Papelera crearPapelera();
Archivo crearArchivo();
Linea crearLinea();
void init (Sistema &s, Archivo &a, Linea &l, Papelera &p);


// FUNCIONES TIPO 1
// -----------------

//PRE: No tiene, solo que si no hay arch no los puede mostrar
//POST: Muestra los archivos creados en el sistema
TipoRet DIR(Sistema &s/*, char parametro[], char &error*/);

//PRE: No Tiene
//POST: Crea un archivo nuevo en el sistema (Si cumple con las comprobaciones)
TipoRet CREATE(Sistema &s, char nombreArchivo[]/*, char &error*/);

//PRE: El archivo debe estar creado
//POST: Inserta una linea al final del archivo
TipoRet IF(Sistema &s, char nombreArchivo[], char texto[]/*, char error[]*/);

//PRE: El archivo debe existir
//POST: Muestra el contenido del archivo
TipoRet TYPE(Sistema &s, char nombreArchivo[]/*, char error[]*/);


// FUNCIONES TIPO 2
// -----------------

//PRE: El archivo a eliminar debe estar creado
//POST: "Borra" un archivo del sistema
TipoRet DELETE(Sistema &s, char nombreArchivo[]/*, char &error*/);

//PRE: El archivo debe estar creado
//POST: Devuelve el archivo con k menos lineas al final
TipoRet BF(Sistema &s, char nombreArchivo[], int k/*, char error[]*/);

//PRE: Los dos archivos deben existir y el segundo archvo debe tener lineas escritas
//POST: Concatena dos archivos (copia el cont de uno al final del otro)
TipoRet CAT(Sistema &s, char nombreArchivo1[], char nombreArchivo2[]/*, char error[]*/);


// FUNCIONES TIPO 3
// ------------------

//PRE: El archivo debe estar creado
//POST: Inserta una linea al comienzo del archivo
TipoRet IC(Sistema &s, char nombreArchivo[], char texto[]/*, char error[]*/);

//PRE: El archivo debe estar creado
//POST: Devuelve el archivo con k menos lineas al comienzo
TipoRet BC(Sistema &s, char nombreArchivo[], int k/*, char error[]*/);

//PRE: El archivo a restaurar no puede tener el mismo nombr que otro arch en el sist
//POST: Restaura un arch previamente borrado
TipoRet UNDELETE(Sistema &s/*, char &error*/);


// FUNCIONES AUXILIARES
// -----------------------

//PRE:El archivo debe estar creado
//POST:Devulve la cantidad de filas de un archivo
int CantLineas(Linea l);

//PRE: la lista sistema debe estar creada;
//POST: Devuele true si la lista es vacia, false en otro caso.
bool isEmptySistema(Sistema s);

//PRE: La lista archivos debe estar creada
//POST: Devuelve true si la lista es vacia, false en otro caso
bool isEmptyArchivo(Archivo a);

//PRE: La lista de lineas debe estar creada
//POST: Devuelve true si la lista es vacia, false en otro caso
bool isEmptyArchivoLineas(Linea l);

//PRE: recibe una lista con por lo menos 1 elemento.
//POST: Retorna la lista sin su primer elemento.
Archivo TailArchivo(Archivo a);

//PRE: la lista de archivos debe contener al menos un archivo
//POST: Compara nom y ext con los archivos de la lista para saber si estan repetidos
bool existeArchivo(Archivo ArchivosCol, char nom[], char ext[]);

//PRE: deben haber archivos sino no imprime
//POST: muestra toda la coleccion de archivos
void Imprimir_archivos(Archivo arch);

//pre: recibe una ListaArchivos creada.
//pos: busca en la lista el archivo y lo devuelve.
Archivo buscarArchivo(Sistema s, char nom[], char ext[]);

//pre:recibe un array
//pos:devuelve true en caso de que el texto se encuentr entre comiilas, false en caso contrario.
bool okComillas(char texto[]);



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







#endif // SISTEMA_H
