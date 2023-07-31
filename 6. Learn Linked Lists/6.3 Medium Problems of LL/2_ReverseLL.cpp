#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node (int val) : data(val), next(nullptr){}
};

void insertAtEnd(Node* &tail, int d) {
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

Node* makeLL(vector<int> arr) {
    Node* head = new Node(arr[0]);
    Node* tail = head;

    for (int i=1; i<arr.size(); i++) {
        insertAtEnd(tail, arr[i]);
    }

    return head;
}

void reverseLL(Node* &head) {
    Node* i=nullptr;
    Node* curr=head;
    Node* j=head->next;

    while(j != nullptr) {
        curr->next = i;
        i = curr;
        curr = j;
        j = j->next;
    }
    curr->next = i;

    head = curr;
}

void reverseLLOpt(Node* &head){
    Node* newHead = nullptr;
    while (head != nullptr) {
        Node* next = head->next;
        head->next = newHead;
        newHead = head;
        head = next;
    }
    head = newHead;
}

void printLL(Node* head) {
    while(head != nullptr) {
        cout << head->data << " " ;
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
    
    Node* head = makeLL(arr);
    printLL(head);

    reverseLLOpt(head);
    printLL(head);

    
    return 0;
}