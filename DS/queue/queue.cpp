#include<iostream>
using namespace std;

class queue
{
    public:
    int front, rear, ele, nol, choice, Q[100];

    void getData()
    {
        front = 0; rear = -1;
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
        if(rear == nol-1)
        {
            cout<<"\nQueue is full\n ";
        }
        else
        {
            rear++;
            cout<<"Enter element : ";
            cin>>ele;
            Q[rear] = ele;
        }
    }
    
    void dequeue()
    {
        if(front == nol-1)
        {
           cout<<"\narray is empty";
        }
        else
        {
            // ele = Q[front];
            cout<<"-----element removed------ :"<<Q[front];
            front++;
            
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