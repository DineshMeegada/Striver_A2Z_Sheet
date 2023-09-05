// Least Recently Used

#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node *next;
        Node *prev;
        Node (int _key, int _val) {
            key = _key;
            val = _val;
        }
    };

    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    int cap;
    unordered_map<int, Node*> m;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node *curr){
        Node *temp = head->next;
        head->next = curr;
        curr->prev = head;
        curr->next = temp;
        temp->prev = curr;
    }

    void deleteNode(Node *node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = NULL;
        node->prev = NULL;
        delete node;
    }
    
    int get(int _key) {
        if (m.find(_key) != m.end()) {
            Node *resNode = m[_key];
            int res = resNode->val;

            m.erase(_key);
            deleteNode(resNode);
            addNode(new Node(_key, res));

            m[_key] = head->next;
            return res;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if (m.find(key) != m.end()){
            Node *nodeAddress = m[key];
            m.erase(key);
            deleteNode(nodeAddress);
        }

        if (m.size() == cap) {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new Node(key, value));
        m[key] = head->next;
    }
};