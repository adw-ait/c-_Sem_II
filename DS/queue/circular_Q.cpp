#include<iostream>
using namespace std;

class queue
{
    public:
    int front, rear, ele, nol, choice, Q[100];

    void getData()
    {
        front = rear = -1;
        cout<<"enter size of array : ";
        cin>>nol;

    
        do{
            cout<<"\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
            cout<<"choice : ";
            cin>>choice;

            switch(choice)
            {
                case 1 : enqueue();break;
                case 2 : dequeue();break;
                case 3 : display();break;
                case 4 : break;
                default : cout<<"invalid input bro";
            }
        }
            while(choice!=4);
        
        
    }

    void enqueue()
    {
        if((rear == nol-1 && front == -1) || (rear == front - 1))
        {
            cout<<"\nQueue is full\n ";
        }
        else if((rear == -1 && front == -1) || )
        {
            front = (front+1)%nol;
            rear=(rear+1)%nol;
            cout<<"Enter element : ";
            cin>>ele;
            Q[rear] = ele;
            cout<<"element inserted bro"
        }
    }
    void dequeue()
    {
        if(front == -1)
        {
            ele = Q[front];
            cout<<"-----element removed------ :"<<ele;
            front = (front+1)%nol;
        }
        else
        {
            cout<<"\narray is empty bro";
        }
        
        

        
    }
    void display()
    {
        for(int i=front; i<=rear; i++)
        {
            cout<<Q[i]<<" | ";
        }
    }
    
};

int main()
{
    queue q1;
    q1.getData();
}