#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int data): data(data), next(NULL) {}
};

void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}

Node* constructLL(vector<int>& arr) {
    // Write your code here
    if (arr.size() == 0) return NULL;

    Node* head = new Node(arr[0]);
    Node* curr = head;

    for (int i=1; i<arr.size(); i++) {
        insertAtTail(curr, arr[i]);
    }

    return head;
}

void printLL (Node* &head){
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " " ;
        temp = temp->next;
    }
}

int searchInLinkedList(Node* head, int k) {
    // Write your code here.
    while (head!=NULL){
        if (head->data == k) return 1;
        head = head->next;
    }
    return 0;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    Node* head = constructLL(arr);
    printLL(head);
    
    cout << searchInLinkedList(head, 5);
    
    return 0;
}