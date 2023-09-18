#include <bits/stdc++.h>
using namespace std;

struct Tree {
    int data;
    Tree* left;
    Tree* right;
    Tree(int val) : data(val), left(nullptr), right(nullptr) {}
};

void printTree(Tree *root) {
    if (root == nullptr) return;

    cout << root->data << ' ' ;
    printTree(root->left);
    printTree(root->right);
}

Tree* formTree(vector<int> &arr, int n, int i) {
    Tree *curr = new Tree(arr[i]);

    int l = 2*i+1, r = 2*i+2;
    if (l<n) curr->left = formTree(arr, n, l);
    if (r<n) curr->right = formTree(arr, n, r);

    return curr;
}

Tree* createTree(vector<int>&arr){
    return formTree(arr, arr.size(), 0);
}

Tree* constructTree(vector<int> &arr){
    int n = arr.size();
    if (n == 0) return nullptr;

    Tree *root = new Tree(arr[0]);
    queue<Tree*> q;
    q.push(root); 

    int i = 1;
    while (i < n) {
        Tree *curr = q.front();
        q.pop();

        if (i<n) {
            curr->left = new Tree(arr[i++]);
            q.push(curr->left);
        }

        if (i<n) {
            curr->right = new Tree(arr[i++]);
            q.push(curr->right);
        }
    }

    return root;    
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    Tree *root = constructTree(arr);
    printTree(root);
    
    return 0;
}