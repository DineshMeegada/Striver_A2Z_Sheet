#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

void insertInDLL(int data, Node* &tail){
    Node* temp = new Node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

Node* makeDLL(vector<int> arr){
    if (arr.empty()) return nullptr;

    Node* head = new Node(arr[0]);
    Node* tail = head;
    for (int i=1; i<arr.size(); i++) {
        insertInDLL(arr[i], tail);
    }

    return head;
}

void reverseDLL (Node* &head) {
    Node* temp = NULL;
    Node* curr = head;
    while (curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    head = temp->prev;
}

// void reverse(Node* &head)
// {
//     Node*temp = NULL;
//     Node*curr = head;
   
//     /* swap next and prev for all nodes of
//     doubly linked list */
//     while (curr != NULL)
//     {
//         temp = curr->prev;
//         curr->prev = curr->next;
//         curr->next = temp;          
//         curr = curr->prev;
//     }
 
   
//     //Edge case if our linked list is empty Or list with only one node
//     if(temp != NULL )
//         head = temp->prev;
// }

void displayDLL (Node* head){
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    Node* head = makeDLL(arr);
    displayDLL(head);

    reverseDLL(head);
    displayDLL(head);
    
    return 0;
}