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

Node* sortLL(Node* head){
    if (head==NULL || head->next==NULL) return head;

    Node* zeroH = new Node(-1);
    Node* oneH = new Node(-1);
    Node* twoH = new Node(-1);

    Node *zero = zeroH, *one = oneH, *two = twoH;
    Node *curr = head;

    while(curr!=NULL) {
        if (curr->data == 0) {
            zero->next = curr;
            zero = curr;
        } else if (curr->data == 1) {
            one->next = curr;
            one = curr;
        } else {
            two->next = curr;
            two = curr;
        }
        curr = curr->next;
    }

    zero->next = oneH->next ? oneH->next : twoH->next;
    one->next = twoH->next;
    two->next = NULL;

    head = zeroH->next;

    delete zeroH;
    delete oneH;
    delete twoH;

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

    Node* sortedH = sortLL(head);
    displayLL(sortedH);


    
    return 0;
}