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

Node* startPoint(Node* head){
    if (head==nullptr || head->next==nullptr) return nullptr;
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            Node* entry = head;
            while (entry != slow) {
                slow = slow->next;
                entry = entry->next;
            }
            return entry;
        }
    }
    return nullptr;
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

    Node* start = startPoint(head);
    cout << start << " " << start->data;
    
    return 0;
}