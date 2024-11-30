// Children Sum Property
// Value of every node in tree is equal to sum of values of its children nodes
//            50
//        /        \
//      7           2
//    /   \       /   \
//   3     1    40     30

// Tree following Children sum property is:
//            170
//        /        \
//     100         70
//    /   \       /   \
//  50     50   40     30


// Time Complexity: O(n)
// Space Complexity: O(n) | O(log n)
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
// We calculate sum of values of both left and right child
// If child value is greater than we reassign the value for root
// Else we reassign value for the child with root's value so as to ensure left and right value always remain sufficient to make root
// Recursive call to left and right child
// Collect the value of left and right child and then reassign root.
void changeTreeChildrenSumProperty(node* root){
    if(root==NULL) return;
    long long child=0;
    if(root->left){
        child+=root->left->data;
    }
    if(root->right){
        child+=root->right->data;
    }
    if(child>=root->data){
        root->data=child;
    }else{
        if(root->left!=NULL) 
        root->left->data = root->data;
        if(root->right!=NULL)
        root->right->data = root->data;
    }
    changeTreeChildrenSumProperty(root->left);
    changeTreeChildrenSumProperty(root->right);
    child=0;
    if(root->left){
        child+=root->left->data;
    }
    if(root->right){
        child+=root->right->data;
    }
    if(root->left!=NULL || root->right!=NULL)
    root->data = child;
}

void traversal(node *root){
    stack<pair<node *, int>> s;
    s.push({root, 1});
    vector<int> pre, in, post;
    if (root == NULL) return;
    while (!s.empty()){
        auto it = s.top();
        s.pop();
        if (it.second == 1){
            pre.push_back(it.first->data);
            it.second += 1;
            s.push(it);
            if (it.first->left != NULL)
                s.push({it.first->left, 1});
        }else if (it.second == 2){
            in.push_back(it.first->data);
            it.second += 1;
            s.push(it);
            if (it.first->right != NULL)
                s.push({it.first->right, 1});
        }else
            post.push_back(it.first->data);
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
int main()
{
    struct node *root = new node(50);
    root->left = new node(7);
    root->left->left = new node(3);
    root->left->right = new node(1);
    root->right = new node(2);
    root->right->left = new node(40);
    root->right->right = new node(30);
    changeTreeChildrenSumProperty(root);
    traversal(root);
    return 0;
}