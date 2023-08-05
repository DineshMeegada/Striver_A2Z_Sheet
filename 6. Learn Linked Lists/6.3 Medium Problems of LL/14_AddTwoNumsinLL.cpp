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

Node* addTwoNumbers(Node *l1, Node *l2) {
    Node *curr1 = l1, *curr2 = l2;
    Node *resH = new Node(-1);
    Node *res = resH;
    int quot = 0;

    while (curr1!=NULL && curr2!=NULL) {
        int sum = curr1->data + curr2->data + quot;
        int rem = sum % 10;
        quot = sum/10;
        
        Node *temp = new Node(rem);
        res->next = temp;
        res = temp;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    while (curr1!=NULL) {
        int sum = curr1->data + quot;
        int rem = sum % 10;
        quot = sum/10;

        Node *temp = new Node(rem);
        res->next = temp;
        res = temp;
        curr1 = curr1->next;
    }

    while (curr2!=NULL) {
        int sum = curr2->data + quot;
        int rem = sum % 10;
        quot = sum/10;

        Node *temp = new Node(rem);
        res->next = temp;
        res = temp;
        curr2 = curr2->next;
    }

    if (quot != 0) {
        Node *temp = new Node(quot);
        res->next = temp;
    }

    resH = resH->next;
    return resH;
}

Node *addTwoNums(Node *l1, Node *l2) {
    Node *resH = new Node(-1);
    Node *res = resH;
    int quot = 0;

    while (l1!=NULL || l2!=NULL || quot!=0) {
        int x = l1 ? l1->data : 0;
        int y = l2 ? l2->data : 0;
        int sum = x + y + quot;
        quot = sum / 10;
        res->next = new Node(sum%10);
        res = res->next;
        l1 = l1 ? l1->next : nullptr;
        l2 = l2 ? l2->next : nullptr;
    }

    return resH->next;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<int> arr1(n);
    for (int i=0; i<n; i++) cin >> arr1[i] ;

    int m;
    cin >> m;
    
    vector<int> arr2(m);
    for (int i=0; i<m; i++) cin >> arr2[i] ;
    
    Node *head1 = makeLL(arr1);
    displayLL(head1);

    Node *head2 = makeLL(arr2);
    displayLL(head2);

    cout << endl;
    Node *head = addTwoNums(head1, head2);
    displayLL(head);
    
    
    return 0;
}