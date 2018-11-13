#include<iostream>
#include<stdio.h>
#include<cstdlib>
using namespace std;
struct BstNode
{
	int data;
    struct BstNode *left,*right;
};
struct BstNode *newNode(int data)
{
    struct BstNode *temp=new BstNode();
    temp->data=data;
    temp->right=NULL;
    temp->left=NULL;
}
struct BstNode* insert(struct BstNode *root,int data)
{
	if(root==NULL)
        return(newNode(data));
    else if(root->data>data)
        root->left=insert(root->left,data);
    else
        root->right=insert(root->right,data);
    return root;
}
bool find_element(struct BstNode *root, int data)
{
    // Traverse untill root reaches to dead end
    while (root != NULL)
    {
        // pass right subtree as new tree

        if (root->data<data)
            root = root->right;

        // pass left subtree as new tree
        else if (root->data>data)
            root = root->left;
        else
            return true;// if the key is found return 1
    }
    return false;
}

struct BstNode* MinValue(struct BstNode *root)
{
    struct BstNode *current=root;
    while(current->left!=NULL)
        current=current->left;
    return current;
}
struct BstNode* deleteNode(struct BstNode *root,int data)
{

     if(root==NULL)
      return root;

       if(data<root->data)
         root->left=deleteNode(root->left,data);
       else if(data>root->data)
        root->right=deleteNode(root->right,data);
       else
       {

            if(root->left==NULL)   // root has one child,no child
            {
                struct BstNode *temp=root->right;
                free(root);
                return temp;
            }
            else if(root->right==NULL)   // root has one child, no child
           {
               struct BstNode *temp=root->left;
               free(root);
               return temp;
           }
                // root has 2 child
             struct BstNode *temp=MinValue(root->right);  // get min value from right of root otherwise max value from  left of root
             root->data=temp->data;                          // copy min or max value to root
             root->right=deleteNode(root->right,temp->data);
                // delete min or max value
       }

       return root;  // backtracking
}
void in_order(struct BstNode *root)
{


        if (root != NULL)
    {
        in_order(root->left);
        cout<<root->data<<" ";

    }
        in_order(root->right);
}
void pre_order(struct BstNode *root)
{
        if (root != NULL)
    {
        cout<<root->data<<" ";
        pre_order(root->left);
        pre_order(root->right);
    }
}

void post_order(struct BstNode *root)
{
        if (root != NULL)
    {
        post_order(root->left);
        post_order(root->right);
        cout<<root->data<<" ";
    }
}
int main()
{
        int c,num;
        struct BstNode *root=NULL;
        cout<<"Enter choice"<<endl<<"1 Insert"<<endl<<"2 Delete"<<endl;
        cout<<"3 In-Order"<<endl<<"4 Pre-Order"<<endl<<"5 Post-Order"<<endl<<"6 Exit"<<endl;
        while(1)
        {
            cout<<"\nEnter choice"<<endl;
            cin>>c;
            switch(c)
            {
                case 1:
                    {
                        cout<<"Enter value to be inserted"<<endl;
                        cin>>num;
                        root=insert(root,num);
                        break;
                    }
                case 2:
                    {
                        cout<<"Enter value to be deleted"<<endl;
                        int n;
                        cin>>n;
                        if(find_element(root,n))
                        deleteNode(root,n);
                        else
                            cout<<"Node not found"<<endl;

                        break;
                    }
                case 3:
                    {
                        cout<<"In-Order: ";
                        in_order(root);
                        break;
                    }
                case 4:
                    {
                        cout<<"Pre-Order: ";
                        pre_order(root);
                        break;
                    }
                case 5:
                    {
                        cout<<"Post_Order: ";
                        post_order(root);
                        break;
                    }
                case 6:
                    {
                        exit(0);
                    }
                default:
                    cout<<"Enter valid choice"<<endl;
            }
        }
    }
