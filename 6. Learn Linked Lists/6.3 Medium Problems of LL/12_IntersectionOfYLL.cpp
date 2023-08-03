#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

void insertNode(Node* &head, int val) {
    Node* newNode = new Node(val);
    
    if(head == NULL) {
        head = newNode;
        return;
    }
    
    Node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    
    temp->next = newNode;
    return;
}

Node* intersectionPresent(Node* head1, Node* head2) {
    Node *a = head1, *b = head2;

    while (a != b) {
        a = a==NULL ? head2 : a->next;
        b = b==NULL ? head1 : b->next;
    }

    return a;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    Node* head = NULL;
    insertNode(head,1);
    insertNode(head,3);
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,4);
    Node* head1 = head;
    head = head->next->next->next;
    Node* headSec = NULL;
    insertNode(headSec,3);
    Node* head2 = headSec;
    headSec->next = head;
    
    Node* interNode = intersectionPresent(head1, head2);
    cout << interNode->data;
    
    return 0;
}