#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int data) : data(data), prev(nullptr), next(nullptr) {}
};

void insertAtEnd(Node* &head, int d){

    Node* temp = new Node(d);

    if (head == nullptr) {
        Node* temp = new Node(d);
        head = temp;
        return ;
    }
    Node* curr = head;
    while (curr->next != nullptr){
        curr = curr->next;
    }
    temp->prev = curr;
    curr->next = temp;

}

Node * insertAtTail(Node *head, int k) {
    // Write your code here
    insertAtEnd(head, k);
    return head;
}

void printDLL(Node* head){
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next; // Move to the next node
    }
    cout << endl;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    Node* head = new Node(7);
    insertAtTail(head, 9);

    printDLL(head);

    
    return 0;
}