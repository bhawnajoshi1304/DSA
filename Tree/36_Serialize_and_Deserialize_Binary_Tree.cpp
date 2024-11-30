// Complete Binary tree is as filled as possible in the left
//            10
//        /        \
//      5           15
//    /   \       /    \
//   2     6    13      22
//  / \
// 12  14

// Count of nodes in complete binary tree is: 9
// Time Complexity: O(n)
// Space Complexity: O(n) | O(log n)
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
            if (it.first->left != NULL)
                s.push({it.first->left, 1});
        }
        else if (it.second == 2) {
            in.push_back(it.first->data);
            it.second += 1;
            s.push(it);
            if (it.first->right != NULL)
                s.push({it.first->right, 1});
        }
        else
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
string serialize(node *root) {
    if (!root)
        return "";
    string s = "";
    queue<node *> q;
    q.push(root);
    while (!q.empty()) {
        node *curr = q.front();
        q.pop();
        if (curr == NULL)
            s.append("#,");
        else
            s.append(to_string(curr->data) + ",");
        if (curr != NULL) {
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    return s;
}
node *deserialize(string data) {
    if (data.size() == 0)
        return NULL;
    stringstream s(data);
    string str;
    getline(s, str, ',');
    node *root = new node(stoi(str));
    queue<node *> q;
    q.push(root);
    while (!q.empty()) {
        node *n = q.front();
        q.pop();
        getline(s, str, ',');
        if (str == "#")
            n->left = NULL;
        else {
            node *leftNode = new node(stoi(str));
            n->left = leftNode;
            q.push(leftNode);
        }
        getline(s, str, ',');
        if (str == "#")
            n->right = NULL;
        else {
            node *rightNode = new node(stoi(str));
            n->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
int main() {
    struct node *root = new node(10);
    root->left = new node(5);
    root->left->left = new node(2);
    root->left->right = new node(6);
    root->right = new node(15);
    root->right->left = new node(13);
    root->left->left->left = new node(12);
    root->left->left->right = new node(14);
    root->right->right = new node(22);
    cout << "Serialized tree: " << serialize(root) << "\n";
    traversal(deserialize("10,5,15,2,6,13,22,12,14,#,#,#,#,#,#,#,#,#,#,"));
    traversal(deserialize("1,2,13,#,#,4,5,#,#,#,#,"));
    return 0;
}