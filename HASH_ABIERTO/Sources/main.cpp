template <typename T>
class Node {
    public:
        T element{};
        Node *nextNode{nullptr};

        Node(const T &initialElement) {
            this->element = initialElement;
        }

};

template <typename T>
class Hash {
    public:
        virtual void insert(const T &element) = 0;
};

class HashString : public Hash<int> {
    private:
        Node<int> *array[10]{};
    public:
        void insert(const int &element) {
            Node<int> *newNode = new Node<int>(element);
            array[4] = newNode;
        }
};

int main() {
    HashString hashTable;
    hashTable.insert(5);

    return 0;
}