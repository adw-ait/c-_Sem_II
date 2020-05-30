
#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
}*rear = NULL, *front = NULL, *delt, *newNode, *displayTraverse;


class circularQueue
{
    public:
    int value, choice;

    void getData()
    {
        do
        {
            cout<<"\nChoose :\n 1.Enqueue\n 2.Dequeue\n 3.Display\n 4.Exit\n";
            cout<<"\nChoice : ";
            cin>>choice;

            switch(choice)
            {
                case 1 : enqueue();break;
                case 2 : dequeue();break;
                case 3 : display();break;
                case 4 : break;
                default : cout<<"\ninvalid choice bruh\n";
            }
        } while (choice!=4);
    }
        
    

    void enqueue()
    {
        createNode();

        if(front == NULL)
        {
            front = newNode;
            rear = newNode;
            
        }
        else
        {
            newNode->next = front;
            front = newNode;
            
        }

        rear->next = front;
        cout<<"\n**INSERTED**\n";
    }

    void dequeue()
    {
        if(front == NULL)
        {
            cout<<"\nQueue is empty";
        }
        else
        {
            if(front == rear)
            {
                delt = front;
                front = NULL;
                rear = NULL;
                free(delt);
                cout<<"\n**DELETED**\n";
            }
            else
            {
                delt = front;
                front = front->next;
                rear->next = front;
                free(delt);
                cout<<"\n**DELETED**\n";
            }
            
        }
    }

    void display()
    {
        if(front == NULL)
        {
            cout<<"\nQueue is empty";
        }
        else
        {
            displayTraverse = front;
            while (displayTraverse->next != front)
            {
                cout<<displayTraverse->data<<" ==> ";
                displayTraverse = displayTraverse->next;
            }
            cout<<displayTraverse<<" ==> ";
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
   circularQueue cq;
   cq.getData();
   return 0;
}
