#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int data): data(data), next(nullptr) {}
};

void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}

Node* constructLL(vector<int>& arr) {
    // Write your code here
    if (arr.size() == 0) return nullptr;

    Node* head = new Node(arr[0]);
    Node* curr = head;

    for (int i=1; i<arr.size(); i++) {
        insertAtTail(curr, arr[i]);
    }

    return head;
}

void deleteNode(Node* head, int position){
    if (head == nullptr) return;
    Node* prev = nullptr;
    Node* curr = head;

    while (curr!=nullptr && --position) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr) return;

    prev->next = curr->next;
    delete curr;
}

void printLL (Node* head){
    while (head!=nullptr){
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
    
    Node* head = constructLL(arr);
    printLL(head);

    deleteNode(head, 3);
    printLL(head);


    
    return 0;
}