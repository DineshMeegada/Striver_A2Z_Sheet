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

vector<vector<int>> levelOrderLC(TreeNode* root) {
    vector<vector<int>> ans;
    if (!root) return ans;
    
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()){
        int n = q.size();
        vector<int> temp;
        for (int i=0; i<n; i++) {
            TreeNode *curr = q.front();
            q.pop();

            temp.push_back(curr->data);
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        ans.push_back(temp);
    }

    return ans;

}

vector<int> levelOrderCN(TreeNode * root){
    vector<int> ans;
    if (!root) return ans;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()){
        TreeNode *curr = q.front();
        q.pop();

        ans.push_back(curr->data);
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
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

    vector<vector<int>> ans = levelOrderLC(root);
    for (auto temp: ans){
        for (auto it: temp) cout << it << ' ' ;
        cout << endl;
    }


    
    return 0;
}