//二叉搜索树
#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node
{
    int data;
    Node* right;
    Node* left;
};

struct Tree
{
    Node* root;
};



void insert(Tree *tree,int value)
{
    Node* node=(Node*)malloc(sizeof(Node));
    node->data=value;
    node->left=NULL;
    node->right=NULL;

    if(tree->root=NULL)
    {
        tree->root=node;
    }
    else
    {
        Node* temp=tree->root;
        while(temp!=NULL)
        {
            if(value< temp->data)
            {
                if(temp->left==NULL)
                {
                    temp->left=node;
                    return;
                }
                else
                {
                    temp=temp->left;
                }
                
            }
            else
            {
                if(temp->right==NULL)
                {
                    temp->right=node;
                    return;
                }
                else
                {
                    temp=temp->right;
                }
                
            }
            
        }
    }

}
    
void preorder(Node* node)
{
    if(node!=NULL)
    {
        cout<<node->data<<endl;
        preorder(node->left);
        preorder(node->right);
    }
}

void inorder(Node* node)
{
    if(node!=NULL)
    {
        inorder(node->left);
        cout<<node->data<<endl;
        inorder(node->right);
    }
}

void backorder(Node* node)
{
    if(node!=NULL)
    {
        
        backorder(node->left);
        backorder(node->right);
        cout<<node->data<<endl;
    }
}

int main()
{
    int array[7]={6,3,8,2,5,1,7};
    Tree tree;
    tree.root=NULL;

    for(int i=0;i<7;i++)
    {
        insert(&tree,array[i]);
    }
    preorder(tree.root);
}