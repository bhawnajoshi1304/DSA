// Given a value of node and assuming no two nodes have same value and element is always present in tree print path from root to node.
//            10
//        /        \
//      5           15
//    /   \       /    \
//   2     6    13      22
//             /  \
//            12   14
// Path to 13: 10 15 13

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

void search(node* root,int val,vector<long long> &path,bool &flag){
    if(root==NULL || flag) return;
    path.push_back(root->data);
    if(root->data==val){
        flag=true;
        return;
    } 
    search(root->left,val,path,flag);
    if(flag) return;
    search(root->right,val,path,flag);
    if(flag) return;
    path.pop_back();
}

void PathToVal(node* root,long long val){
    bool flag=false;
    vector<long long> path;
    search(root,val,path,flag);
    for(auto i:path){
        cout<<i<<" ";
    }
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
    int val=13;
    cout<<"Path to "<<val<<" is: ";
    PathToVal(root,val);
    cout<<"\n";
    return 0;
}