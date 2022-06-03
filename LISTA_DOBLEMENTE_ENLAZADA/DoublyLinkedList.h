/***********************************************************************
 * Module:  DoublyLinkedList.h
 * Author:  Alexander
 * Modified: jueves, 2 de junio de 2022 2:50:17
 * Purpose: Declaration of the class DoublyLinkedList
 ***********************************************************************/

#if !defined(__Listas_Doblemente_Enlazadas_DoublyLinkedList_h)
#define __Listas_Doblemente_Enlazadas_DoublyLinkedList_h

#include <List.h>
#include <Node.h>

class DoublyLinkedList : public List
{
public:
   Node* getFirstNode(void);
   void setFirstNode(Node* newFirstNode);
   Node* getLastNode(void);
   void setLastNode(Node* newLastNode);

protected:
private:
   Node* firstNode;
   Node* lastNode;


};

#endif