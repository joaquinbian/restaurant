#include <iostream>
using namespace std;

#include "Examen.h"
#include "ServicioMesa.h"
#include "ArchivoServicioMesa.h"

void Examen::EjemploDeListado(){
   ArchivoServicioMesa archivo("restaurant.dat");
   ServicioMesa registro;

   int i, cantidadRegistros = archivo.CantidadRegistros();
   for(i = 0; i < cantidadRegistros; i++){
      registro = archivo.Leer(i);
      cout << registro.toCSV() << endl;
   }
}



void Examen::Punto1(){
   // ¿Cuál es la cantidad de mozos distintos que no recibieron propina, en al menos uno de los servicios de mesa que atendió? 
   ArchivoServicioMesa archivo("restaurant.dat");
   ServicioMesa registro;
   int cantidadRegistros = archivo.CantidadRegistros();
   int contador = 0;
   bool idMozos[20] = {};

   for(int i = 0; i < cantidadRegistros; i++){
      registro = archivo.Leer(i);

      if(registro.getPropina() == 0){
         if(!idMozos[registro.getIDMozo()-1]){
            idMozos[registro.getIDMozo()-1] = true;
         }
      }
   }

   for(int i = 0; i < 20; i++){
      if(idMozos[i]){
         contador++;
      }
   }
   std::cout<<"la cantidad de mozos distintos que no recibieron propina es de " << contador << std::endl;


}

void Examen::Punto2(){
//¿Qué números de mozo no obtuvieron nunca un puntaje de 10 pero tampoco un 1?
   bool idMozos[20] = {};
   ArchivoServicioMesa archivo("restaurant.dat");
   ServicioMesa registro;
   int cantidadRegistros = archivo.CantidadRegistros();
   int pos;


   for(int i = 0; i < 20; i++){
      idMozos[i] = true;
   }

   for(int i = 0; i < cantidadRegistros; i++){
      registro = archivo.Leer(i);
      if(registro.getPuntajeObtenido() == 10 || registro.getPuntajeObtenido() == 1){
         idMozos[registro.getIDMozo() - 1] = false;
      }
   }

   for(int i = 0; i < 20; i++){
      if(idMozos[i] == true){
         std::cout << "el mozo " << i + 1 << " nunca recibio propina "<< std::endl;
      }
   }


}

void Examen::Punto3(){
   //¿Qué plato se vendió más veces en el 2024 que en el 2023?
   ArchivoServicioMesa archivo("restaurant.dat");
   ServicioMesa registro;

   int cantidadRegistros = archivo.CantidadRegistros();

   int contadorPlatos2024[70] = {};
   int contadorPlatos2023[70] = {};

   for(int i = 0; i < cantidadRegistros; i++){
      registro = archivo.Leer(i);

      if(registro.getFecha().getAnio() == 2023){
         contadorPlatos2023[registro.getIDPlato() - 1]++;
      }
      if(registro.getFecha().getAnio() == 2024){
         contadorPlatos2024[registro.getIDPlato() - 1]++;
      }
   }


   for(int i = 0; i < 70;i++){
      if(contadorPlatos2024[i] > contadorPlatos2023[i]){
         std::cout<<"el plato " << i+1 << " se vendio mas veces en 2024 que en 2023 " << std::endl;
      }
   }
}
