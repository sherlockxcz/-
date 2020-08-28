#include<stdlib.h>
#include<stdio.h>

struct Node
{
    int data;
    Node* left;
    Node* right;
};
struct Tree
{
    Node* root;
};
//BTS
void insert(Tree* tree,int value)
{
    Node* node = (Node*) malloc(sizeof(Node));
    node->data=value;
    node->left=NULL;
    node->right=NULL;

    if(tree->root==NULL)
    {
        tree->root=node;
    }
    else
    {
        Node* temp=tree->root;
        while(temp!=NULL)
        {
            if(value < temp->data)
            {
                if(temp->left==NULL)
                {
                    temp->left=node;
                    return;
                }
                else
                {
                    temp =temp->left;
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
//高度
int get_height(Node* node)
{
    if(node==NULL)
    {
        return 0;
    }
    else
    {
        int left_h=get_height(node->left);
        int right_h=get_height(node->right);
        int max=left_h;
        if(right_h>max)
        {
            max=right_h;
        }
        return max+1;
    }
    
}
//找最大

int get_maximum(Node* node)
{
    if(node==NULL)
    {
        return -1;
    }
    else
    {
        int m1= get_maximum(node->left);
        int m2 =get_maximum(node->right);
        int m3 =node->data;
        int max=m3;
        if(m1>m3) max=m1;
        if(m2>m1) max=m2;
        return max;
    }
    
}

//先序遍历
void preorder(Node* node)
{
    if(node!=NULL)
    {
        printf("%d\n",node->data);
        preorder(node->left);
        preorder(node->right);
    }

}
//中序遍历
void inorder(Node* node)
{
    if (node!=NULL)
    {
        inorder(node->left);
        printf("%d\n",node->data);
        inorder(node->right);
    }
    
}
//后序遍历
void postorder(Node* node)
{
    if(node!=NULL)
    {
        postorder(node->left);
        postorder(node->right);
        printf("%d\n",node->data);
    }
}

int main()
{
    int arr[7]={6,3,8,2,5,1,7};
    Tree tree;
    tree.root=NULL;

    for(int i=0;i<7;i++)
    {
        insert(&tree,arr[i]);
    }
    //preorder(tree.root);
    int height=get_height(tree.root);
    printf("height:%d",height);
    int n=get_maximum(tree.root);
    printf("max=%d",n);
    return 0;
}