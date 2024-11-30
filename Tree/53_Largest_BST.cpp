// Binary Tree
//            10
//        /        \
//      15          5
//    /   \       /    \
//   2     6    13      22
//             /  \
//            12   14

// Largest BST means largest size subtree which is BST.
// Calculate the smallest value in left subtree and largest value in right subtree. If node lies in range then a BST. size of this BST is x+y+1, where x is size of left subtree and y is size of right subtree.
// Use postorder traversal
#include <bits/stdc++.h>
using namespace std;
struct node {
    int data;
    struct node *left;
    struct node *right;
    node(int data) {
        this->data = data;
        this->left = this->right = NULL;
    }
};
class nodeValue{
    public: 
    int maxNode, minNode, maxSize;
    nodeValue(int minValue, int maxValue, int size){
        minNode=minValue;
        maxNode=maxValue;
        maxSize=size;
    }
};
nodeValue largestBSThelper(node *root){
    if (root == NULL)
        return nodeValue(INT_MAX, INT_MIN, 0);
    auto left = largestBSThelper(root->left);
    auto right = largestBSThelper(root->right);
    if (left.maxNode < root->data && root->data < right.minNode)
        return nodeValue(min(root->data, left.minNode), max(root->data, right.maxNode), left.maxSize + right.maxSize + 1);
    return nodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
}
int largestBST(node* root){
    return largestBSThelper(root).maxSize;
}
int main() {
    struct node *root = new node(10);
    root->left = new node(15);
    root->left->left = new node(2);
    root->left->right = new node(6);
    root->right = new node(5);
    root->right->left = new node(13);
    root->right->left->left = new node(12);
    root->right->left->right = new node(14);
    root->right->right = new node(22);
    cout<<largestBST(root)<<"\n";
    return 0;
}