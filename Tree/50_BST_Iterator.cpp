// Binary Search Tree

//            8
//        /        \
//      5           12
//    /   \       /    \
//   4     7    11      14
//        /            /
//      6            13
// Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):
    // BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
    // boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
    // int next() Moves the pointer to the right, then returns the number at the pointer.
#include <bits/stdc++.h>
using namespace std;
struct node {
    long long data;
    struct node *left;
    struct node *right;
    node(long long data) {
        this->data = data;
        this->left = this->right = NULL;
    }
};
class BST {
public:
    node *root;
    BST() {
        root = NULL;
    }
    void insert(int data) {
        if (root == NULL){
            root = new node(data);
            return;
        }
        node *curr = root;
        while (true) {
            if (curr->data <= data) {
                if (curr->right == NULL) {
                    curr->right = new node(data);
                    break;
                }
                else
                    curr = curr->right;
            }
            else {
                if (curr->left == NULL) {
                    curr->left = new node(data);
                    break;
                }
                else
                    curr = curr->left;
            }
        }
    }
    void remove (int data) {
        if (root == NULL)
            return;
        if (root->data == data) {
            root = helper(root);
            return;
        }
        node *curr = root;
        while (curr != NULL) {
            if (curr->data > data) {
                if (curr->left != NULL && curr->left->data == data) {
                    curr->left = helper(curr->left);
                    break;
                }
                else
                    curr = curr->left;
            }
            else {
                if (curr->right != NULL && curr->right->data == data) {
                    curr->right = helper(curr->right);
                    break;
                }
                else
                    curr = curr->right;
            }
        }
    }
    node* helper(node *curr) {
        if (curr->left == NULL)
            return curr->right;
        if (curr->right == NULL)
            return curr->left;
        node *rightmostLeft = curr->left;
        while (rightmostLeft->right != NULL)
            rightmostLeft = rightmostLeft->right;
        rightmostLeft->right = curr->right;
        node *tmp = curr->left;
        delete curr;
        return tmp;
    }
    bool search(int data) {
        node *curr = root;
        while (curr != NULL) {
            if (curr->data == data)
                return true;
            if (curr->data < data)
                curr = curr->right;
            else
                curr = curr->left;
        }
        return false;
    }
};
class BSTIterator {
    stack<node *> inorder;
    bool reverse;
    void pushAll(node *root) {
        while (root != NULL) {
            inorder.push(root);
            if (reverse)
                root = root->right;
            else
                root = root->left;
        }
    }
public:
    BSTIterator(node *root, bool isReverse=false) {
        reverse = isReverse;
        pushAll(root);
    } 
    int next() {
        node *curr = inorder.top();
        inorder.pop();
        if (reverse)
            pushAll(curr->left);
        else
            pushAll(curr->right);
        return curr->data;
    } 
    bool hasNext() {
        return !inorder.empty();
    }
};
int main() {
    BST t;
    t.insert(8);
    t.insert(5);
    t.insert(12);
    t.insert(7);
    t.insert(4);
    t.insert(6);
    t.insert(11);
    t.insert(14);
    t.insert(13);
    BSTIterator i(t.root);
    while (i.hasNext())
        cout << i.next() << " ";
    cout << "\n";
    BSTIterator j(t.root,true);
    while (j.hasNext())
        cout << j.next() << " ";
    cout << "\n";
    return 0;
}