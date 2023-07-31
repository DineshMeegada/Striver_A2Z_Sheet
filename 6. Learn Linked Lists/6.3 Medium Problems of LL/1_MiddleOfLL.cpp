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

int middleOfLL(Node* head){
    Node* slow = head;
    Node* fast = head;

    while (fast!=nullptr && fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    Node* head = makeLL(arr);

    int mid = middleOfLL(head);
    cout << mid;
    
    return 0;
}