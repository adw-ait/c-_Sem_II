#include<iostream>
using namespace std;

struct node // user defined node data type 
{
    int data; //to store data of the node
    struct node *left; //to set left pointer
    struct node *right; //to set right pointer
}*root = NULL, *traverse, *newNode, *temp, *traverse2, *minValue;

class binaryTree //class for binary tree
{
    public:
            int choice, value; //value : will be used to store value taken from user, choice will be usedd to get one choice from user from given menu
            int response;


    void getData()//function that gets required data from user
    {
        do
        {
            cout<<endl;
            cout<<"\nChoose :\n1.Insert\n2.Display\n3.Search\n4.DeleteNode\n5.PreOrder\n6.PostOrder\n7.Exit\n";
            cout<<"choice : "; 
            cin>>choice;
            cout<<endl;

            switch(choice)
            {
                case 1 : insert();break; //insert node
                case 2 : inorder(root);break; //displayed the tree in inorder fashion
                case 3 : search();break; //search a node in the tree
                case 4 : deleteNode();break; //delete a particular node
                case 5 : preOrder(root);break;//display in preorder sequence, i.e Root,Left,Right
                case 6 : postOrder(root);break;//display in preorder sequence, i.e Left,Right,Root
                case 7 : break;//exit from program
                default : cout<<"\ninvalid input bruh";//choice doesn't match above conditions
            }
        }

        while(choice != 7);//loop until user exits
    }

    void insert()//insert into the tree
    {
        createNode();//function which creates new node to insert

        if(root == NULL)//if null new node will be root element in this case
        {
            pointNull(); //function where right and left pointer points NULL
            root = newNode; //root is assigned to new node
            cout<<"\nRoot element Inserted\n";
        }

        else//if root is already present
        {
            traverse = root; //temporary pointer which will point to root node

                while((newNode->data < traverse->data) && traverse->left != NULL)//loop to left until it is NULl
                {
                   
                    traverse = traverse->left; //move to left next node
        
                }

                while((newNode->data > traverse->data) && traverse->right != NULL) //loop to right until it is NULL
                {
                    
                    traverse = traverse->right; //move to next right node
                   
                }

                while((newNode->data < traverse->data) && traverse->left != NULL)
                {
                   
                    traverse = traverse->left;
                    
                }

             if(newNode->data < traverse->data)//if value is smaller than the node traverse is pointing
            { // then do this
                pointNull();
                traverse->left = newNode;
                cout<<"\nNode inserted at left\n";
            }
            else if(newNode->data > traverse->data)//if value is greater than node traverse is pointing
            { // then do this
                pointNull();
                traverse->right = newNode;
                cout<<"\nNode inserted at right\n";
            }
            else if(newNode->data == traverse2->data) //if value is value is same it will not be inserted, no similar value allowed
            {
                cout<<"\nYou Cannot insert similar data Bruh";
                cout<<"\nInsert new value Bruh";
                insert(); //insert function is called to insert the value again
            }
        }  
    }

    void search() //function to search the element
    {
        int value; //search value
        cout<<"\nENter value to be searched : ";
        cin>>value; //useer inputs the value

        if(root == NULL) //if root is null tree doesn't exist
        {
            cout<<"\nTree is empty, Insert something first";
            insert(); //insert function called to insert the element
        }

        else
        {
            traverse = root; //temporary pointer pointing to nodes

             while((traverse->data != value)  && (traverse->right != NULL || traverse->left != NULL)) //loop until value is found in the tree and until the left and right pointer becomes null
            {    
                while(value < traverse->data && traverse->data != value && traverse->left != NULL) //if value is smaller go to left
                {
                    traverse = traverse->left; //move to left node
                    
                }

                while(value > traverse->data && traverse->data != value && traverse->right != NULL) //if value is greater than root go to right
                {
                    traverse = traverse->right; // move to right
                    
                }
            }

             if(value == traverse->data) //vale found
            {
                cout<<"\nValue found!!!\n";
            }

            else if(traverse->left == NULL || traverse->right == NULL) //if right and left is null
            {
                cout<<"\nValue not present in the tree";
                cout<<"\nYou can insert it, if you want";
                insertSearchedElement(); // searched element is inserted in the tree
            }

            else
            {
                cout<<"\nValue not present in the tree";
                cout<<"\nYou can insert it, if you want";
                insertSearchedElement(); //searched element is inserted in the tree
            } 
        }
    }

        void insertSearchedElement() //function to insert searched element
        {
            
            cout<<"\nResponse :\n1.Yes\n2.No\nChoice :  ";
            cin>>response;
            switch(response)
            {
                case 1 : insert();break;
                case 2 : break;
                default : cout<<"\ninvalid input";
            }

        }

        void inorder(struct node* traverse) //recursive function for Inorder display of tree
        {
            if(traverse == NULL) //loop until traverse is not null
            return;
            
                inorder(traverse->left);
                cout<<traverse->data<<"-->";
                inorder(traverse->right);
        }

        void preOrder(struct node * traverse)// recursive function for preorder sequence
        {
            if(traverse == NULL)
            return;

                cout<<traverse->data<<"-->";
                inorder(traverse->left);
                inorder(traverse->right);

        }

        void postOrder(struct node * traverse)//recursive function for post order sequence
        {
            if(traverse == NULL)
            return;

                inorder(traverse->left);
                inorder(traverse->right);
                cout<<traverse->data<<"-->";
        }
        


        void deleteNode() //delete a particular node from tree
        {
            int value; //value to be deleted 
            cout<<"\nEnter value to be deleted : ";
            cin>>value; //user enters value
            
            traverse = traverse2 = root;
            
            while((traverse->data != value)  && (traverse->right != NULL || traverse->left != NULL)) //same as insertion logic
            {
                // cout<<"\nin 1st while loop";
                // cout<<"\ntraverse 1 is : "<<traverse->data;
                // cout<<"\nTraverse 2 is : "<<traverse2->data;
                
                            
                    while(traverse->data != value && value < traverse->data && traverse->left != NULL) //go to left if value is smaller than root element
                    {
                        traverse2 = traverse;
                        traverse = traverse->left;

                        //  cout<<"\nTraverse 2 is : "<<traverse2;
                        //  cout<<"\ntraverse 1 is : "<<traverse;
                    }

                    while(traverse->data != value && value > traverse->data && traverse->right != NULL)//go to right if value is greater than root element
                    {
                        traverse2 = traverse;
                        traverse = traverse->right;

                         cout<<"\nTraverse 2 is : "<<traverse2;
                         cout<<"\ntraverse 1 is : "<<traverse;
                    }               
            }
        
            
            if(traverse->data != value) //value not present in the tree
            {
                cout<<"\nValue not found bruh";
            }

            else if(value == traverse->data)//value found 
            {
                if(traverse == root)//if value is same as root element
                {
                    free(traverse);
                    root = NULL;
                    cout<<"\nRoot element deleted, NO value present in the tree";
                }

               else if(traverse->left == NULL && traverse->right == NULL)//if value that is being deleted has no child
               { //then do this
                   if(traverse->data < traverse2->data)
                   {
                       free(traverse); //node deleted 
                       traverse2->left = NULL;
                       cout<<"\nNode deleted bruh";
                   }
                   else if(traverse->data > traverse2->data)
                   {
                       free(traverse); //node delted 
                       traverse2->right = NULL;
                       cout<<"\nNode deleted bruh";
                   }
               }

               else if(traverse->left == NULL || traverse->right == NULL)//if any one value is Null
               {//then do this
                   if(traverse->left == NULL && traverse->right != NULL) //if left is null
                   {
                       if(traverse->data < traverse2->data)
                       {
                           traverse2->left = traverse->right;
                           free(traverse);// node deleted 
                           cout<<"\nNode deleted bruh";
                       }
                       else if(traverse->data > traverse2->data)
                       {
                           traverse2->right = traverse->right;
                           free(traverse); // node deleted
                           cout<<"\nNode deleted bruh";
                       }
                   }
                   else if(traverse->left != NULL && traverse->right == NULL)  //if right is null
                   {
                       if(traverse->data < traverse2->data)
                       {
                           traverse2->left = traverse->left;
                           free(traverse);
                           cout<<"\nNode deleted bruh";
                       }
                       else if(traverse->data > traverse2->data)
                       {
                           traverse2->right = traverse->left;
                           free(traverse);
                           cout<<"\nNode deleted bruh";
                       }
                   }
               }
            }
        }
        
    void pointNull() //function that points right and left pointers to null
    {
        newNode->left = NULL; //left pointer
        newNode->right = NULL; //right pointer
    }

    void createNode() //function to create a new node when evoked
    {
        newNode = (struct node*)malloc(sizeof(node)); //dynamically node is created and memory is allocated
        cout<<endl<<"Enter element : ";
        cin>>value; // value to insert into ndoe
        newNode->data = value;
    }
};

int main() //main function
{
    binaryTree bt; //object of the class
    bt.getData();//get data function tha is called into main via object made
    return 0;
}