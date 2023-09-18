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


void inOrder(TreeNode *root, vector<int> &temp){
    if (root == NULL) return ;
    inOrder(root->left, temp);
    temp.push_back(root->data);
    inOrder(root->right, temp);
}


vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> temp;
    inOrder(root, temp);
    return temp;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    return 0;
}