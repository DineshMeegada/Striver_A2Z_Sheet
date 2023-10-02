#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode 
{
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) 
    {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};


unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> getParents(BinaryTreeNode<int>* root, BinaryTreeNode<int>* &target, int start){
    unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> parents;

    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while (!q.empty()){
        BinaryTreeNode<int>* curr = q.front();
        if (curr->data == start) target = curr;
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

int timeToBurnTree(BinaryTreeNode<int>* root, int start){
    BinaryTreeNode<int> *target = nullptr;
    unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> parents = getParents(root, target, start);


    unordered_map<BinaryTreeNode<int>*, bool> visited;
    visited[target] = true;

    queue<BinaryTreeNode<int>*> currQ;
    currQ.push(target);

    int ans = 0;
    while (!currQ.empty()){
        int n = currQ.size();
        ans++;

        for (int i=0; i<n; i++) {
            BinaryTreeNode<int>* curr = currQ.front();
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

    return ans-1;
}


int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    
    
    return 0;
}
