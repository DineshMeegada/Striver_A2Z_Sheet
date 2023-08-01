#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

bool hasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }

    return false;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    Node* head = new Node(2);
    Node* node1 = new Node(3);
    Node* node2 = new Node(4);
    Node* node3 = new Node(5);
    Node* node4 = new Node(7);
    
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    // node4->next = node1;

    bool isCyclic = hasCycle(head);
    cout << isCyclic ;

    
    return 0;
}