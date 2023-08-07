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

int findLength(Node *head){
    int length = 0;
    while (head) {
        length++;
        head = head->next;
    }

    return length;
}

Node *rotateRight(Node *head, int k) {
    Node *fast = head;
    int len = findLength(head);
    int x = k%len;
    while (x--) fast = fast->next;

    Node *curr = head;
    while (fast->next) {
        fast = fast->next;
        curr = curr->next;
    }

    fast->next = head;
    Node *n = curr->next;
    curr->next = NULL;
    head = n;

    return head;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    Node *head = makeLL(arr);
    displayLL(head);

    Node *head1 = rotateRight(head, k);
    displayLL(head1);
    
    return 0;
}