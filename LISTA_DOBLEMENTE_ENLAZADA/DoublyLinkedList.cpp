/***********************************************************************
 * Module:  DoublyLinkedList.cpp
 * Author:  Alexander
 * Modified: jueves, 2 de junio de 2022 2:50:17
 * Purpose: Implementation of the class DoublyLinkedList
 ***********************************************************************/

#include "DoublyLinkedList.h"

////////////////////////////////////////////////////////////////////////
// Name:       DoublyLinkedList::getFirstNode()
// Purpose:    Implementation of DoublyLinkedList::getFirstNode()
// Return:     Node*
////////////////////////////////////////////////////////////////////////

Node* DoublyLinkedList::getFirstNode(void)
{
   return firstNode;
}

////////////////////////////////////////////////////////////////////////
// Name:       DoublyLinkedList::setFirstNode(Node* newFirstNode)
// Purpose:    Implementation of DoublyLinkedList::setFirstNode()
// Parameters:
// - newFirstNode
// Return:     void
////////////////////////////////////////////////////////////////////////

void DoublyLinkedList::setFirstNode(Node* newFirstNode)
{
   firstNode = newFirstNode;
}

////////////////////////////////////////////////////////////////////////
// Name:       DoublyLinkedList::getLastNode()
// Purpose:    Implementation of DoublyLinkedList::getLastNode()
// Return:     Node*
////////////////////////////////////////////////////////////////////////

Node* DoublyLinkedList::getLastNode(void)
{
   return lastNode;
}

////////////////////////////////////////////////////////////////////////
// Name:       DoublyLinkedList::setLastNode(Node* newLastNode)
// Purpose:    Implementation of DoublyLinkedList::setLastNode()
// Parameters:
// - newLastNode
// Return:     void
////////////////////////////////////////////////////////////////////////

void DoublyLinkedList::setLastNode(Node* newLastNode)
{
   lastNode = newLastNode;
}