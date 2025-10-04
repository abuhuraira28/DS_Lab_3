#include <iostream>
using namespace std;

// Implement a stack data structure using an array
#define MAX_SIZE 5 // Defines the maximum size of the stack

class Stack {
private:
    int arr[MAX_SIZE]; // Array to hold the stack elements
    int top;           // Index of the top element in the stack (-1 means stack is empty)

public:
    Stack() {
        top = -1; // Initialize stack as empty
    }

    // Method 1: Push (Adding an element to the stack)
    void push(int value) {
        if (top == MAX_SIZE - 1) {
            cout << "ERROR: STACK OVERFLOW! (Stack is full)." << endl;
        } else {
            arr[++top] = value; // Increment top and insert value
            cout << "Pushed: " << value << endl;
        }
    }

    // Method 2: Pop (Removing and returning the top element)
    int pop() {
        if (top == -1) { // Underflow (No elements in stack)
            cout << "ERROR: STACK UNDERFLOW! (Stack is empty)." << endl;
            return -1;
        } else {
            int data = arr[top--]; // Get value, then decrement top (LIFO)
            return data;
        }
    }

    // Method 3: Peek (Viewing the top element without removing it)
    int peek() {
        if (top == -1)
            return -1;
        return arr[top];
    }

    // Helper to print the stack state
    void printStack() {
        cout << "Stack: [";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << (i == top ? "" : ", ");
        }
        cout << "]" << endl;
    }
};

// MAIN DEMONSTRATION
int main() {
    cout << "--- Task 5: STACK ARRAY DEMO ---" << endl;
    Stack myStack; // Changed StackArray to Stack to match class name

    // Pushing elements up to the capacity (5 elements)
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    myStack.push(50);
    myStack.printStack(); // Changed print to printStack to match method name

    // Trigger Overflow error
    myStack.push(60);

    cout << "Peek (Top value): " << myStack.peek() << endl; // Should be 50
    cout << "Popped value: " << myStack.pop() << endl; // Should be 50
    myStack.printStack(); // Changed print to printStack

    // Empty the stack
    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop();

    // Trigger Underflow error
    myStack.pop();

    cout << "\n-- Demo Complete --" << endl;
    return 0;
}