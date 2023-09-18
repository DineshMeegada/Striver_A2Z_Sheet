#include <bits/stdc++.h>
using namespace std;


// Following is the TreeNode class structure

template <typename T>
class TreeNode {
    public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void preOrd(TreeNode<int> *root, vector<int> &temp){
    if (root == NULL) return ;
    temp.push_back(root->data);
    preOrd(root->left, temp);
    preOrd(root->right, temp);
}

vector<int> preOrder(TreeNode<int> * root){
    vector<int> res;
    preOrd(root, res);
    return res;
}


int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    

    return 0;
}