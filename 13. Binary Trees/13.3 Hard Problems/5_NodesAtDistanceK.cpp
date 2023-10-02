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

unordered_map<TreeNode*, TreeNode*> getParents(TreeNode* root){
    unordered_map<TreeNode*, TreeNode*> parents;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()){
        TreeNode* curr = q.front();
        q.pop();

        if (curr->left){
            parents[curr->left] = curr;
            q.push(curr->left);
        }

        if (curr->right){
            parents[curr->right] = curr;
            q.push(curr->right);
        }
    }

    return parents;
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, TreeNode*> parents = getParents(root);

    unordered_map<TreeNode*, bool> visited;
    visited[target] = true;

    queue<TreeNode*> currQ;
    currQ.push(target);

    while (!currQ.empty()){
        int n = currQ.size();
        if (!k--) break;

        for (int i=0; i<n; i++) {
            TreeNode* curr = currQ.front();
            currQ.pop();

            if (curr->left && !visited[curr->left]){
                currQ.push(curr->left);
                visited[curr->left] = true;
            }

            if (curr->right && !visited[curr->right]){
                currQ.push(curr->right);
                visited[curr->right] = true;
            }

            if (parents[curr] && !visited[parents[curr]]){
                currQ.push(parents[curr]);
                visited[parents[curr]] = true;
            }
        }
    }

    vector<int> ans;
    while (!currQ.empty()){
        ans.push_back(currQ.front()->data);
        currQ.pop();
    }

    return ans;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    TreeNode* root = createTree(arr);
    vector<int> ans = distanceK(root, root->left, k);

    for (auto it: ans) cout << it << ' ' ;
    
    
    
    return 0;
}