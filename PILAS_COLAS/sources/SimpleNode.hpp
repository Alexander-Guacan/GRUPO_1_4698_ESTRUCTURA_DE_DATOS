#ifndef SIMPLE_NODE_HPP
#define SIMPLE_NODE_HPP

template <typename T>
class SimpleNode {
    private:
        T *data{nullptr};
        SimpleNode<T> *nextNode{nullptr};

    public:
        SimpleNode(T *initialData);
        T *getData();
        SimpleNode<T> *getNextNode();
        void setData(T *newNode);
        void setNextNode(SimpleNode<T> *newNextNode);
        ~SimpleNode();
};

template <typename T>
SimpleNode<T>::SimpleNode(T *initialData) {
    this->data = initialData;
}

template <typename T>
T *SimpleNode<T>::getData() {
    return this->data;
}

template <typename T>
SimpleNode<T> *SimpleNode<T>::getNextNode() {
    return this->nextNode;
}

template <typename T>
void SimpleNode<T>::setData(T *newData) {
    this->data = newData;
}

template <typename T>
void SimpleNode<T>::setNextNode(SimpleNode<T> *newNextNode) {
    this->nextNode = newNextNode;
}

template <typename T>
SimpleNode<T>::~SimpleNode() {
    this->data = nullptr;
    this->nextNode = nullptr;
}

#endif