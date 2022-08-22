#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left, *right;
    
    node()
    {
        left = right = NULL;
    }
    node (int x)
    {
        data = x;
        left = right = NULL;
    }
    ~node()
    {
        delete left;
        delete right;
    }

};

void print(node *root)
{
    if(root==NULL)
        return;
    print(root->left);
    cout<<root->data<<" -> ";
    print(root->right);
}

int main()
{
    /*
            2
           / \
          3   4
         / \ / \
        5  6 7  8
    */
    node *root = new node();
    root->data = 2;

    root->left = new node(3);
    root->left->left = new node(5);
    root->left->right = new node(6);

    root->right = new node(4);
    root->right->left = new node(7);
    root->right->right = new node(8);

    print(root);

    return 0;
}