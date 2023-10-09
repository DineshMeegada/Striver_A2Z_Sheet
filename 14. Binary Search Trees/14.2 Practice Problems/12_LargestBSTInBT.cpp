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



bool checkBST(vector<int> left, vector<int> right, TreeNode* root) {
    return left[1]<root->data && root->data<right[2];
}

// {size, largest, lowest}

vector<int> solve(TreeNode *root){
    if (!root) return {0, INT_MIN, INT_MAX};

    vector<int> left = solve(root->left);
    vector<int> right = solve(root->right);

    bool isBST = checkBST(left, right, root);

    if (isBST) return {left[0]+right[0]+1, max(right[1], root->data), min(left[2], root->data)};
    return {max(left[0], right[0]), INT_MAX, INT_MIN};

}

int largestBST(TreeNode * root){
    vector<int> temp = solve(root);

    return temp[0];
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    
    
    return 0;
}