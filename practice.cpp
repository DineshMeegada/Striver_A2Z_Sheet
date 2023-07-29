#include <bits/stdc++.h>
using namespace std;

class Node  {
    public :
    int data;
    Node* next;
    
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

void insertAtHead(Node* &head, int d){
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail (Node* &tail, int d) {
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}

void insertAtMiddle (Node* &head, Node* &tail, int position, int d) {
    if (position == 1) {
        insertAtHead(head, d);
        return;
    }

    Node* nodeToInsert = new Node(d);
    Node* temp = head;

    while (--position > 1 && temp->next) {
        temp = temp -> next;
    }

    if (temp -> next == NULL) {
        insertAtTail(tail, d);
        return ;
    }

    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;

}

void deleteNode (Node* &head, int position) {
    Node* curr = head;

    if (position == 1) {
        head = curr->next;
        curr->next = NULL;
        return;
    }

    while (--position > 1){
        curr = curr -> next;
    }

    Node* temp = curr->next;
    curr->next = temp->next;
    temp->next = NULL;
}

void print (Node* &head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp -> data << " ";
        temp = temp->next;
    }
}

int main() {
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Node* node1 = new Node(4) ;

    Node* head = node1;
    Node* tail = node1;

    insertAtHead(head, 8);
    insertAtHead(head, 9);
    print(head);
    cout << endl;

    insertAtTail(tail, 13);
    insertAtTail(tail, 67);
    print(head);
    cout << endl;

    insertAtMiddle(head, tail, 9, 22);
    print(head);
    cout << endl;

    deleteNode(head, 1);
    print(head);
    cout << endl;

    cout << "head -> " << head->data << endl;
    cout << "tail -> " << tail->data << endl;
 
    

    return 0;
}