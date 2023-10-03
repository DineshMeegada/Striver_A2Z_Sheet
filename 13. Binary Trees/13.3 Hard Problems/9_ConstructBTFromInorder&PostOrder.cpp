#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}
node* construct(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd, map<int, int> &inMap) {
    if (inStart>inEnd || postStart>postEnd) return NULL;

    node *root = newNode (postorder[postEnd]);

    int inIndex = inMap[root->data];
    int numsRight = inEnd-inIndex;

    root->left = construct(inorder, inStart, inIndex-1, postorder, postStart, postEnd-numsRight-1, inMap);
    root->right = construct(inorder, inIndex+1, inEnd, postorder, postEnd-numsRight, postEnd-1, inMap);

    return root;
}

node* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (inorder.size() != postorder.size() || inorder.empty()) return nullptr;

    map<int, int> inMap;
    for (int i=0; i<inorder.size(); i++) {
        inMap[inorder[i]] = i;
    }

    node *root = construct (inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, inMap);

    return root;

}

int main() {

  vector<int> preorder{10,20,40,50,30,60};
  vector<int> inorder{40,20,50,10,60,30};
  node * root = buildTree(preorder, inorder);
  return 0;
}