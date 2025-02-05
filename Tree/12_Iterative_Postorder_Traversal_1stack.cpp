#include <bits/stdc++.h>
using namespace std;
struct node
{
    long long data;
    struct node *left;
    struct node *right;
    node(long long data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

// Postorder Traversal - left right root

//            10
//        /        \
//      5           15
//    /   \       /    \
//   2     6    13      22
//  /          /  \
// 1          12   14

// Post-Order Traversal: 1 2 6 5 12 14 13 22 15 10

// Time Complexity: O(n)
// Space Complexity: O(n) | O(log n)

void postOrder(node *root)
{
    if (root == NULL)
        return;
    // Implemented using one stacks
    // Since we need first left tree then right and then root.
    // So at first we push root and then its left elements while popping out elements we travel right and then push its left and so on...
    stack<node*> s;
    node *temp = NULL;
    while (root != NULL || !s.empty())
    {
        while (root != NULL)
        {
            s.push(root);
            root = root->left;
        }
        while(root==NULL && !s.empty()){
            root=s.top();
            if(root->right==NULL || root->right==temp){
                cout<<root->data<<" ";
                s.pop();
                temp=root;
                root=NULL;
            }else{
                root=root->right;
            }
        }
    }
}

int main()
{
    struct node *root = new node(10);
    root->left = new node(5);
    root->left->left = new node(2);
    root->left->left->left = new node(1);
    root->left->right = new node(6);
    root->right = new node(15);
    root->right->left = new node(13);
    root->right->left->left = new node(12);
    root->right->left->right = new node(14);
    root->right->right = new node(22);
    cout << "Postorder Traversal: ";
    postOrder(root);
    cout << "\n";
    return 0;
}