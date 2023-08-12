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

Node *midPoint(Node *head) {
    Node *slow = head, *fast = head->next;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node *reverse(Node *head){
    Node *pre = head, *curr = head->next, *next = NULL;

    while (curr) {
        Node *fast = curr->next;
        curr->next = next;
        if (fast) pre->next = fast;
        next = curr;
        curr = fast;
    }

    return head;
}

Node *merge(Node *head1, Node *head2) {
    Node *resH = new Node (0);
    Node *res = resH;

    while (head1){
        res->next = head1;
        head1 = head1->next;
        res = res->next;
        res->next = head2;
        head2 = head2 ? head2->next : NULL;
        res = res->next;
    }

    return resH->next;
}

Node *reorderList(Node *head){
    if (!head) return head;

    Node *mid = midPoint(head);

    Node *midHead = reverse(mid);
    Node *secHalf = midHead->next;
    midHead->next = NULL;

    Node *result = merge(head, secHalf);
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

    Node *head1 = reorderList(head);
    displayLL(head1);
    
    return 0;
}