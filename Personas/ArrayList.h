#ifndef __ARRAYLIST_H
#define __ARRAYLIST_H
#include <iostream>
#include <string>


class ArrayList
{
private:
  int size;
  int elements; // for int values
  int *array;
  void *pElement;
  int reservedSize;
   
  
public:
  //CONSTRUCTOR
  ArrayList();
  //DESTRUCTOR
  ~ArrayList();
  
  //METHODS
  int init(int from);
  int expand(); //for int values
  int add(ArrayList* pList, void* pElement); // for ArrayList 
  int add(int el); // for int values
  int get(int index); // for int values
  int pop(); // for int values
  int len(ArrayList* pList);
  void* get(ArrayList* pList, int index);
  int contains(ArrayList* pList, void* pElement);
  int set(ArrayList* pList, int index, void* pElement);
  int resizeUp(ArrayList* pList);
  int resizeDown(ArrayList* pList);
  int remove(ArrayList* pList, int index);
  int contract(ArrayList* pList, int index);
  int clear(ArrayList* pList);
  ArrayList* clone(ArrayList* pList);
  int push(ArrayList* pList, int index, void* pElement);
  int expand(ArrayList* pList, int index);
  int indexOf(ArrayList* pList, void* pElement);
  int isEmpty(ArrayList* pList);
  void* pop(ArrayList* pList, int index);
  ArrayList* subList(ArrayList* pList, int from, int to);
  int containsAll(ArrayList* pList, ArrayList* pList2);
  int sort(ArrayList* pList, int (*pFunc) (void*,void*), int order);
  int map(ArrayList* pList, void (*pFunc)(void*));
  ArrayList* filter(ArrayList* pList, int (*pFunc)(void*));
  
  int get_elements();
  
  
};




#endif // __ARRAYLIST_H