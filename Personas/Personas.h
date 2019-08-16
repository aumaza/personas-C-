#ifndef __PERSONAS_H
#define __PERSONAS_H
#include "ArrayList.h"
#include <iostream>
#include <string>



using namespace std;

class Personas
{
private:
  int id;
  string nombre;
  string apellido;
  int edad;
  string dni;
  int isEmpty;
  
public:
  
  Personas(int Id, string Nombre, string Apellido, int Edad, string Dni, int IsEmpty);//CONSTRUCTOR PARAMETRIZADO
  Personas();//CONSTRUCTOR VOID
  ~Personas();//DESTRUCTOR
  
  //SETTERS
  void set_id(int ID);
  void set_nombre(string Nombre);
  void set_Apellido(string Apellido);
  void set_edad(int Edad);
  void set_dni(string Dni);
  void set_isEmpty(int IsEmpty);
  
  //GETTERS
  int get_id();
  string get_nombre();
  string get_apellido();
  int get_edad();
  string get_dni();
  int get_isEmpty();
  
  //METHODS
  string mostrarPersona();
  string mostrarUnaPersona(Personas* onePersona);
  string mostrarPersonas (ArrayList* lista, Personas* onePersona);
  int add(ArrayList* lista, Personas* onePersona);
  int searchFreePersona(ArrayList* lista, Personas* pPersona);
  string findPersona(ArrayList* lista, Personas* pPersona);
  
  void header();
  void footer();
};



#endif // __PERSONAS_H