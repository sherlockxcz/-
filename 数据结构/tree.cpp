#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    Node* left;
    Node* right;
};
//先序遍历  根-左-右
void preorder(Node* node)
{
    if(node!=NULL)
    {
        printf("%d\n",node->data);
        preorder(node->left);
        preorder(node->right);
    }

}
//中序遍历 左-跟-右
void inorder(Node* node)
{
    if (node!=NULL)
    {
        inorder(node->left);
        printf("%d\n",node->data);
        inorder(node->right);
    }
    
}
//后序遍历 左 右 跟
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
    Node n1;
    Node n2;
    Node n3;
    Node n4;
    
    n1.data=5;
    n2.data=6;
    n3.data=7;
    n4.data=8;
    
    n1.left=&n2;
    n2.left=&n4;
    n1.right=&n3;

    n2.right=NULL;
    n3.right=NULL;
    n3.left=NULL;
    n4.right=NULL;
    n4.left=NULL;
    
    postorder(&n1);

    
    return 0;

}
