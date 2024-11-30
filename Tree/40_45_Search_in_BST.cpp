// Binary Search Tree
// Nodes of left subtree are less than root and nodes on right subtree are greater than root.
// Inorder gives sorted array.
// No duplicates allowed ideally can be stored as frequency or as right child.
// Generally gives O(log n) search time for elements.
//            8
//        /        \
//      5           12
//    /   \       /    \
//   4     7    11      14
//        /            /
//      6            13
// For insertion in a BST we traverse the tree searching for element until we find an emty node and insert it there.

// For deletion we check if it has both left and right child in tree. If only one child then replace node with its child otherwise attach the right subtree to rightmost element of left subtree and replace node with left element

// Ceil in BST gives the smallest number greater than equal to the given number. Search for leftmost element in right tree if not searchble.

// Floor in BST gives the greatest number smaller than equal to the given number. Search for rightmost element in left tree if not searchble.

// For searching kth smallest number in BST make use of inorder traversal with count of numbers. Use morris traversal to reduce space complexity.

// For searching kth largest number in BST make use of modified inorder(right root left) traversal with count of numbers. Use morris traversal to reduce space complexity.

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
void inOrder(node *root) {
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

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
    int findCeil(int data){
        int ceil =-1;
        node *curr = root;
        while (curr != NULL) {
            if (curr->data == data)
                return curr->data;
            if (curr->data < data)
                curr = curr->right;
            else {
                ceil = curr->data;
                curr = curr->left;
            }
        }
        return ceil;
    }
    int findFloor(int data){
        int floor =-1;
        node *curr = root;
        while (curr != NULL) {
            if (curr->data == data)
                return curr->data;
            if (curr->data > data)
                curr = curr->left;
            else {
                floor = curr->data;
                curr = curr->right;
            }
        }
        return floor;
    }
    int kthSmallest(int k){
        int c = 0;
        node *curr = root;
        while (curr != NULL) {
            if (curr->left == NULL) {
                if (c == k - 1)
                    return curr->data;
                c += 1;
                curr = curr->right;
            }else {
                node *prev = curr->left;
                while (prev->right != NULL && prev->right != curr)
                    prev = prev->right;
                if (prev->right == NULL) {
                    prev->right = curr;
                    curr = curr->left;
                } else if (prev->right == curr) {
                    prev->right = NULL;
                    if (c == k - 1)
                        return curr->data;
                    c += 1;
                    curr = curr->right;
                }
            }
        }
        return -1;
    }
    int kthLargest(int k){
        int c = 0;
        node *curr = root;
        while (curr != NULL) {
            if (curr->right == NULL) {
                if (c == k - 1)
                    return curr->data;
                c += 1;
                curr = curr->left;
            }else {
                node *prev = curr->right;
                while (prev->left != NULL && prev->left != curr)
                    prev = prev->left;
                if (prev->left == NULL) {
                    prev->left = curr;
                    curr = curr->right;
                } else if (prev->left == curr) {
                    prev->left = NULL;
                    if (c == k - 1)
                        return curr->data;
                    c += 1;
                    curr = curr->left;
                }
            }
        }
        return -1;
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
    cout << "12 found in BST: " << t.search(12) << "\n";
    cout << "Inorder of BST: ";
    inOrder(t.root);
    cout << "\n";
    t.remove(12);
    t.insert(15);
    cout << "12 found in BST: " << t.search(12) << "\n";
    cout << "Inorder of BST: ";
    inOrder(t.root);
    cout << "\n";
    cout << "Floor of 9 in BST is: " << t.findFloor(9) << "\n";
    cout << "Ceil of 9 in BST is: " << t.findCeil(9) << "\n";
    cout << "3rd smallest number in BST: " << t.kthSmallest(3) << "\n";
    cout << "3rd largest number in BST: " << t.kthLargest(3) << "\n";
    return 0;
}