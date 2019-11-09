TipoRet cd (Sistema &s, string nombreDirS){

TipoRet Respuesta;
Directorio DirCol;
Directorio dirActual;
char nombreDirAbuscar[100];

strcpy(nombreDirAbuscar, nombreDirS);

// agregarBarra(nombreDirAbuscar[]);
//comprobamos que el sistema no sea vacio
if (isEmptyDir(s->directorio)) { // capaz izquierdo

        strcopy (mensaje, "no hay directorios en el sistema");
        Respuesta = ERROR;

}else{


    if(PrimerCBarra(nombreDirAbuscar)){ //Caso de Ruta Absoluta //Funcion PrimerCBarra borra el caracter '/'

        dirActual = s->directorio;
        DirCol = dirActual;

        if(buscoDir(DirCol, nombreDirS)){
           s->dirActual = DirCol;
           mensaje = "OK: La busqueda se ejecuto satisfactoriamente";
           Respuesta = OK;

        }else{

           DirCol = dirActual;
           mensaje = "Error: La ruta es invalida";
           Respuesta = ERROR;

         }

    }else{                        //Caso de Ruta Relativa

            Dircol = s->dirActual;

            Dircol = Dircol->der; //como es relativo bajamos un novel para comenzar la busqueda
            //si no ejecuta todo bien va a sobrar caracteres en
            if(buscoDir(DirCol, nombreDirS)){
              s->dirActual = DirCol;
              mensaje = "OK: La busqueda se ejecuto satisfactoriamente";
              Respuesta = OK;

            }else{

              mensaje = "Error: La ruta es invalida";
              Respuesta = ERROR;

            }
        }

    }

}

--------------------------------------------------------------------

//Hay que ver el tema de los strings y los char todavia sigo con problemitas con eso.
bool buscoDir(Directorio d, char nom[]){

      char nuevo[], busco[];
      if(nom[0] != '\0'/*&&(subDir(d)!=NULL)*/){

            busco = strtok(nom,'/'); //Tomamos el nombre del directorio a buscar en el nivel que nos encontramos
            //acordarse de poner una barra al final (condicion) o excluirla desde aca.
            if(busco == NULL){
                  strcpy(busco, nom);
            }else{
                  nuevo = strtok(nom,'\0'); //dejamos el resto de niuestro string para recursividad
            }
            if(existeDir(d, busco){
                  return  buscoDir(subDir(d), nuevo);
            }else{
                  return false;
            }

      }
      return true;
}


bool PrimerCBarra(char nombreDirS[]){
      char aux[100];
    //  strcpy(nombre, nombreDir);  //no seguro que funke
      //aux = strtok(nombre, '/');
      strcpy(aux,strtok(nombreDirS, '/'));
      if (aux == NULL){
            return true;
      }else{
            return false;
      }
      //borrar la barra
}
//
// void agregarBarra(char nombre[]){
//     int pos = 0;
//     while(nombre[pos] != '\0'){
//           pos++;
//     }
//     nombre[pos] = '/';
//     pos++;
//     nombre[pos] = '\0';
// }



    //si el primer caracter es barra es abs
    //mandamos el dir actual a la raiz

    // if (strcmp (/, palabra1) == 0) {
    //         //estoy en la raiz
    //         //ruta absoluta
    //         dirActual = s->directorio;
    //         DirCol = dirActual;
    //
    //         if (!existeDir(DirCol,palabra1)) {
    //         strcopy (mensaje, "no existe el dir");
    //         Respuesta = ERROR;
    //
    //     } else {
    //
    //         //lo encontro.
    //         //dir col apunta a ese nodo
    //
    //         dirCol = DirCol->der;
    //
    //         if (!existeDir(DirCol,palabra2)) {
    //         strcopy (mensaje, "no existe el dir");
    //         Respuesta = ERROR;
    //
    //         } else {
    //
    //             //existe la palabra dos
    //
    //             dirCol = DirCol->der;
    //
    //             if (!existeDir(DirCol,palabra2)) {
    //             strcopy (mensaje, "no existe el dir");
    //             Respuesta = ERROR;
    //
    //             } else {
    //
    //                 //existe la palabra dos
