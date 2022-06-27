#ifndef NODE_HPP
#define NODE_HPP

template <typename T>
class Node {
    private:
        T data{};
        Node<T> *nextNode{nullptr};
        Node<T> *previousNode{nullptr};

    public:
        Node(const T &initialData);
        T &getData();
        Node<T> *getNextNode() const;
        Node<T> *getPreviousNode() const;
        void setData(const T &newData);
        void setNextNode(Node<T> *newNextNode);
        void setPreviousNode(Node<T> *newPreviousNode);
        ~Node();
};

template <typename T>
Node<T>::Node(const T &initialData) {
    this->data = initialData;
}

template <typename T>
T &Node<T>::getData() {
    return this->data;
}

template <typename T>
Node<T> *Node<T>::getPreviousNode() const {
    return this->previousNode;
}

template <typename T>
Node<T> *Node<T>::getNextNode() const {
    return this->nextNode;
}

template <typename T>
void Node<T>::setData(const T &newData) {
    this->data = newData;
}

template <typename T>
void Node<T>::setPreviousNode(Node<T> *newPreviousNode) {
    this->previousNode = newPreviousNode;
}

template <typename T>
void Node<T>::setNextNode(Node<T> *newNextNode) {
    this->nextNode = newNextNode;
}

template <typename T>
Node<T>::~Node() {
    this->data = nullptr;
    this->nextNode = nullptr;
    this->previousNode = nullptr;
}

#endif