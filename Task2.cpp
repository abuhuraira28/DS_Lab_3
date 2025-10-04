#include <iostream>
using namespace std;

#define MAX_SIZE 5

// Node structure for stack (Linked List)
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Stack implementation using Linked List
class StackLL {
private:
    Node* top; // Pointer to the top node
    int size;  // Track number of elements
    int capacity; // Maximum size (for demo)

public:
    // Constructor
    StackLL(int cap = MAX_SIZE) : top(nullptr), size(0), capacity(cap) {
        cout << "Stack (Linked List) created with capacity = " << capacity << endl;
    }

    // Method 1: PUSH (Insert at the top)
    void push(int value) {
        if (size == capacity) {
            cout << "STACK OVERFLOW (Stack is FULL)!" << endl;
            return;
        }
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        size++;
        cout << "Pushed: " << value << endl;
    }

    // Method 2: POP (Removing the top element)
    int pop() {
        if (isEmpty()) {
            cout << "STACK UNDERFLOW (Stack is empty)!" << endl;
            return -1;
        }
        Node* temp = top;
        int poppedValue = temp->data;
        top = top->next;
        delete temp;
        size--;
        return poppedValue;
    }

    // Method 3: PEEK (View the top element without removing it)
    int peek() const {
        if (isEmpty()) {
            cout << "STACK EMPTY!" << endl;
            return -1;
        }
        return top->data;
    }

    // Utility to check if stack is empty
    bool isEmpty() const {
        return top == nullptr;
    }

    // Utility to display the stack
    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node* curr = top;
        cout << "Stack elements (Top -> Bottom): ";
        while (curr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    cout << "---- Task 2 Demonstration ----" << endl;
    StackLL stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    stack.push(60);  // Trigger Overflow

    stack.display();

    cout << "Top element (peek): " << stack.peek() << endl;
    cout << "Popped value: " << stack.pop() << endl;
    stack.display();

    return 0;
}
