#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

TreeNode* formTree(vector<int> &arr, int n, int i){
    TreeNode* curr = new TreeNode(arr[i]);

    int l = 2*i+1, r = 2*i+2;
    if (l<n) curr->left = formTree(arr, n, l);
    if (r<n) curr->right = formTree(arr, n, r);

    return curr;
}

TreeNode* createTree(vector<int> &arr){
    if(arr.empty()) return nullptr;
    return formTree(arr, arr.size(), 0);
}

TreeNode* searchBST(TreeNode* root, int x) {
    while (root){
        if (x == root->data) return root;
        if (x > root->data) root = root->right;
        else root = root->left;
    }

    return NULL;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    
    
    return 0;
}