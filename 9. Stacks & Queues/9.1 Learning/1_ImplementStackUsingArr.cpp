#include <bits/stdc++.h>
using namespace std;

// Stack class.
class Stack {

private:
    int *arr;
    int top1;
    int size;
    
public:
    
    Stack(int capacity) {
        // Write your code here.
        size = capacity;
        top1 = -1;
        arr = new int[capacity];
    }

    void push(int num) {
        // Write your code here.
        if (!isFull()) arr[++top1] = num;
    }

    int pop() {
        // Write your code here.
        if (isEmpty()) return -1;
        top1--;
        return arr[top1+1];
    }
    
    int top() {
        // Write your code here.
        if (isEmpty()) return -1;
        return arr[top1];
    }
    
    int isEmpty() {
        // Write your code here.
        return (top1==-1) ? 1 : 0;
    }
    
    int isFull() {
        // Write your code here.
        return (top1+1 == size) ? 1 : 0;
    }
    
};


int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    Stack myStack(5);

    myStack.push(3);
    myStack.push(8);
    myStack.push(1);

    if (myStack.isEmpty()) cout << "Stack is Empty" << endl;
    else cout << "Stack is not empty" << endl;

    if (myStack.isFull()) cout << "Stack is Full" << endl;
    else cout << "Stack is not full" << endl;

    int popped1 = myStack.pop();
    cout << popped1 << endl;
    
    return 0;
}