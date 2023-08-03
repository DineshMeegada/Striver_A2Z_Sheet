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

Node* midOfLL(Node* head){
    Node* slow = head;
    Node* fast = head->next;

    while(fast!=NULL && fast->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node* merge(Node* left, Node* right){
    Node* ans = new Node(-1);
    Node* temp = ans;

    while(left!=NULL && right!=NULL) {
        if (left->data < right->data) {
            temp->next = left;
            temp = left;
            left = left->next;
        } else {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while(left!=NULL) {
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while(right!=NULL){
        temp->next = right;
        temp = right;
        right = right->next;
    }

    return ans->next;
}

Node* mergeSort(Node* head){
    if (head == NULL || head->next == NULL) return head;

    Node* mid = midOfLL(head);

    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    Node* result = merge(left, right);
    return result;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    Node *head = makeLL(arr);
    displayLL(head);

    Node *sortedLL = mergeSort(head);
    displayLL(sortedLL);

    
    return 0;
}