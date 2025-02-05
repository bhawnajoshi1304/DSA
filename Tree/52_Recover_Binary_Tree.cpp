// Binary Search Tree

//            8
//        /        \
//      5           15
//    /   \       /    \
//   3     7    10      25
//                     /
//                   20

// In the given BST two node values are swapped.
// There are two types of swapping:
    // adjacent
    // swap the first and middle violation
    // 8-7
    // 3 5 8 7 10 15 20 25

    // non-adjacent
    // swap the first and last violation
    // 25-5
    // 3 25 7 8 10 15 20 5
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
void traversal(node *root) {
    stack<pair<node *, int>> s;
    s.push({root, 1});
    vector<int> pre, in, post;
    if (root == NULL)
        return;
    while (!s.empty()) {
        auto it = s.top();
        s.pop();
        if (it.second == 1) {
            pre.push_back(it.first->data);
            it.second += 1;
            s.push(it);
            if (it.first->left != NULL) {
                s.push({it.first->left, 1});
            }
        }
        else if (it.second == 2) {
            in.push_back(it.first->data);
            it.second += 1;
            s.push(it);
            if (it.first->right != NULL) {
                s.push({it.first->right, 1});
            }
        }
        else {
            post.push_back(it.first->data);
        }
    }
    cout << "Preorder Traversal: ";
    for (auto i : pre)
        cout << i << " ";
    cout << "\n";
    cout << "Inorder Traversal: ";
    for (auto i : in)
        cout << i << " ";
    cout << "\n";
    cout << "Postorder Traversal: ";
    for (auto i : post)
        cout << i << " ";
    cout << "\n";
}

node *first, *tmp, *middle, *last;
void inorderCheck(node* root) {
    if (root == NULL)
        return;
    inorderCheck(root->left);
    if (tmp != NULL && root->data < tmp->data) {
        if (first == NULL) {
            first = tmp;
            middle = root;
        }
        else
            last = root;
    }
    tmp = root;
    inorderCheck(root->right);
}
void recoverTree(node *root) {
    first = middle = last = NULL;
    tmp = new node(INT_MIN);
    inorderCheck(root);
    if (first != NULL && last != NULL)
        swap(first->data, last->data);
    else if (first != NULL && middle != NULL)
        swap(first->data, middle->data);
}
int main() {
    struct node *root = new node(8);
    root->left = new node(5);
    root->left->left = new node(3);
    root->left->right = new node(7);
    root->right = new node(15);
    root->right->left = new node(10);
    root->right->right = new node(25);
    root->right->right->left = new node(20);
    // swap 8 7
    swap(root->data, root->left->right->data);
    cout<<"Before recover:\n";
    traversal(root);
    cout << "\n";
    recoverTree(root);
    cout<<"After recover:\n";
    traversal(root);
    cout << "\n";
    // swap 5 25
    swap(root->left->data, root->right->right->data);
    cout<<"Before recover:\n";
    traversal(root);
    cout << "\n";
    recoverTree(root);
    cout<<"After recover:\n";
    traversal(root);
    cout << "\n";
    return 0;
}