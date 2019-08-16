#include "ArrayList.h"
#include "Personas.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <sstream>


using namespace std;

//CONSTRUCTOR PARAMETRIZADO
Personas::Personas ( int Id, string Nombre, string Apellido, int Edad, string Dni, int IsEmpty )
{
  id = Id;
  nombre = Nombre;
  apellido = Apellido;
  edad = Edad;
  dni = Dni;
  isEmpty = IsEmpty;
  
}

//CONSTRUCTOR GENERICO
Personas::Personas()
{
  id = 0;
  nombre = "";
  apellido = "";
  edad = 0;
  dni = "";
  isEmpty = 0;
}


//DESTRUCTOR
Personas::~Personas()
{
  
}


//SETTERS

void Personas::set_id ( int ID )
{
  id = ID;
}

void Personas::set_nombre ( string Nombre )
{
  nombre = Nombre;
}

void Personas::set_Apellido ( string Apellido )
{
  apellido = Apellido;
}

void Personas::set_edad ( int Edad )
{
  edad = Edad;
}

void Personas::set_dni ( string Dni )
{
  dni = Dni;
}

void Personas::set_isEmpty ( int IsEmpty )
{
  isEmpty = IsEmpty;
}


//GETTERS

int Personas::get_id()
{
  return id;
}

string Personas::get_nombre()
{
  return nombre;
}

string Personas::get_apellido()
{
  return apellido;
}

int Personas::get_edad()
{
  return edad;
}

string Personas::get_dni()
{
  return dni;
}

int Personas::get_isEmpty()
{
  return isEmpty;
}


//LISTADOS
void Personas::header()
{
  cout<<"ID       NOMBRE         APELLIDO         EDAD        DNI"<<endl;
  cout<<"================================================================"<<endl;
}

void Personas::footer()
{
  cout<<"================================================================"<<endl;
}



string Personas::mostrarPersona()
{
  stringstream M;
  
  header();
  M<<id;
  M<<"\t"<<nombre;
  M<<"\t\t"<<apellido;
  M<<"\t\t  "<<edad;
  M<<"\t   "<<dni;
  footer();
  return M.str();
}

string Personas::mostrarUnaPersona ( Personas* onePersona )
{
  stringstream P;
 
  P<<"\n"<<onePersona->id;
  P<<"\t"<<onePersona->nombre;
  P<<"\t\t"<<onePersona->apellido;
  P<<"\t\t   "<<onePersona->edad;
  P<<"\t\t   "<<onePersona->dni;

  return P.str();
}

string Personas::mostrarPersonas ( ArrayList* lista, Personas* onePersona )
{
   
  int counter = 0;
  stringstream M;
  
  header();
  if(lista != NULL && onePersona != NULL)
  {
     
      for(int i=0; i<lista->len(lista);i++)
      {
	onePersona = (Personas*)lista->get(lista,i);
  
      if(onePersona->isEmpty == 1)
	{
	    M<<mostrarUnaPersona(onePersona);
	    counter++;
	}
      }
  }
  
  M<<"\nHay "<<counter<<" Personas"<<endl;
  
  return M.str();
}


int Personas::add ( ArrayList* lista, Personas* onePersona)
{
  int id = searchFreePersona(lista,onePersona)  ;
  
  if(lista != NULL && onePersona != NULL)
  {
    onePersona->id = id+2;
    
    cout<<"\nIngrese Nombre: ";
    getline(cin,onePersona->nombre);
    
    cout<<"\nIngrese Apellido: ";
    getline(cin,onePersona->apellido);
    
    cout<<"\nIngrese Edad: ";
    cin>>onePersona->edad;
    cin.get();
    
    cout<<"\nIngrese DNI: ";
    getline(cin,onePersona->dni);
    
    onePersona->isEmpty = 1;
    
    lista->add(lista,onePersona);
    
  }
  
  else
  {
    return 1;
  }
}


int Personas::searchFreePersona ( ArrayList* lista, Personas* pPersona )
{
    int index=-1;
  
    for(int i=0; i<lista->len(lista); i++)
    {
      pPersona = (Personas*)lista->get(lista,i);
      
        if(pPersona->id < 0 || pPersona->id == lista->len(lista))
        {
            index=i;
            break;
        }
    }
    return index;
}

string Personas::findPersona ( ArrayList* lista, Personas* pPersona )
{
    int flag = 0;
    string dni;
    stringstream M;
    
    cout<<"\nIngrese DNI: ";
    getline(cin,dni);
      
                  
    for(int i=0; i<lista->len(lista); i++)
    {
        pPersona = (Personas*)lista->get(lista,i);

        if(pPersona->dni.compare(dni) == 0 && pPersona->isEmpty == 1)
        {
            M<<mostrarUnaPersona(pPersona);
            flag = 1;
        }
    }
        
    if(flag == 0)
    {
        M<<"\nNo existe registro!!";
    }
   
    return M.str();
}









