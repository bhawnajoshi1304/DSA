// Print all nodes at distance k from a node
// We have to give level k from given node taken as root for the graph.
//            10
//        /        \
//      5           15
//    /   \       /    \
//   2     6    13      22
//             /  \
//            12   14

// The nodes at distance 3 from given node 5 is: 13 22 
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

void nodesAtDistanceK(node *root, node *target, int k)
// vector<long long> nodesAtDistanceK(node *root, node *target, int k)
{
    unordered_map<node *, node *> parent;
    createParent(root, parent, NULL);
    unordered_map<node *, bool> visited;
    int dist = 0;
    // vector<long long> ans;
    queue<node *> q;
    q.push(target);
    while (!q.empty() && dist < k)
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
        dist += 1;
    }
    while (!q.empty())
    {
        cout<<q.front()->data<<" ";
        // node *tmp = q.front();
        q.pop();
        // ans.push_back(tmp->data);
    }
    // return ans;
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
    cout << "The nodes at distance " << k << " from given node " << tmp->data << " is: ";
    nodesAtDistanceK(root,tmp,k);
    // for (auto i : nodesAtDistanceK(root, tmp, k))
    //     cout << i << " ";
    cout << "\n";
    return 0;
}