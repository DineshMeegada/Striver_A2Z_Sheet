#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int data) : data(data), prev(nullptr), next(nullptr) {}
};

void insertAtEnd(Node* &head, int d){

    Node* temp = new Node(d);

    if (head == nullptr) {
        Node* temp = new Node(d);
        head = temp;
        return ;
    }
    Node* curr = head;
    while (curr->next != nullptr){
        curr = curr->next;
    }
    temp->prev = curr;
    curr->next = temp;

}

Node *makeDLL(vector<int> arr){
    if (arr.empty()) return nullptr;

    Node* head = new Node(arr[0]);
    for (int i=1; i<arr.size(); i++) {
        insertAtEnd(head, arr[i]);
    }

    return head;
}

void printDLL(Node* head){
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next; // Move to the next node
    }
    cout << endl;
}

vector<pair<int, int>> findPairs(Node* head, int k){
    vector<pair<int, int>> pairs;

    Node *left = head, *right = head;
    while (right->next) right = right->next;

    while (left->data < right->data) {
        int sum = left->data + right->data;

        if (sum == k){
            pair<int, int> temp = {left->data, right->data};
            pairs.push_back(temp);
            left = left->next;
            right = right->prev;
        } else if (sum < k) left = left->next;
        else right = right->prev;
    }

    return pairs;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;

    int k;
    cin >> k;
    
    Node *head = makeDLL(arr);
    printDLL(head);

    vector<pair<int, int>> pairs = findPairs(head, k);
    for(auto it: pairs) cout << it.first << " " << it.second << endl;

    return 0;
}