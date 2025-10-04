#include <iostream>
using namespace std;

class Stack {
private:
    int size;
    int top;
    int* arr;
public:
    Stack(int size) {
        this->size = size;
        top = -1;
        arr = new int[size];
    }
    ~Stack() {
        delete[] arr;
    }
    bool isFull() {
        return top == size - 1;
    }
    bool isEmpty() {
        return top == -1;
    }
    void push(int value) {
        if (isFull()) {
            cout << "Stack is full!" << endl;
            return;
        }
        arr[++top] = value;
    }
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top--];
    }
};

int main() {
    Stack s(5); // Creating a stack of size 5
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.pop() << endl; // Should print 3
    cout << s.pop() << endl; // Should print 2
    cout << s.pop() << endl; // Should print 1
    cout << s.pop() << endl; // Should print -1 (stack empty)
    return 0;
}