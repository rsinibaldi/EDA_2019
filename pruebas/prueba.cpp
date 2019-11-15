#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <ctype.h>




using namespace std;





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

bool PrimerCBarra(char nombreDirS[]){

       return nombreDirS[0] == '/';

}

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


//
// void resto(char nombreaux[], char nombreArch[], char ruta[]){
//
//   char nombreRuta[200];
//   char rest[200],aux[200],aux2[200];
//   int pos;
//   bool esAbsoluta;
//
//   strcpy(nombreRuta, nombreaux);
//   // strcat(nombreRuta,"=");
//
//   std::cout << "nombreRuta 1: " << nombreRuta << '\n';
//
//     char str[] ="- This, a sample string.";
//     char * pch;
//     ruta[0] = '\0';
//
//     if(PrimerCBarra(nombreRuta)){
//       strcat(ruta,"/");
//     }
//     std::cout << "nombreRuta 2: " << nombreRuta << '\n';
//     std::cout << "ruta 1: " << ruta << '\n';
//     // pch = strtok (nombreRuta,"=");
//
//
//     std::cout << "ruta 2: " << pch << '\n';
//     strcat(ruta,pch);
//         // std::cout << "ruta 2.2: " << strcmp(pch,strtok(pch,"/")) << '\n';
//
//     while(strcmp(pch,strtok(pch,"/"))!=0){
//     std::cout << "ruta 3.1: " << pch << '\n';
//       strcpy(aux,pch);
//       strcat(ruta,aux);
//       strcat(ruta,"/");
//       strcpy(aux2,strtok (NULL, "="));
//       std::cout << "ruta 3.2: " << ruta <<"  - "<<aux << '\n';
//       pch = strtok (NULL, "/");
//     }
//
//     strcat(ruta,"*");
//     std::cout << "ruta 4: " << ruta << '\n';
//     strcpy(nombreArch,pch);
//
// }
// /****************************************************************************** */



void resto(char nombreaux[], char nombreArch[], char ruta[]){

  char nombreRuta[200];
  char rest[200],aux[200];
  bool esAbsoluta;

  strcpy(nombreRuta, nombreaux);

    char str[] ="- This, a sample string.";
    char * pch, * pos;
    ruta[0] = '\0';
    unsigned int intPos = 0;

    // for(int i = 0; i = strlen(nombreRuta); i++){
    //   if (nombreRuta[i] == '/') {
    //     pos = i;
    //   }
    // }

    pos=strrchr(nombreRuta,'/');
    std::cout << "--------- muestro pos:  " << pos-nombreRuta+1 << '\n';
    intPos = atoi(pos);
    std::cout << "--------- muestro pos2:  " << intPos << '\n';
    strncpy(nombreRuta, nombreRuta, intPos);
    std::cout << "--------- muestro strncpy:  " << nombreRuta << '\n';

    if(PrimerCBarra(nombreaux)){
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


int main(){

  char a[200];
  char b[200];
  char c[200];
  char d[200];
  int i = 0;
  bool res;

  strcpy(a,"/dir1/dir2/dir3");

  //   strcpy(a,d);
  strcat(d,"/dir1");
  strcat(d,"/dir2");
  strcat(d,"/dir3");

  // strcpy(b,strtok(a,"/"));
//  strcpy(c,strtok(NULL,""));
std::cout << "A tiene: " << d  << '\n';
  // std::cout << "b tiene: " << b << '\n';
  // // std::cout << "c tiene: " << c << '\n';
  //
  // if (b == NULL){
  //   std::cout << "b = null" << '\n';
  // }else{
  //   std::cout << "b != NULL" << '\n';
  // }

// res = esRutaAbsoluta(a);
 resto(a,b,c);
 std::cout << "El resto es:  a: " << a << " -  b: " << b << " -  c: " << c << '\n';

  // a[15]='\0';
  // while (a[i] != '\0'){
  //   i++;
  // }
  //  a[i] = '/';
  //  a[i+1] = '*';
  //  a[i+2] = '\0';
  //
  //    std::cout << "a tiene: " << a << '\n';
  //
  //




    return 0;
}
