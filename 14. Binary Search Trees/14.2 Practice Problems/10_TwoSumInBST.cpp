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

void inorder(TreeNode *root, vector<int> &arr) {
    if (!root) return ;

    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

bool pairSumBst(TreeNode *root, int k){
    vector<int> arr;
    inorder(root, arr);

    int l=0, r=arr.size()-1;
    while (l<r) {
        if (arr[l] + arr[r] == k) return true;
        if (arr[l] + arr[r] > k) r--;
        else l++;
    } 

    return false;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    
    
    return 0;
}