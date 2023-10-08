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



class BSTIterator {
public:
    stack<TreeNode*> st;

    BSTIterator(TreeNode* root) {
        while (root) {
            st.push(root);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode *curr = st.top();
        st.pop();
        TreeNode *temp = curr->right;

        while (temp) {
            st.push(temp);
            temp = temp->left;
        }

        return curr->data;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};


int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    
    
    return 0;
}