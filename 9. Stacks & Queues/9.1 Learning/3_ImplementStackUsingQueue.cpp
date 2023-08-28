#include <bits/stdc++.h>
using namespace std;

class Stack {
	// Define the data members.
    queue<int> q;
   public:
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return q.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return q.empty();
    }

    void push(int element) {
        // Implement the push() function.
        q.push(element);
        for (int i=1; i<q.size(); i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        // Implement the pop() function.
        if (q.empty()) return -1;
        int ele = q.front();
        q.pop();
        return ele;
    }

    int top() {
        // Implement the top() function.
        if (q.empty()) return -1;
        return q.front();
    }
};

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    

    
    return 0;
}