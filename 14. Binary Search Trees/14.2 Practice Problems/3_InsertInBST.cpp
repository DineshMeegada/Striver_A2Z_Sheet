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

TreeNode* insertIntoBST(TreeNode* root, int x) {
    TreeNode *node = new TreeNode (x);
    if (!root) return node;

    TreeNode *curr = root;
    while (curr) {
        if (curr->data > x){
            if (curr->left == NULL) {
                curr->left = node;
                return root;
            }
            curr = curr->left;
        }else {
            if (curr->right == NULL) {
                curr->right = node;
                return root;
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