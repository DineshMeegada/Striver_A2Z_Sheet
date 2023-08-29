#include <bits/stdc++.h>
using namespace std;


class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};



class Stack
{
    //Write your code here
    Node *top;

public:
    Stack()
    {
        //Write your code here
        top = NULL;
    }

    int getSize()
    {
        //Write your code here
        int cnt = 0;
        Node *temp = top;
        while (temp){
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    bool isEmpty()
    {
        //Write your code here
        return (top == NULL);
    }

    void push(int data)
    {
        //Write your code here
        Node *temp = new Node(data);
        temp->next = top;
        top = temp;
    }

    void pop()
    {
        //Write your code here
        if (top == NULL) return ;
        Node *prev = top;
        top = top->next;
        delete prev;
    }

    int getTop()
    {
        //Write your code here
        if (top == NULL) return -1;
        Node *head = top;
        int ans = head->data;
        return ans;
    }
};

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    return 0;
}