// nuevo00000
bool esRuta(char nom){
  char nomruta[200];
  // aca cargarmos el nom en algo manejable
  strcpy (nomruta, nom});
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
    //procedimiento normal
    return false;
  }else if (cont == 2){
      if (PrimerCBarra(nomruta)){
        return false
      } else {
        return true;
      }
  }else{
    return true;
  }

}




//te guardas la posicion en caso de que falle y tengas que resetear
Directorio dirActual;
dirActual = s->dirActual;

// aca cargarmos el nom en algo manejable
strcpy (nomruta, nombreDirS);

// Se le agrega la barra para poder usar la func buscodir
agregarBarraFinal(nomruta);


//PARTE SE QUEDA CON EL ULTIMO
if(strcmp(nombreaux, "*") != 0){
  strcpy(aux, strtok(nombreaux, "/"));
  strcpy(resto,  strtok(NULL, "\0"));
  return vuleta
}

resto = al ultimo


if (esRuta) {
  buscoDir(s, nomruta)
}
