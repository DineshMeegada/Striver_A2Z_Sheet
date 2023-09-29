#include<bits/stdc++.h>
using namespace std;

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

vector<int> bottomView(TreeNode<int> * root){
    map<int, int> mp;
    queue<pair<TreeNode<int>*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        mp[curr.second] = curr.first->data;

        if (curr.first->left) q.push({curr.first->left, curr.second-1});
        if (curr.first->right) q.push({curr.first->right, curr.second+1});
    }

    vector<int> ans;
    for (auto it: mp){
        ans.push_back(it.second);
    }

    return ans;
}