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

void reorder(TreeNode *root) {
    if (!root || (!root->left && !root->right)) return;

    int child = 0;
    if (root->left) child += root->left->data;
    if (root->right) child += root->right->data;

    if (child < root->data) {
        if (root->left) root->left->data = root->data;
        if (root->right) root->right->data = root->data;
    }

    reorder(root->left);
    reorder(root->right);

    if (root->data != root->left->data + root->right->data) 
        root->data = root->left->data + root->right->data;
}


int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    TreeNode *root = createTree(arr);
    reorder(root);
    
    
    
    return 0;
}