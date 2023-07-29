#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

Node* insertAtFirst(Node* list, int newValue) {
    // Write your code here
    Node* temp = new Node(newValue);
    temp->next = list;
    list = temp;

    return list;
}

void printLL(Node* &head){
    Node* curr = head;
    while (curr!=NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    Node* curr = new Node(2);
    Node* head = insertAtFirst(curr, 5);

    printLL(head);
    
    return 0;
}