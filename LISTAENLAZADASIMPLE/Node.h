#ifndef NODE_H
#define NODE_H

class Node {
    int value;
    Node *nextNode{nullptr};

    public:
        void setValue(int newValue);
        void setNextNode(Node *newNextNode);
        int getValue();
        Node *getNextNode();
};

#endif