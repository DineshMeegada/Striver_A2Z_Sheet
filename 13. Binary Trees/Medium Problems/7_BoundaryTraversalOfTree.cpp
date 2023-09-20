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

bool isLeaf (TreeNode *node) {
    return (!node->left && !node->right);
}

void leftNodes(TreeNode *root, vector<int> &res) {
    while (root) {
        if (!isLeaf(root)) res.push_back(root->data);
        if (root->left) root = root->left;
        else root = root->right;
    }
}

void leafNodes(TreeNode *root, vector<int> &res) {
    if (isLeaf(root)) {
        res.push_back(root->data);
        return ;
    }

    if (root->left) leafNodes(root->left, res);
    if (root->right) leafNodes(root->right, res);
}

void rightNodes(TreeNode *root, vector<int> &res) {
    vector<int> temp;
    while (root){
        if (!isLeaf(root)) temp.push_back(root->data);
        if (root->right) root = (root->right);
        else root = root->left;
    }

    for (int i=temp.size()-1; i>=0; i--) {
        res.push_back(temp[i]);
    }
}

vector<int> traverseBoundary(TreeNode *root) {
    vector<int> res;
	if (!root) return res;

    res.push_back(root->data);
    leftNodes(root->left, res);
    leafNodes(root, res);
    rightNodes(root->right, res);

    return res;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    TreeNode *root = createTree(arr);
    vector<int> ans = traverseBoundary(root);
    for (auto it: ans) cout << it << ' ';
    
    
    
    return 0;
}