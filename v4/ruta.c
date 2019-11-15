

//te guardas la posicion en caso de que falle y tengas que resetear
Directorio dirActual;
dirActual = s->dirActual;

// aca cargarmos el nom en algo manejable
strcpy (nomruta, nombreDirS);

// Se le agrega la barra para poder usar la func buscodir
agregarBarraFinal(nomruta);






//consultamos si es abs o relativo
if(PrimerCBarra(nomruta)){
  // nos paramos al inicio del arbol y e igualamos el dir col a eso
  s->dirActual = s->directorio;
}
//sino, dejamos el dir actual como esta




if(strcmp(nombreaux, "*") != 0){
  strcpy(aux, strtok(nombreaux, "/"));
  strcpy(resto,  strtok(NULL, "\0"));
  return vuleta
}
return resto


if (esRuta) {
  buscoDir(s, nomruta)
}
