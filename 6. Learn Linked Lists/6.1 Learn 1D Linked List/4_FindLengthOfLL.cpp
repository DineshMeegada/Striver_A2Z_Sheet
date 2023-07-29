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

int lenOfLL(Node* head){
    int cnt = 0;
    while (head!=NULL) {
        cnt++;
        head = head->next;
    }
    return cnt;
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
    
    cout << "Length is " << lenOfLL(head);
    
    return 0;
}