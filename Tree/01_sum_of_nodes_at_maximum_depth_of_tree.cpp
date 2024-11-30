// A tree is represented with a structure consisting of a data node and two pointers left and right.

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
int fun(node *root, int &level, int &max_level, int &sum)
{
    if (root == NULL)
        return sum;
    if (level == max_level)
        sum += root->data;
    if (level > max_level)
    {
        max_level = level;
        sum = root->data;
    }
    int tmp = level;
    level += 1;
    sum = fun(root->left, level, max_level, sum);
    level = tmp + 1;
    sum = fun(root->right, level, max_level, sum);
    return sum;
}

//            10
//        /        \
//      5           15
//    /   \       /    \
//   2     6    13      22
//  /          /  \
// 1          12   14
// Sum of nodes at maximum depth is: 1 + 12 + 14 = 27
// Procedure to create new node

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
    int max_level = 0, level = 1, sum = 0;
    cout << "Sum of nodes at maximum depth is: " << fun(root, level, max_level, sum) << "\n";
    return 0;
}
