#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
}*root = NULL, *traverse, *newNode, *temp, *traverse2;

class binaryTree
{
    public:

    void getData()
    {
        int choice;
        do
        {
            cout<<"\nChoose :\n1.Insert\n2.Display\n3.exit\n";
            cout<<"choice : "; 
            cin>>choice;

            switch(choice)
            {
                case 1 : insert();break;
                case 2 : inorder(root);break;
                case 3 : break;
                default : cout<<"\ninvalid input bruh";
            }
        }
        while(choice != 3);
    }

    void insert()
    {
        createNode();
       if(root == NULL)
       {
           pointNull();
           root = newNode;
           cout<<"\nRoot element Inserted\n";
       }
       else
       
       recurInsert(root);
      
    }

    struct node * recurInsert(struct node * traverse)
    {
        if(traverse != NULL)
        {
            if(newNode->data < traverse->data)
            {
                traverse->left = recurInsert(traverse->left);
                pointNull();
                // traverse->left = newNode;
                cout<<"\nElement inserted at left\n";

            }
            else if(newNode->data > traverse->data)
            {
                traverse->right = recurInsert(traverse->right);
                pointNull();
                // traverse->right = newNode;
                cout<<"\nElement inserted at right\n";
            }
            else if(traverse->data == newNode->data)
            {
                cout<<"\nYou Cannot insert similar data Bruh";
            }

            
        }
        
        return traverse;
    }




    void firstNode()
    {
        createNode();
        traverse = root;
        if(root == NULL)
        {
            newNode = root;
            pointNull();
        }
    }

    void inorder(struct node* traverse)
        {
            if(traverse == NULL)
            return;
            
                inorder(traverse->left);
                cout<<traverse->data<<"-->";
                inorder(traverse->right);
            
            // cout<<endl;
        }

    void pointNull()
    {
        newNode->left = NULL;
        newNode->right = NULL;
    }

    void createNode()
    {
        int value;
        newNode = (struct node*)malloc(sizeof(node));
        cout<<endl<<"\nEnter element :";
        cin>>value;
        newNode->data = value;
    }
};

int main()
{
    binaryTree bt;
    bt.getData();
    return 0;
}