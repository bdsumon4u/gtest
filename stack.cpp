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

class Stack
{
public:
    int size;
    Node *head;

    Stack() {
        this->size = 0;
        this->head = NULL;
    }

    bool isEmpty() {
        return this->size == 0;
    }

    void push(int data) {
        cout << "Pushing: " << data << endl;
        Node *node = new Node(data);
        node->next = this->head;
        this->head = node;
        this->size++;
    }

    int top() {
        if (this->isEmpty()) {
            cout << "UNDERFLOW" << endl;
            exit(1);
        }

        return this->head->data;
    }

    int pop() {
        int data = this->top();

        Node *node = this->head;
        this->head = node->next;
        delete node;
        this->size--;
        return data;
    }

    void print(bool pop = false) {
        Node *node = this->head;
        if (pop) {
            while (!this->isEmpty()) {
                cout << this->pop() << " ";
            }
        } else {
            while (node) {
                cout << node->data << " ";
                node = node->next;
            }
        }
        cout << endl << "Size: " << this->size << endl;
    }
};

void stackTest() {
    Stack *stack = new Stack();
    cout << "Size: " << stack->size << endl;
    stack->push(3);
    stack->push(2);
    stack->push(32);
    cout << "Pop: " << stack->pop() << endl;
    stack->push(12);
    stack->push(35);
    stack->push(42);
    cout << "Pop: " << stack->pop() << endl;
    cout << "Size: " << stack->size << endl;
    cout << "Print: ";
    stack->print(false);
}

int operate(int A, char op, int B) {
    switch (op) {
        case '+': return A + B;
        case '-': return A - B;
        case '*': return A * B;
        case '/': return A / B;
        default: return -1;
    }
}

// 5 6 7 + -
int postEv(string exp) {
    Stack *stack = new Stack();
    for (char ch : exp) {
        if (isdigit(ch)) {
            cout << (int)ch << endl;
            stack->push(ch - '0');
        } else {
            int B = stack->pop();
            int A = stack->pop();
            stack->push(operate(A, ch, B));
        }
    }
    return stack->top();
}

int main(int argc, char const *argv[])
{
    string postfix = "567+-";
    cout << postEv(postfix) << endl;

    return 0;
}
