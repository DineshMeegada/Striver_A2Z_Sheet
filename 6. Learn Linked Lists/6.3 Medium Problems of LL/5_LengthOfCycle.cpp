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
    Node* node1 = new Node(arr[1]);
    head->next = node1;
    Node* tail = node1;

    for (int i=2; i<arr.size(); i++) {
        insertAtEnd(arr[i], tail);
    }
    tail->next = node1;

    return head;
}

int lengthOfLoop(Node *head) {
    // Write your code here
    if (head==NULL || head->next==NULL) return 0;
    Node* slow = head;
    Node* fast = head;

    while (fast!=NULL && fast->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow==fast) {
            int cnt = 1;
            Node* temp = slow->next;
            while(temp != slow){
                temp = temp->next;
                cnt++;
                if (temp== slow) break;
            }
            return cnt;
        }
    }
    return 0;
}


void displayLL(Node* head) {
    int cnt = 0;
    while (head != nullptr || cnt<2) {
        if (head->data == 29) cnt++;
        cout << head->data << " " ;
        head = head->next;
    }
    cout << endl;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    Node* head = makeLL(arr);
    // displayLL(head);

    int len = lengthOfLoop(head);
    cout << len;
    
    return 0;
}