#include <bits/stdc++.h>
using namespace std;

class Queue {
    // Define the data members(if any) here.
    stack<int> st1;
    stack<int> st2;
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        while (!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }

        st1.push(val);

        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
    }

    int deQueue() {
        // Implement the dequeue() function.
        if (st1.empty()) return -1;
        int ele = st1.top();
        st1.pop();
        return ele;
    }

    int peek() {
        // Implement the peek() function here.
        if(st1.empty()) return -1;
        return (st1.top());
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        return st1.empty();
    }
};

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    

    
    return 0;
}