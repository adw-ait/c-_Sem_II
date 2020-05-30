#include<iostream>
using namespace std;

class prodConsm
{
    public:

    int mutex = 1, full = 0, empty, item = 0;

    void menu()
    {
        int choice;
        do
        {
            cout<<"\nEnter your choice\n 1.Produce\n 2.Consume\n 3.Exit";
            cout<<"\nChoice : ";
            cin>>choice;

            switch (choice)
            {
            case 1 : produce();break;
            case 2 : consume();break;    
            case 3 : break;
            default: cout<<"Invalid input";
                break;
            }
        } while (choice!=3);
        
    }

    void produce()
    {
        if(mutex == 1 && empty != 0)
        {
            empty = wait(empty);
            // cout<<"\nempty after wait : "<<empty;
            mutex = wait(mutex);
            // cout<<"\nmutex after wait : "<<mutex;

            //insertion inside buffer
            item++;
            cout<<"\nproduced an item";

            mutex = signal(mutex);
            // cout<<"\nmutex after signal : "<<mutex;
            full = signal(full);
            // cout<<"\nfull after signal : "<<full;
        }
        else
        {
            cout<<"\nBuffer is full";
        }
        
    }

    void consume()
    {
         if(mutex == 1 && full != 0)
        {
            full = wait(full);
            // cout<<"\nfull after wait : "<<full;
            mutex = wait(mutex);
            // cout<<"\nmutex after wait :"<<mutex;

            //insertion inside buffer
            item--;
            cout<<"\nRemoved from buffer";

            mutex = signal(mutex);
            // cout<<"\nmutex after signal : "<<mutex;
            empty = signal(empty);
            // cout<<"\nempty after signal : "<<empty;

            cout<<"\nConsumed the item";
        }
        
        else
        {
            cout<<"\nBuffer is empty";
        }
        

    }
    
    int wait(int S)
    {
        while(S<=0);
        --S;
        return S;
    }

    int signal(int S)
    {
        ++S;
        return S;
    }

    prodConsm(int tempBufferSize)
    {
      empty = tempBufferSize ;
    }
};



int main()
{
    int  bufferSize;
    cout<<"\nEnter size of buffer : ";
    cin>>bufferSize;

    prodConsm pC(bufferSize);
    pC.menu();
    return 0;
}