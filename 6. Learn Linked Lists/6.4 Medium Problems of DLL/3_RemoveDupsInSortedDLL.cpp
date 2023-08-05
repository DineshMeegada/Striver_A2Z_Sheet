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

Node *makeDLL(vector<int> arr){
    if (arr.empty()) return nullptr;

    Node* head = new Node(arr[0]);
    for (int i=1; i<arr.size(); i++) {
        insertAtEnd(head, arr[i]);
    }

    return head;
}

void printDLL(Node* head){
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next; // Move to the next node
    }
    cout << endl;
}

Node * removeDuplicates(Node *head){
    Node *left = head, *right = head;
    while (left && left->next) {
        while (right && left->data == right->data) right = right->next;
        left->next = right;
        if(right) right->prev = left;
        
        left = right;
    }

    return head;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    Node *Duphead = makeDLL(arr);
    printDLL(Duphead);

    Node *head = removeDuplicates(Duphead);
    printDLL(head);
    
    return 0;
}