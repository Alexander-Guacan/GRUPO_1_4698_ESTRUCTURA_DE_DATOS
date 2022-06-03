/***********************************************************************
 * Module:  Node.h
 * Author:  Alexander
 * Modified: jueves, 2 de junio de 2022 2:50:51
 * Purpose: Declaration of the class Node
 ***********************************************************************/

#if !defined(__Listas_Doblemente_Enlazadas_Node_h)
#define __Listas_Doblemente_Enlazadas_Node_h

class Node
{
public:
   T getData(void);
   void setData(T newData);
   Node* getNextNode(void);
   void setNextNode(Node* newNextNode);
   Node* getPreviousNode(void);
   void setPreviousNode(Node* newPreviousNode);
   Node(T initialData);
   ~Node();

protected:
private:
   T data;
   Node* nextNode;
   Node* previousNode;


};

#endif