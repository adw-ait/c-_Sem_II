#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
}*head = NULL, *traverseFront, *traverseBack, *newNode;

class linkedListPalindrome
{
    public:

        int linkedListSize, value;

    void getData()
    {
        cout<<"\nEnter size of linked List : ";
        cin>>linkedListSize;

        for(int i = linkedListSize-1; i>=0; i--)
        {
            createNode();

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


    }

    void isPalindrome()
    {
        head = traverseFront = traverseBack;
        while(traverseBack->next != NULL)
        {
            traverseBack = traverseBack->next;
        }

        while(traverseFront->next != NULL && traverseBack)
    }

     void displayLinkedList()
    {
        if(head == NULL)
        {
            cout<<"\nList is empty bruh";
        }
        else
        {
            traverseFront = head;
            while(traverseFront != NULL)
            {
                cout<<traverseFront->data<<"--> ";
                traverseFront = traverseFront->next;
            }
            cout<<endl;
        }
        
    }

    void createNode()
    {
        newNode = (struct node*)malloc(sizeof(node));
        cout<<endl<<"Enter element :";
        cin>>value;
        newNode->data = value;
    }
};

int main()
{
    linkedListPalindrome llp;
    llp.getData();
    llp.displayLinkedList();
    return 0;
}