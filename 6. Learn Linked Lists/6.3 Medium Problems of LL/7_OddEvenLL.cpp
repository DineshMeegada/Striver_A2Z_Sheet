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

Node* oddEvenList(Node* head) {
    if (head==NULL || head->next==NULL || head->next->next==NULL) return head;

    Node *even = head->next, *odd = head, *evenH = head->next;
    while (odd->next && even->next) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenH;
    return head;
}


Node* segregateEvenOdd(Node* head)
{
    // Write your code here
    
    Node *even = NULL, *odd = NULL, *evenH = NULL, *oddH = NULL;
    Node* curr = head;

    while(curr != NULL) {
        int val = curr->data;
        cout << val << endl;
        if (val%2 == 0){
          if (even == NULL) {
            even = curr;
            evenH = curr;
          } else {
            even->next = curr;
            even = curr;
          }
        } else {
            if (odd == NULL) {
                odd = curr;
                oddH = curr;
            } else {
                odd->next = curr;
                odd = curr;
            }
        }
        curr = curr->next;
    }
    odd->next = NULL;
    even->next = oddH;
    return evenH;

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

    Node *head1 = segregateEvenOdd(head);
    displayLL(head1);
    
    return 0;
}