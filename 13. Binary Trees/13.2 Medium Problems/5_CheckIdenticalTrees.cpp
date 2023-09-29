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



bool identicalTrees(TreeNode* root1, TreeNode* root2) {
    if (!root1 || !root2) return root1==root2;
    if (root1->data != root2->data) return false;
    
    bool left = identicalTrees(root1->left, root2->left);
    bool right = identicalTrees(root1->right, root2->right);
    
    return left && right;
}


int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<int> arr1(n), arr2(n);
    for (int i=0; i<n; i++) cin >> arr1[i] ;
    for (int i=0; i<n; i++) cin >> arr2[i] ;
    
    TreeNode *root1 = createTree(arr1);
    TreeNode *root2 = createTree(arr2);
    cout << identicalTrees(root1, root2);
    
    
    return 0;
}