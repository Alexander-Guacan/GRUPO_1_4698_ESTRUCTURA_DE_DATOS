#ifndef NODE_DOUBLE_HPP
#define NODE_DOUBLE_HPP

template <typename T>
class NodeDouble {
    T data;
    NodeDouble<T> *previousNode{nullptr};
    NodeDouble<T> *nextNode{nullptr};

    public:
        NodeDouble(T initialData);
        T getData();
        NodeDouble<T> *getPreviousNode();
        NodeDouble<T> *getNextNode();
        void setData(T newData);
        void setPreviousNode(NodeDouble<T> *newPreviousNode);
        void setNextNode(NodeDouble<T> *newNextNode);
};

template <typename T>
NodeDouble<T>::NodeDouble(T initialData) {
    this->data = initialData;
}

template <typename T>
T NodeDouble<T>::getData() {
    return this->data;
}

template <typename T>
NodeDouble<T> *NodeDouble<T>::getPreviousNode() {
    return this->previousNode;
}

template <typename T>
NodeDouble<T> *NodeDouble<T>::getNextNode() {
    return this->nextNode;
}

template <typename T>
void NodeDouble<T>::setData(T newData) {
    this->data = newData;
}

template <typename T>
void NodeDouble<T>::setPreviousNode(NodeDouble<T> *newPreviousNode) {
    this->previousNode = newPreviousNode;
}

template <typename T>
void NodeDouble<T>::setNextNode(NodeDouble<T> *newNextNode) {
    this->nextNode = newNextNode;
}

#endif