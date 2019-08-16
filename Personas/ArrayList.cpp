#include "ArrayList.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>

#define AL_INCREMENT 10
#define AL_INITIAL_VALUE 10

using namespace std;

//CONSTRUCTOR
ArrayList::ArrayList(void)
{
    size = 0; //AL_INITIAL_VALUE;
    elements = 0;
    array = new int[size];
    pElement = new void*[size];
    reservedSize = AL_INITIAL_VALUE;
}

//DESCTRUCTOR

ArrayList::~ArrayList()
{
  delete[] array;
}


//METHODS
int ArrayList::init ( int from )
{
  for(size_t i = from; i<size; i++)
  {
    array[i] = 0;
  }
}


int ArrayList::expand()
{
  size *= AL_INITIAL_VALUE;
  
  int *aux = new int[size];
  
  for(size_t i=0; i<elements; i++)
  {
    aux[i] = array[i];
  }
  
  delete[] array;
  
  array = aux;
  
  init(elements);
}

int ArrayList::add ( ArrayList* pList, void* pElement )
{
  int returnAux = -1;
  int ok = 0;
  
  if(pList != NULL && pElement > 0)
  {
    if(pList->size == pList->reservedSize)
    {
      ok = expand();
    }
    
    if(!ok)
    {
      pList->pElement = pElement;
      pList->size++;
      returnAux = 0;
    }
  }
  return returnAux;
}


int ArrayList::add(int el)
{
  if(elements >= size)
  {
    expand();
  }
  array[elements++] = el;
}

int ArrayList::get ( int index )
{
  if(index < 0 || index >= elements)
  {
    throw("out of bounds exception!");
  }
  return array[index];
}


int ArrayList::pop()
{
  if(elements > 0)
  {
    array[--elements] = 0;
  }
  
  else
  {
    throw("empty array");
  }
}


int ArrayList::len ( ArrayList* pList )
{
  int returnAux = -1;
  if(pList != NULL)
  {
    returnAux = pList->size;
  }
  return returnAux;
}


void* ArrayList::get ( ArrayList* pList, int index )
{
  void* returnAux = NULL;
  if(pList != NULL && index >=0 && index < pList->size)
  {
    returnAux = (pList+index)->pElement;
  }
  return returnAux;
}


int ArrayList::contains ( ArrayList* pList, void* pElement )
{
  int returnAux = -1;
  int is = 0;
  int i;
  
  if(pList != NULL && pElement != NULL)
  {
    for(i=0; i<pList->len(pList); i++)
    {
      if(pElement == (pList+i)->pElement)
      {
	is = 1;
	break;
      }
    }
    
    if(is)
    {
      returnAux = 1;
    }
    
    else
    {
      returnAux = 0;
    }
  }
  return returnAux;
}


int ArrayList::set ( ArrayList* pList, int index, void* pElement )
{
  int returnAux = -1;
  
  if(pList != NULL && pElement != NULL && index >= 0 && index < pList->size)
  {
    if(pList->size == index)
    {
      
    if(pList->size == pList->reservedSize)
    {
      resizeUp(pList);
    }
    pList->add(pList,pElement);
    }
  
  else
  {
    (pList+index)->pElement = pElement;
  }
  returnAux = 0;
  }
  return returnAux;
}


int ArrayList::contract ( ArrayList* pList, int index )
{
  int returnAux = -1;
  int i;
  
  if(pList != NULL && index >= 0 && index < pList->size)
  {
    for(i=0; i<pList->size; i++)
    {
      (pList+i)->pElement = (pList+index+1)->pElement;
    }
    pList->size--;
    returnAux = 0;
  }
  return returnAux;
}



int ArrayList::remove ( ArrayList* pList, int index )
{
  int returnAux = -1;
  
  if(pList != NULL && index >= 0 && index < pList->size)
  {
    contract(pList, index);
    returnAux = 0;
  }
  return returnAux;
}


int ArrayList::clear ( ArrayList* pList )
{
  int returnAux = -1;
  
  if(pList != NULL)
  {
    pList->pElement = realloc(pList->pElement,sizeof(void*)*AL_INCREMENT);
      
    if(pList->pElement != NULL)
    {
      pList->size = 0;
      pList->reservedSize = AL_INCREMENT;
      returnAux = 0;
    }
  }
  return returnAux;
}




int ArrayList::get_elements()
{
  return elements;
}


int ArrayList::resizeUp ( ArrayList* pList )
{
  int returnAux = -1;
  void** aux;
  
  if(pList !=NULL)
  {
    aux = (void**)realloc(pList->pElement,sizeof(void*)*(pList->reservedSize+AL_INCREMENT));
    
    if(aux != NULL)
    {
      pList->pElement = aux;
      pList->reservedSize += AL_INCREMENT;
      returnAux = 0;
    }
  }
  return returnAux;
}


int ArrayList::resizeDown ( ArrayList* pList )
{
  int returnAux = -1;
  void** aux;
  
  if(pList != NULL)
  {
    aux = (void**)realloc(pList->pElement,sizeof(void*)*(pList->reservedSize-AL_INCREMENT));
    
    if(aux != NULL)
    {
      pList->pElement = aux;
      pList->reservedSize -= AL_INCREMENT;
      returnAux = 0;
    }
  }
  return returnAux;
}



ArrayList* ArrayList::clone ( ArrayList* pList )
{
  ArrayList* returnAux = NULL;
  
  if(pList != NULL)
  {
    int i;
    returnAux = new ArrayList();
    
    if(returnAux != NULL)
    {
      for(i=0; i<pList->size; i++)
      {
	returnAux->add(returnAux,pList->get(pList,i));
      }
    }
  }
  return returnAux;
}


int ArrayList::expand ( ArrayList* pList, int index )
{
  int returnAux = -1;
  int i;
  
  if(pList != NULL && index >=0 && index < pList->size)
  {
    if(pList->size == pList->reservedSize)
    {
      resizeUp(pList);
    }
    for(i=pList->size; i>index; i++)
    {
      (pList+i)->pElement = (pList+i-1)->pElement;
    }
    returnAux = 0;
  }
  return returnAux;
}



int ArrayList::push ( ArrayList* pList, int index, void* pElement )
{
  int returnAux = -1;
  
  if(pList != NULL && index >=0 && index <= pList->size)
  {
    if(pList->size == index)
    {
      pList->add(pList,pElement);
    }
    
    else
    {
      expand(pList,index);
      pList->set(pList,index,pElement);
      pList->size++;
      returnAux = 0;
    }
      
  }
  return returnAux;
}


int ArrayList::indexOf ( ArrayList* pList, void* pElement )
{
  int returnAux = -1;
  int i;
  
  if(pList != NULL && pElement != NULL)
  {
    for(i=0; i<pList->len(pList); i++)
    {
      if((pList+i)->pElement == pElement)
      {
	returnAux = i;
	break;
      }
    }
  }
  return returnAux;
}


int ArrayList::isEmpty ( ArrayList* pList )
{
  int returnAux = -1;
  
  if(pList != NULL)
  {
    if(pList->len(pList) != 0)
    {
      returnAux = 0;
    }
    
    else
    {
      returnAux = 1;
    }
  }
  return returnAux;
}


void* ArrayList::pop ( ArrayList* pList, int index )
{
  void* returnAux = NULL;
  
  if(pList != NULL && index >= 0 && index < pList->size)
  {
    returnAux = pList->get(pList,index);
    pList->remove(pList,index);
  }
  
  return returnAux;
}


ArrayList* ArrayList::subList ( ArrayList* pList, int from, int to )
{
  ArrayList* subList = NULL;
  
  if(pList != NULL)
  {
    if(from >= 0 && from < pList->size && to >= 0 && to <= pList->size && from < to)
    {
      subList = new ArrayList();
      
      if(subList != NULL)
      {
	for(int i=from; i<to; i++)
	{
	  pList->add(subList,pList->get(pList,i));
	}
      }
    }
  }
  return subList;
}


int ArrayList::containsAll ( ArrayList* pList, ArrayList* pList2 )
{
  int returnAux = -1;
  int i;
  int flag = 0;
  
  if(pList != NULL && pList2 != NULL)
  {
    if(pList->len(pList) < pList2->len(pList2))
    {
      returnAux = 0;
    }
    
    else
    {
      for(i=0; i<pList2->len(pList2); i++)
      {
	if(!pList->contains(pList,pList2->get(pList2,i)))
	{
	  flag = 0;
	  break;
	}
      }
	if(flag)
	{
	    returnAux = 0;
	}
	else
	{
	  returnAux = 1;
	}
      }
    }
    return returnAux;
    
  }
  

int ArrayList::sort ( ArrayList* pList, int (*pFunc) (void*,void*), int order )
{
    int returnAux = -1;
    void* aux = NULL;
    int tam;
    
    if(pList != NULL && pFunc != NULL && order >= 0 && order <= 1)
    {
      tam = pList->len(pList);
      
      for(int i=0; i<tam-1; i++)
      {
	for(int j=i+1; j<tam; j++)
	{
	  if(order)
	  {
	    if(pFunc(pList->get(pList,i), pList->get(pList,j)) > 0)
	    {
	      aux = pList->get(pList,i);
	      pList->set(pList,i,pList->get(pList,j));
	      pList->set(pList,j,aux);
	    }
	  }
	  else
	  {
	    if(pFunc(pList->get(pList,i),pList->get(pList,j)) < 0)
	    {
	      aux = pList->get(pList,i);
	      pList->set(pList,i,pList->get(pList,j));
	      pList->set(pList,j,aux);
	    }
	  }
	}
      }
	returnAux = 0;
      }
      return returnAux;
}



int ArrayList::map ( ArrayList* pList, void ( *pFunc )(void*))
{
  int aux = 0;
  
  if(pList!= NULL && pFunc != NULL)
  {
    for(int i=0; i<pList->len(pList); i++)
    {
	pFunc(pList->get(pList,i));
    }
    aux = 1;
  }
  return aux;
}


ArrayList* ArrayList::filter ( ArrayList* pList, int (*pFunc)(void*))
{
  ArrayList* subList = NULL;
  int aux = -1;
  subList = new ArrayList();
  
  if(subList != NULL)
  {
    for(int i=0; i<pList->len(pList); i++)
    {
      aux = pFunc(pList->get(pList,i));
      
      if(subList != NULL && aux == 1)
      {
	subList->add(subList,pList->get(pList,i));
      }
    }
  }
  return subList;
}







