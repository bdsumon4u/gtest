#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class List
{
public:
    int size;
    Node *head;
    Node *tail;

    List() {
        this->size = 0;
        this->head = NULL;
        this->tail = NULL;
    }

    void push(int data) {
        if (this->size == 0) {
            return unshift(data);
        }
        Node *node = new Node(data);
        this->tail->next = node;
        this->tail = node;
        this->size++;
    }

    void pop(int data) {

    }

    void shift(int data) {

    }

    void unshift(int data) {
        Node *node = new Node(data);
        node->next = this->head;
        this->head = node;
        if (this->size == 0) {
            this->tail = this->head;
        }
        this->size++;
    }

    void insert(int i, int data) {
        if (this->size == 0 || i == 0) {
            return this->unshift(data);
        } else if (i == this->size) {
            return this->push(data);
        }


    }

    void print() {
        Node *node = this->head;
        while (node) {
            cout << node->data << " ";
            node = node->next;
        }
        cout << endl;
    }
};

int main(int argc, char const *argv[])
{
    List *list = new List();
    cout << "Size: " << list->size << endl;
    list->unshift(5);
    list->push(3);
    list->push(2);
    cout << "Size: " << list->size << endl;
    list->insert(5);
    cout << "Print: ";
    list->print();

    return 0;
}
