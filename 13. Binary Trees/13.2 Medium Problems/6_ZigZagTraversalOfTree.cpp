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

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    queue<TreeNode*> q;
    q.push(root);

    int flag = 1;
    while (!q.empty()) {
        int n = q.size();
        vector<int> temp(n);
        for (int i=0; i<n; i++) {
            TreeNode *curr = q.front();
            q.pop();

            int ind = flag ? i : n-i-1;
            temp[ind] = curr->data;

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }

        res.push_back(temp);
        flag = 1 - flag;
    }

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
    vector<vector<int>> res = zigzagLevelOrder(root);
    for (auto ans: res) {
        for (auto it: ans) cout << it << ' ';
        cout << endl;
    }
    
    
    
    return 0;
}