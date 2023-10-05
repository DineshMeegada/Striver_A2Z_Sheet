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

TreeNode* findLastRight(TreeNode *root) {
    if (root->right == NULL) return root;
    return findLastRight(root->right);
}

TreeNode* helper(TreeNode *root) {
    if (root->left == NULL) return root->right;
    if (root->right == NULL) return root->left;

    TreeNode *rightChild = root->right;
    TreeNode *lastRight = findLastRight(root->left);
    lastRight->right = rightChild;

    return root->left;
}


TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return root;

    TreeNode *curr = root;
    if(curr->data == key) return helper(curr);
    while (curr) {
        if (curr->data > key) {
            if (curr->left && curr->left->data == key) {
                curr->left = helper(curr->left);
                break;
            }
            curr = curr->left;
        }else {
            if (curr->right && curr->right->data == key) {
                curr->right = helper(curr->right);
                break;
            }
            curr = curr->right;
        }
    }

    return root;
}

int main() {
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    
    
    return 0;
}