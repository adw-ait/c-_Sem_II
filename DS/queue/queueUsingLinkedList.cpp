#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
}*front = NULL, *rear = NULL, *traverse, *newNode, *temp;

class Queue
{
    public:
    int choice, value; 
    void getData()
    {
        
        do
        {
            cout<<"\nChoose :\n 1.Enqueue\n 2.Dequeue\n 3.Display\n 4.Exit\n";
            cout<<"\nChoice : ";
            cin>>choice;

            switch(choice)
            {
                case 1 : Enqueue();break;
                case 2 : Dequeue();break;
                case 3 : display();break;
                case 4 : break;
                default : cout<<"\ninvalid choice bruh\n";
            }
        } while (choice!=4);
    }

    void Enqueue()
    {
        createNode();
        if(rear == NULL)
        {
            newNode->next = NULL;
            rear = newNode;
            front = newNode;
            cout<<"\n**INSERTED**\n";
        }
        else
        {
            rear->next = newNode;
            newNode->next = NULL;
            rear = newNode;

            cout<<"\n**INSERTED**\n";
        }
        
    }
    
    void Dequeue()
    {
        if(front == NULL)
        {
            cout<<"\nQueue is empty bruh";
        }

        else
        {
            if(front->next != NULL)
            {
                temp = front;
                front = front->next;
                free(temp);
                cout<<"\n**DELETED**\n";
            }
            else
            {
                free(front);
                cout<<"\n**DELETED**\n";
                front = NULL;
                rear = NULL;
            }
            
        }

    }

    void display()
    {
        if(front == NULL)
        {
            cout<<"\nStack is empty bruh\n";
        }

        else
        {
            traverse = front;
            cout<<"|  FRONT  |";
            cout<<endl;
            while(traverse->next != NULL)
            {
                cout<<"|  "<<traverse->data<<"  |";
                cout<<endl;
                traverse = traverse->next;
            }
            cout<<"|  "<<traverse->data<<"  |";
            cout<<endl; 
            cout<<"|  REAR  |";
            
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
    Queue q1;
    q1.getData();
    return 0;
}
