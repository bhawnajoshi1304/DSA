// Binary Search Tree

//            8
//        /        \
//      5           12
//    /   \       /    \
//   4     7    11      14
//        /            /
//      6            13

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
node* LCA(node *root, int p, int q) {
    if (root == NULL)
        return NULL;
    if (root->data < p && root->data < q)
        return LCA(root->right, p, q);
    if (root->data > p && root->data > q)
        return LCA(root->left, p, q);
    return root;
}
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
    cout << "LCA of 11 and 13 is: " << LCA(t.root, 11, 13)->data << "\n";
    cout << "LCA of 5 and 13 is: " << LCA(t.root, 5, 13)->data << "\n";
    return 0;
}