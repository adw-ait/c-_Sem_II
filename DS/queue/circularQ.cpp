#include<iostream>
using namespace std;

class circularQ
{
    public:
    int front, rear, size, *Q, choice, ele;

    

    void getData()
    {
        front = rear = -1;
        
        cout<<"\nenter Q size : ";
        cin>>size;

        Q = new int[size];

        do{
            cout<<"\nOperations : \n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit";
            cout<<"\nenter your choice : ";
            cin>>choice;
            switch(choice)
            {
                case 1 : enQueue();break;
                case 2 : deQueue();break;
                case 3 : display();break;
                case 4 : break;
                default : cout<<"\nwrong input bro ";break;
            }
        }
        while(choice != 4);
    }

    void enQueue()
    {
        if((front == rear + 1 ) || front == 0 && rear == size-1)
        {
            cout<<"\narray is full bro";
        }
        else if(front == -1)
        {
            front = 0;
            rear = (rear+1)%size;
            cout<<"\nenter element : ";
            cin>>ele;
            Q[rear] = ele;

        }
        else
        {
            rear = (rear+1)%size;
            cout<<"\nenter element : ";
            cin>>ele;
            Q[rear] = ele;
        }
        

    }

    void deQueue()
    {
        if(rear == -1 && front == -1)
        {
            cout<<"\narray is empty";
        }

        else if(rear == rear)
        {
            front = rear = -1;
        }
        else
        {
            // ele = Q[front];
            front = (front + 1) % size;
            cout<<"\narray deleted";
        }
        
    }

    void display()
    {
        cout<<endl;
        if(front == -1 && rear == -1)
        {
            cout<<"\narray is empty";
        }
        else
        {
            for(int i = (front+1)%size; i<rear; i++)
            {
                cout<<"| "<<Q[i]<<" |";
            }
        }
    }

};

int main()
{
    circularQ cQ;
    cQ.getData();
    return 0;
}