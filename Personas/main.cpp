#include "ArrayList.h"
#include "Personas.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main()
{
  //Personas *pPersona = new Personas(1,"Augusto","Maza",44,"24283493",1);
 //cout<<pPersona->mostrarPersona();
  
  ArrayList* lista = new ArrayList();
  Personas* pPersona = new Personas();
  
  pPersona->add(lista,pPersona);
  //pPersona->add(lista,pPersona);
  
  cout<<pPersona->mostrarPersonas(lista,pPersona);
  
  cout<<pPersona->findPersona(lista,pPersona);
  cout<<pPersona->mostrarUnaPersona(pPersona);
  
  /*int opcion;
  do{
      
  cout<<"========================"<<endl;
  cout<<"======== PERSONAS ======"<<endl;
  cout<<"1. Altas"<<endl;
  cout<<"2. Bajas"<<endl;
  cout<<"3. Modificaciones"<<endl;
  cout<<"4. Informes"<<endl;
  cout<<"5. Guardar Datos"<<endl;
  cout<<"0. Salir"<<endl;
  cout<<"========================"<<endl;
  cout<<"\nOpcion: ";
  cin.get();
  cin>>opcion;
  
  switch(opcion)
  {
        
    case 1: 
	pPersona->add(lista,pPersona);
      break;
    case 2:
      break;
    case 3:
      break;
    case 4: pPersona->mostrarPersonas(lista,pPersona);
      break;
    case 5:
      break;
  }
  }while(opcion != 0);*/
  
  
    return 0;
}
