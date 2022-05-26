#include "Node.h"

void Node::setValue(int newValue) {
    this->value = newValue;
}

void Node::setNextNode(Node *newNextNode) {
    this->nextNode = newNextNode;
}

int Node::getValue() {
    return this->value;
}

Node *Node::getNextNode() {
    return this->nextNode;
}