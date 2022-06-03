/***********************************************************************
 * Module:  Menu.h
 * Author:  Alexander
 * Modified: jueves, 2 de junio de 2022 19:22:04
 * Purpose: Declaration of the class Menu
 ***********************************************************************/

#if !defined(__Listas_Doblemente_Enlazadas_Menu_h)
#define __Listas_Doblemente_Enlazadas_Menu_h

class Menu
{
public:
   void start(void);
   char printOptions(void);
   void insertAtBegin(List<T>* list);
   void insertAtEnd(List<T>* list);
   void insertAt(List<T>* list);
   void searchFromBegin(List<T>* list);
   void searchFromEnd(List<T>* list);
   void deleteFirst(List<T>* list);
   void deleteLast(List<T>* list);
   void deleteAt(List<T>* list);

protected:
private:

};

#endif