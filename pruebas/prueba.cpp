#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>       // std::cout
#include <string>         // std::string
#include <cstddef>         // std::size_t




using namespace std;


void CortarRuta (const std::string &ruta){
  std::cout << "Partiendo: " << ruta << '\n';
  std::size_t barra = ruta.find_last_of("/\\");
  std::cout << " Ruta: " << ruta.substr(0,barra) << '\n';
  std::cout << " archivo/carpeta: " << ruta.substr(barra+1) << '\n';
}

int main(){
string ruta1,ruta2;

ruta1 = "/dir1/dir2/dir3";
ruta2 = "c:\\windows\\winhelp.exe";

  CortarRuta (ruta1);
std::cout << "" << '\n';
  CortarRuta (ruta2);

    return 0;
}
