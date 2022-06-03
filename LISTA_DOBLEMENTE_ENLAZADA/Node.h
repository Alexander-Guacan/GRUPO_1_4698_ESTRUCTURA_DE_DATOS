#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
    T data;
    Node<T> *nextNode{nullptr};
    Node<T> *previousNode{nullptr};

    public:
        T getData();
        void setData(T newData);
        Node<T> *getNextNode();
        void setNextNode(Node<T> *newNextNode);
        Node<T> *getPreviousNode();
        void setPreviousNode(Node<T> *newPreviousNode);
        Node(T initialData);
        ~Node();
};

template <typename T>
T Node<T>::getData() {
    return data;
}

template <typename T>
void Node<T>::setData(T newData) {
    data = newData;
}

template <typename T>
Node<T> *Node<T>::getNextNode() {
    return nextNode;
}

template <typename T>
void Node<T>::setNextNode(Node<T> *newNextNode) {
    nextNode = newNextNode;
}

template <typename T>
Node<T> *Node<T>::getPreviousNode() {
    return previousNode;
}

template <typename T>
void Node<T>::setPreviousNode(Node<T> *newPreviousNode) {
    previousNode = newPreviousNode;
}

template <typename T>
Node<T>::Node(T initialData) : data(initialData) {}

template <typename T>
Node<T>::~Node() {
    // TODO : implement
}

#endif