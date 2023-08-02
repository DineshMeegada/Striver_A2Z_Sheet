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

Node* midNode (Node* head) {
    Node* slow = head;
    Node* fast = head;

    while(fast->next!=NULL && fast->next->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

void reverse(Node* &head){
    Node* prev = NULL;
    Node* curr = head->next;
    while (curr!=NULL){
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head->next = prev;
}


bool isPalindrome(Node* &head) {
    Node* mid = midNode(head);
    reverse(mid);

    Node* start = head;
    mid = mid->next;
    while (mid != NULL){
        if(start->data != mid->data) return false;
        start = start->next;
        mid = mid->next;
    }

    return true;
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

    bool isPal = isPalindrome(head);
    cout << isPal;
    
    return 0;
}