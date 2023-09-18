#include <bits/stdc++.h>
using namespace std;


// Following is Binary Tree Node structure:
class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};


void preOrder(TreeNode *root, vector<int> &temp){
    if (root == NULL) return ;
    temp.push_back(root->data);
    preOrder(root->left, temp);
    preOrder(root->right, temp);
}

void postOrder(TreeNode *root, vector<int> &temp){
    if (root == NULL) return ;
    postOrder(root->left, temp);
    postOrder(root->right, temp);
    temp.push_back(root->data);
}

void inOrder(TreeNode *root, vector<int> &temp){
    if (root == NULL) return ;
    inOrder(root->left, temp);
    temp.push_back(root->data);
    inOrder(root->right, temp);
}

vector<vector<int>> getTreeTraversal(TreeNode *root){
    vector<int> pre, post, inOrd;
    preOrder(root, pre);
    postOrder(root, post);
    inOrder(root, inOrd);

    return {inOrd, pre, post};
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    


    
    return 0;
}