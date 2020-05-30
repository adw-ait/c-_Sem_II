#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node * next;
}*head = NULL, *newNode, *traverse;

class arrayToLinkedList
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
        for(int i = arraySize-1; i>=0; i--)
        {
            createNode(array[i]);

            if(head == NULL)
            {
                newNode->next = NULL;
                head = newNode;
            }
            else
            {
                newNode->next = head;
                head = newNode;
            }
        }

        cout<<"\nLinked list made bruh : ";
    }

    void displayLinkedList()
    {
        if(head == NULL)
        {
            cout<<"\nList is empty bruh";
        }
        else
        {
            traverse = head;
            while(traverse != NULL)
            {
                cout<<traverse->data<<"--> ";
                traverse = traverse->next;
            }
            cout<<endl;
        }
        
    }

    void display()
    {
        for(int i = 0; i < arraySize; i++)
        {
            cout<<" | "<<array[i]<<" |";
        }
        cout<<endl;
    }
        
};

int main()
{
    arrayToLinkedList aToL;
    aToL.getData();
    aToL.display();
    aToL.makingLinkedList();
    aToL.displayLinkedList();
    return 0;
}