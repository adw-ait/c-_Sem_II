#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node * left;
    struct node * right;
}*root = NULL, *newNode, *traverse;

class balancedBinaryTree
{
    public:
            int arraySize, *array;

    void getData()
    {
        cout<<"\nEnter size of array : ";
        cin>>arraySize;

        array = new int[arraySize];

        for(int i=0; i<arraySize; i++)
        {
            cout<<"\nenter element "<<i<<" : ";
            cin>>array[i];
        }
    }

    void createNode(int value)
    {
        newNode = (struct node *)malloc(sizeof(node));
        newNode->data = value;
    }

    void makingLinkedList()
    {
        for(int i = 0; i<arraySize; i++)
        {
            createNode(array[i]);
            if(root == NULL)
            {
              root = newNode;
              pointNull();   
            }

            else
            {
                
            }
            
        }
    }

    

    void pointNull()
    {
        newNode->left = newNode->right = NULL;
    }
        
};

int main()
{
    balancedBinaryTree bbt;
    
    return 0;
}