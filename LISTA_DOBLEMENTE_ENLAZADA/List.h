/***********************************************************************
 * Module:  List.h
 * Author:  Alexander
 * Modified: jueves, 2 de junio de 2022 2:32:01
 * Purpose: Declaration of the class List
 ***********************************************************************/

#if !defined(__Listas_Doblemente_Enlazadas_List_h)
#define __Listas_Doblemente_Enlazadas_List_h

class List
{
public:
   virtual bool isEmpty(void)=0;
   virtual int size(void)=0;
   virtual void insertAtBegin(T data)=0;
   virtual void insertAtEnd(T data)=0;
   virtual void insertAt(T data, int position)=0;
   virtual bool searchFromBegin(T data)=0;
   virtual bool searchFromEnd(T data)=0;
   virtual bool deleteAtBegin(void)=0;
   virtual bool deleteAtEnd(void)=0;
   virtual bool deleteAt(int position)=0;

protected:
private:

};

#endif