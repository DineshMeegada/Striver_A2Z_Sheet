#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
    Node (int data) : data(data), prev(nullptr), next(nullptr) {}
};

void insertAtEnd(Node* &tail, int d){
    Node* temp = new Node(d);
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
}

Node* constructDLL(vector<int>& arr) {
    // Write your code here
    if (arr.empty()) return nullptr;
    Node* node1 = new Node(arr[0]);
    Node* tail = node1;

    for (int i=1; i<arr.size(); i++) {
        insertAtEnd(tail, arr[i]);
    }

    return node1;
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
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;

    // for (int i=0; i<n; i++) cout << arr[i];
    
    Node* head = constructDLL(arr);
    printDLL(head);

    return 0;
}