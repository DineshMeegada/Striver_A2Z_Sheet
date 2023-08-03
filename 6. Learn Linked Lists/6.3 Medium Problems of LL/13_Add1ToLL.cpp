#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node (int val) : data(val), next(nullptr) {}
};

void insertAtEnd(int data, Node* &tail) {
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

Node* makeLL (vector<int> arr) {
    if (arr.empty()) return nullptr;

    Node* head = new Node(arr[0]);
    Node* tail = head;

    for (int i=1; i<arr.size(); i++) {
        insertAtEnd(arr[i], tail);
    }

    return head;
}

void displayLL(Node* head) {
    while (head != nullptr) {
        cout << head->data << ' ' ;
        head = head->next;
    }
    cout << endl;

}

void reverse(Node* &head){
    Node* curr = head, *prev = NULL;
    while (curr!=NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}

Node* addOneToLL(Node* head) {
    reverse(head);

    Node *curr = head;
    int quot = 1;
    while(curr != NULL) {
        int sum = curr->data + quot;
        int rem = sum%10;
        quot = sum/10;
        curr->data = rem;
        curr = curr->next;
    }

    reverse(head);
    if (quot != 0) {
        Node *temp = new Node(quot);
        temp->next = head;
        head = temp;
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
    
    Node* head = makeLL(arr);
    displayLL(head);

    Node* addedH = addOneToLL(head);
    displayLL(addedH);

    
    return 0;
}