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
    int len = 0;
    while(head) {
        len++;
        head = head->next;
    }
    return len;
}

Node *reverseKGroup(Node *head, int k) {
    if (head==NULL || head->next==NULL) return head;

    int length = findLength(head);

    Node *dum = new Node(0);
    dum->next = head;

    Node *pre = dum;
    Node *curr, *next;

    while(length >= k) {
        curr = pre->next;
        next = curr->next;

        for (int i=1; i<k; i++){
            curr->next = next->next;
            next->next = pre->next;
            pre->next = next;
            next = curr->next;
        } 

        pre = curr;
        length -= k;
    }

    return dum->next;

}

Node* reverseKNodes(Node* head,int k) {
    if(head == NULL||head->next == NULL) return head;
    
    int length = findLength(head);
    
    Node* dummyHead = new Node(0);
    dummyHead->next = head;
    
    Node* pre = dummyHead;
    Node* cur;
    Node* nex;
    
    while(length >= k) {
        cur = pre->next;
        nex = cur->next;
        for(int i=1;i<k;i++) {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
        length -= k;
    }
    return dummyHead->next;
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

    // cout << findLength(head);
    Node *head1 = reverseKNodes(head, k);
    displayLL(head1);
    
    return 0;
}