#include <bits/stdc++.h>
using namespace std;

class Node {
    public :
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
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

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    Node* head = constructLL(arr);
    printLL(head);

    
    return 0;
}