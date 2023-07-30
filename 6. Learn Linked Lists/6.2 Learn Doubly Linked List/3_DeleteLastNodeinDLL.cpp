#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node (int val) : data(val), prev(nullptr), next(nullptr){}
};

void deleteLastNode(Node* &head){
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->prev->next = nullptr;
    delete temp;
}

void printDLL(Node* head){
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    Node* head = new Node(8);
    Node* node1 = new Node(3);
    Node* node2 = new Node(6);

    head->next = node1;
    node1->prev = head;
    node1->next = node2;
    node2->prev = node1;
    
    printDLL(head);

    deleteLastNode(head);
    printDLL(head);

    return 0;
}