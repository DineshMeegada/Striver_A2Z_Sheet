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

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    if (!root) return ans;

    stack<TreeNode*> st;

    while (root || !st.empty()){
        if (root){
            st.push(root);
            root = root->left;
        }else {
            TreeNode* temp = st.top();
            st.pop();

            ans.push_back(temp->data);
            root = temp->right;
        }
    }

    return ans;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    TreeNode *root = createTree(arr);
    vector<int> inOrd = inorderTraversal(root);
    for (auto it: inOrd) cout << it << ' ';
    
    
    
    return 0;
}