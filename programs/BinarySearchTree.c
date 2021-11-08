#include <stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}node;
node* root = NULL;
void insert(int v)
{
    node* temp = (node*)malloc(sizeof(node));
    node* p;
    node* p1=NULL;
    if (temp==NULL)
    {
        printf("\nMemory not allocated. Node is not inserted");
        return;
    }
    temp->data = v;
    temp->left = NULL;
    temp->right = NULL;
    if(root == NULL)
    {
        root = temp;
        printf("\nnode with %d value inserted successfully", temp->data);
    }
    else
    {
        p = root;
        do
        {
            if(v<p->data)
            {
                p1 = p;
             p = p->left;
            }
            else 
            {
                p1 = p;
                p = p->right;
            }
        }while(p!=NULL);
        if (v < p1->data)
        {
            p1->left = temp;
        }
        else
        {
            p1->right = temp;
        }
        printf("\nnode with %d value inserted successfully", temp->data);
    }
}
void inorder(node* p)
{
    if(p==NULL)
    {
        return;
    }
    inorder(p->left);
    printf("%d ",p->data);
    inorder(p->right);
    
}

void preorder(node* p)
{
    if(p==NULL)
    {
        return;
    }
    printf("%d ",p->data);
    preorder(p->left);
    
    preorder(p->right);
    
}
void postorder(node* p)
{
    if(p==NULL)
    {
        return;
    }
    
    postorder(p->left);
    
    postorder(p->right);
    printf("%d ",p->data);
    
}
int minVal(node * p){
    while(p->left!=NULL){
        p=p->left;
    }
    return p->data;
}
void del(node*root, int v)
{
    
   node* p = root;
   node* p1 = NULL;
   node *temp;
   if(root==NULL){
       printf("\nTree is empty");
       return;
   }
   //find node with given value
    do
    {
        if(p->data==v)
            break;
        if(v < p->data)
        {
            p1=p;
            p = p->left;
        }
        else if (v > p->data)
        {
            p1=p;
            p = p->right;
        }
    }while(p!=NULL);
    
    if (p==NULL)
    {
        printf("\nNode not present in the tree");
        return;
    }
    else
    {
        if(p1==NULL){
            //only one node in tree, thats root node 
            temp=root;
            root=NULL;
            printf("\nnode with value %d deleted",temp->data);
            free(temp);
            return;
        }
        else{
            //node with no child
            if(p->left==NULL && p->right==NULL){
                if(p1->data<v){
                    p1->right=NULL;
                }
                else if(p1->data>v){
                    p1->left=NULL;
                    
                }
                printf("\nnode with value %d deleted",p->data);
                free(p);
                return;
            }
            //node with 2 childs
            else if(p->left!=NULL && p->right!=NULL){
                printf("\nnode with value %d replaced with ",p->data);
                p->data=minVal(p->right);
                printf("%d ",p->data);
                del(p->right,p->data);
                return;
            }
            //node with one child
            else{
                if(p->left==NULL){
                    if(p1->data<v){
                        p1->right=p->right;
                    }
                    else if(p1->data>v){
                        p1->left=p->right;
                    }
                }
                else{
                    if(p1->data<v){
                        p1->right=p->left;
                    }
                    else if(p1->data>v){
                        p1->left=p->left;
                    }
                }
                printf("\nnode with value %d deleted",p->data);
                free(p);
                return;
            }
        }
    }

}

int main()
{
	//write a menu driven code as per your requirement
    insert(50);
    insert(25);
    insert(12);
    insert(30);
    insert(6);
    insert(75);
    insert(60);
    insert(52);
    insert(70);
    printf("\nInorder traversal: ");
    inorder(root);
    del(root,25);
    printf("\nInorder traversal: ");
    inorder(root);
    
    return 0;
}