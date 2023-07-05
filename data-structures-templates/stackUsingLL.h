#include <iostream>
using namespace std;


template <typename T>
class Node {
    public:

        T data;
        Node<T>* next;

        Node (T data) {
            this->data = data;
            next = NULL;
        }
};


// stack using LL is stores as head -> node -> node -> node ->....-> null
template <typename T>
class Stack {
    Node<T>* head;
    int count; //num of elements present in stack

    public:

    Stack() {
        head = NULL;
        count = 0;
    }

    int size() {
        return this->count;
    }

    bool empty() {
        return this->count == 0;
    }

    void push(T element) {
        Node<T>* newNode = new Node<T>(element);
        newNode -> next = head;
        head = newNode;
        count++;
    }

    T pop() {
        if (head == NULL) {
            cout << "Stack is Empty" << endl;
            return 0;
        }
        T ans = head -> data;
        Node<T>* tmp = head;
        head = head -> next;
        count--;

        delete tmp;

        return ans;
    }

    T top() {
        if (head == NULL) {
            cout << "Stack is empty" << endl;
            return 0;
        }
        return head -> data;
    }
};
