/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *curr = head;
        while (curr) {
            Node *temp = new Node(curr->val);
            Node *nex = curr->next;
            curr->next = temp;
            temp->next = nex;
            curr = nex;
        }

        Node *itr = head;
        while (itr) {
            if (itr->random) {
                itr->next->random = itr->random->next;
            }

            itr = itr->next->next;
        }

        Node *resH = new Node(0);
        Node *res = resH;
        itr = head;
        while (itr) {
            Node *fast = itr->next->next;
            res->next = itr->next;
            itr->next = fast;
            itr = fast;
            res = res->next;
        }

        return resH->next;
    }
};