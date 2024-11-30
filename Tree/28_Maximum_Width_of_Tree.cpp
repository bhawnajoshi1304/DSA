// Maximum Width of Tree
// It is the number of imaginary and real nodes between any two nodes of tree in same level
//            10
//        /        \
//      5           15
//    /   \       /    \
//   2     6    13      22
//             /  \
//            12   14
// Maximum Width of Tree is: 4

// Explanation: between 2 and 22 4 nodes are present.
//              If 2 had a left child then ans would be 6

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

long long maximumWidth(node* root){
    long long ans=0;
    if(root==NULL) return ans;
    queue<pair<node*,long long>> q; // node and index
    q.push({root,0});
    while(!q.empty()){
        long long s=q.size(),mi,ma,mmin=q.front().second;
        for(long long i=0;i<s;i+=1){    
            long long ind=q.front().second-mmin; //To start indexes from 0
            node* tmp=q.front().first;
            if(tmp->left!=NULL) q.push({tmp->left,ind*2+1});
            if(tmp->right!=NULL) q.push({tmp->right,ind*2+2});
            q.pop();
            if(i==0) mi=ind;
            if(i==s-1) ma=ind;
        }
        ans=max(ans,ma-mi+1);
    }
    return ans;
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
    cout<<"Maximum Width of Tree is: "<<maximumWidth(root)<<"\n";
    return 0;
}