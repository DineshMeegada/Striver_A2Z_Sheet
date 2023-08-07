/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *child;
    Node (int val) : data(val), next(nullptr), child(nullptr) {}
};

Node *merge(Node *head1, Node *head2){
    Node *res = new Node(0);
    Node *curr = res;
    
    while(head1 && head2){
        if(head1->data < head2->data) {
            curr->child = head1;
            curr = head1;
            head1 = head1->child;
        } else {
            curr->child = head2;
            curr = head2;
            head2 = head2->child;
        }
    }
    
    if(head1) curr->child = head1;
    else curr->child = head2;
    
    return res->child;
}


Node* flattenLinkedList(Node* head)
{
    if (head == NULL || head->next == NULL) return head;
    
    Node *right = flattenLinkedList(head->next);
    head->next = NULL;
    
    return merge(head, right);
   
}



 
int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    return 0;
}

