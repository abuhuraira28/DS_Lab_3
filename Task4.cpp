#include <iostream>
using namespace std;

#define MAX_SIZE 5 // Required for StackArray

// StackArray Definition (Minimal for Context) --
class StackArray {
private:
    int data[MAX_SIZE];
    int top;
public:
    StackArray() {
        top = -1;
    }
    void push(int val) {
        if (top == MAX_SIZE - 1) {
            cout << "StackArray Overflow!" << endl;
            return;
        }
        data[++top] = val;
    }
    int pop() {
        if (top < 0) {
            cout << "StackArray Underflow!" << endl;
            return -1;
        }
        return data[top--];
    }
    void print() const {
        cout << "Array Stack: [";
        for (int i = 0; i <= top; i++) {
            cout << data[i];
            if (i < top) cout << ", ";
        }
        cout << "]" << endl;
    }
};

// Node Definition --
class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// StackList Definition (Minimal for Context) --
class StackList {
private:
    Node* head;
public:
    StackList() : head(nullptr) {}
    ~StackList() {
        while (head != nullptr) {
            Node* current = head;
            head = head->next;
            delete current;
        }
    }
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    int pop() {
        if (head == nullptr) {
            cout << "List Stack Underflow!" << endl;
            return -1;
        }
        Node* current = head;
        int val = current->data;
        head = head->next;
        delete current;
        return val;
    }
    void print() const {
        cout << "List Stack: [";
        Node* current = head;
        while (current != nullptr) {
            cout << current->data;
            current = current->next;
            if (current != nullptr) cout << ", ";
        }
        cout << "]" << endl;
    }
};
// Demonstration function that uses the same interface for both implementations
void demonstrateADT(StackArray& arrayStack, StackList& listStack) {
    cout << "Pushing 10 and 20 into both implementations." << endl;

    // Use interface on Array Stack
    arrayStack.push(10);
    arrayStack.push(20);
    cout << "Array Stack Pop: " << arrayStack.pop() << endl; // Pops 20

    // Use interface on List Stack
    listStack.push(100);
    listStack.push(200);
    cout << "List Stack Pop: " << listStack.pop() << endl; // Pops 200

    arrayStack.print();
    listStack.print();
}

int main() {
    cout << "--- Task 4 Demonstration ---" << endl;
    StackArray stack1;
    StackList stack2;

    demonstrateADT(stack1, stack2);

    // Destructors handle cleanup.
    return 0;
}