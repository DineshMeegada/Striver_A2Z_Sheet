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


int maxSum (TreeNode* root, int &sum){
    if (!root) return 0;

    int lsum = max(0, maxSum(root->left, sum));
    int rsum = max(0, maxSum(root->right, sum));
    int currSum = lsum+rsum+root->data;

    sum = max(sum, currSum);
    return max(lsum, rsum) + root->data;
}

int maxPathSum(TreeNode* root) {
    int sum = INT_MIN;
    maxSum(root, sum);
    return sum;
}


int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    TreeNode *root = createTree(arr);
    cout << maxPathSum(root);
    
    
    return 0;
}