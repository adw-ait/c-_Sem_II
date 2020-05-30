#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
}*root = NULL, *traverse, *newNode, *temp, *traverse2, *minValue;

class binaryTree
{
    public:
            int choice, value;
            int response;


    void getData()
    {
        do
        {
            cout<<endl;
            cout<<"\nChoose :\n1.Insert\n2.Display\n3.Sort\n4.Exit\n";
            cout<<"choice : "; 
            cin>>choice;
            cout<<endl;

            switch(choice)
            {
               case 1 : insert();break;
               case 2 : display(root);break;
               case 3 : sort(root);break;
               case 4 : break;
               default : cout<<"\nInvalid input";
            }
        }

        while(choice != 7);
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
        {
            traverse = root;          

                while((newNode->data < traverse->data) && traverse->left != NULL)
                {
                   
                    traverse = traverse->left;
        
                }

                while((newNode->data > traverse->data) && traverse->right != NULL)
                {
                    
                    traverse = traverse->right;
                   
                }

                while((newNode->data < traverse->data) && traverse->left != NULL)
                {
                   
                    traverse = traverse->left;
                    
                }

             if(newNode->data < traverse->data)
            {
                pointNull();
                traverse->left = newNode;
                cout<<"\nNode inserted at left\n";
            }
            else if(newNode->data > traverse->data)
            {
                pointNull();
                traverse->right = newNode;
                cout<<"\nNode inserted at right\n";
            }
            else if(newNode->data == traverse2->data)
            {
                cout<<"\nYou Cannot insert similar data Bruh";
                cout<<"\nInsert new value Bruh";
                insert();
            }
        }  
    }


    void sort(struct node* traverse)
        {
            if(traverse == NULL)
            return;
            
                sort(traverse->left);
                cout<<traverse->data<<"-->";
                sort(traverse->right);
        }

        void display(struct node * traverse)
        {
            if(traverse == NULL)
            return;

                cout<<traverse->data<<"-->";
                display(traverse->left);
                display(traverse->right);

        }

        void pointNull()
    {
        newNode->left = NULL;
        newNode->right = NULL;
    }

    void createNode()
    {
        newNode = (struct node*)malloc(sizeof(node));
        cout<<endl<<"Enter element : ";
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
