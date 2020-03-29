#include<bits/stdc++.h>
using namespace std;
struct node
{
  int key;
  struct node *left=NULL,*right=NULL;
};
struct node *newnode(int key)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->key=key;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
struct node *insert(struct node *node,int key)
{
    if(node==NULL)
    return newnode(key);
    if(key<node->key)
    node->left=insert(node->left,key);
    else if(key>node->key)
    node->right=insert(node->right,key);
    return node;
}
void inorder(struct node *node)
{
    if(node!=NULL)
    {
       inorder(node->left);
       cout<<node->key<<endl;
       inorder(node->right);
    }
}
int main()
{
    struct node *root=NULL;
    root=insert(root,10);
    insert(root,20);
    insert(root,30);
    insert(root,40);
    insert(root,50);
    insert(root,60);
    insert(root,70);
    inorder(root);
}
