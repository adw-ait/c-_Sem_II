#include <iostream>
using namespace std;

class doubleEndedQueue
{
    int *queue, arraySize, front, front2, rear, rear2, value;

    public:
    
        void getData()
        {
            int choice;
            cout<<"Enter size of an array : ";
            cin>>arraySize;

            queue = new int[arraySize];

            front = 0;
            rear = -1;

            rear2 = arraySize;
            front2 = arraySize - 1;

            for(int i=0; i<arraySize; i++)
            {
                queue[i]=0;
            }
            
            do{
                cout<<"Select the operation you want to perform : "<<endl;
                cout<<"\n1.Insert at front\n2.Insert at Rear\n3.Delete From Front\n4.Delete From Rear\n5.Display";
                cin>>choice;
                cout<<"\nEnter choice : ";
                switch(choice)
                {
                    case 1 : enqueueAtFront();break;
                    case 2 : enqueueAtRear();break;
                    case 3 : dequeueFromFront();break;
                    case 4 : dequeueFromRear();break;
                    case 5 : display();break;
                    case 6 : break;
                    default: cout<<"Invalid Input";
                }
            }
            while(choice != 6);
        }


        void enqueueAtFront()
        {
            if (rear == rear2 - 1)
            {
                cout<<"\nQueue is full bruh"<< endl;
            }   
            else
            {
                cout<<"Enter element : "<<endl;
                cin>>value;
                rear++;
                queue[rear] = value;
                cout<<"\n Element inserted";
            }
        }


        void enqueueAtRear()
        {

            if (rear2 == rear+1)
            {
                cout<<"\nQueue is full bruh"<<endl;
            }
            else
            {
                cout<<"Enter element : " << endl;
                cin>>value;
                rear2--;
                queue[rear2] = value;
                cout<<"\nElement inserted";
            }  
        }


        void dequeueFromRear()
        {
            if (rear2 > front2)
            {
                cout<<"\nQueue is empty bruh"<<endl;
            }
            else
            {
                value = queue[front2];
                front2--;
                cout<<"\nElement removed";
            }
        }



        void dequeueFromFront()
        {
            if (rear < front)
            {
                cout<<"\nQueue is empty bruh"<<endl;
            }
            else
            {
                value = queue[front];
                front++;
                cout<<"\nElement removed"<<endl;
            }
                
        }


        void display()
        {   
            cout<<"Queue : ";
            for(int i=front; i<=front2; i++)
            {
                cout<<queue[i]<<" ";
            }
            cout<<endl; 
        }
};


int main(){
    doubleEndedQueue dQ;
    dQ.getData();

    return 0;
}