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
        cout << head->data << " " ;
        head = head->next;
    }
    cout << endl;

}

Node* removeKthNode (Node *&head, int k) {
    Node* fast = head;
    for (int i=0; i<k; i++) fast = fast->next;

    // if (!fast) return head->next;
    Node *slow = head;
    while (fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;

    return head;

}

Node* removeNthNode(Node* &head, int n){
    Node *fast = head, *slow = head;
    for (int i = 0; i < n; i++) fast = fast->next;
    if (!fast) return head->next;
    while (fast->next) fast = fast->next, slow = slow->next;
    cout << slow->data << endl;
    slow->next = slow->next->next;
    return head;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;

    Node* head = makeLL(arr);
    displayLL(head);

    Node* head1 = removeKthNode(head, k);
    displayLL(head1);
    
    return 0;
}