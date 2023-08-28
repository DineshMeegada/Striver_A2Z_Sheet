#include <bits/stdc++.h>
using namespace std;

class Queue {
    private:
        int front, rear;
        int n;
        vector<int> arr;
    public:
        Queue(int size){
            front = 0;
            rear = 0;
            n = size;
            arr.resize(100001);
        }

        void push(int x) {
            if (rear-front == n) return ;
            arr[rear%n] = x;
            rear++;
        }

        int top() {
            if (rear == front) return -1;
            return arr[front%n];
        }

        void pop() {
            if (rear == front) return ;
            arr[front%n] = -1;
            front++;
        }

        void print() {
            for (int i=front; i<rear; i++) {
                cout << arr[i] << ' ';
            }
        }
};

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Queue myQueue(5);

    myQueue.push(3);
    myQueue.push(4);
    myQueue.push(9);
    myQueue.push(1);
    
    cout << myQueue.top() << endl;

    myQueue.pop();
    myQueue.push(1);

    myQueue.print();
    
    return 0;
}