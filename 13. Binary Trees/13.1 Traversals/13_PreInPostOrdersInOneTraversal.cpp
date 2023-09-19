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

vector<vector<int>> getTreeTraversal(TreeNode *root){
    vector<int> preOrd, inOrd, postOrd;
    stack<pair<TreeNode*, int>> st;
    st.push({root, 1});

    while (!st.empty()) {
        pair<TreeNode*, int> curr = st.top();
        
        if (curr.second == 1) {
            preOrd.push_back(curr.first->data);
            st.top().second++;
            if (curr.first->left) st.push({curr.first->left, 1});
        } else if (curr.second == 2) {
            inOrd.push_back(curr.first->data);
            st.top().second++;
            if (curr.first->right) st.push({curr.first->right, 1});
        } else {
            postOrd.push_back(curr.first->data);
            st.pop();
        }
    }

    return {preOrd, inOrd, postOrd};
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    TreeNode *root = createTree(arr);
    vector<vector<int>> res = getTreeTraversal(root);
    for (auto ans: res) {
        for (auto it: ans) cout << it << ' ' ;
        cout << endl;
    }
    
    
    
    return 0;
}