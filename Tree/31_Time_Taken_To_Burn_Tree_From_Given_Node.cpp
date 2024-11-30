// Time taken to burn a tree from a node
// We burn a tree by burning adjacent nodes at a level one by one
//            10
//        /        \
//      5           15
//    /   \       /    \
//   2     6    13      22
//             /  \
//            12   14
// Time taken to burn tree from node 5 is: 4
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
void createParent(node *root, unordered_map<node *, node *> &parent, node *prev)
{
    if (root == NULL)
        return;
    parent[root] = prev;
    createParent(root->left, parent, root);
    createParent(root->right, parent, root);
}

long long burnTree(node *root, node *target)
{
    unordered_map<node *, node *> parent;
    createParent(root, parent, NULL);
    unordered_map<node *, bool> visited;
    int time = 0;
    queue<node *> q;
    q.push(target);
    while (!q.empty())
    {
        long long size = q.size();
        for (long long i = 0; i < size; i++)
        {
            node *tmp = q.front();
            q.pop();
            if (visited.find(tmp) == visited.end())
                visited[tmp] = true;
            if (tmp->left != NULL && visited.find(tmp->left) == visited.end())
                q.push(tmp->left);
            if (tmp->right != NULL && visited.find(tmp->right) == visited.end())
                q.push(tmp->right);
            if (parent[tmp] != NULL && visited.find(parent[tmp]) == visited.end())
                q.push(parent[tmp]);
        }
        if (q.size() > 0)
            time += 1;
    }
    return time;
}

int main()
{
    struct node *root = new node(10);
    root->left = new node(5);
    root->left->left = new node(2);
    root->left->right = new node(6);
    root->right = new node(15);
    root->right->left = new node(13);
    root->right->left->left = new node(12);
    root->right->left->right = new node(14);
    root->right->right = new node(22);
    node *tmp = root->left;
    long long k = 3;
    cout << "Time taken to burn tree from given node " << tmp->data << " is: " << burnTree(root, tmp) << "\n";
    return 0;
}