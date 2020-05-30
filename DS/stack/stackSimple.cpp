#include<iostream>
using namespace std;

class Stack
{
    public:

    int size, *stack, top, value, choice;
    
    void getData()
    {
        top = -1;
        cout<<"\nenter size of stack : ";
        cin>>size;

        stack = new int[size];
        

        

        do
        {
            cout<<"\n1.Push\n2.Pop\n3.display\n4.Exit\n";
            cout<<"\nenter choice : ";
            cin>>choice;

            switch(choice)
            {
                case 1 : push();break;
                case 2 : pop();break;
                case 3 : display();break;
                case 4 : break;
                default : cout<<"\ninvalid input";break;
            }
            
        }
        while(choice != 4);
    }

    void push()
    {
        if(top == size-1)
        {
            cout<<"\nStack is full ";
        }
        else
        {
            top++;
            cout<<"\nenter value to be inserted : ";
            cin>>value;
            stack[top] = value;
            cout<<"\n**INSERTED**";
        }
    }
    void pop()
    {
        if(top == -1)
        {
            cout<<"\nstack is empty";
        }
        else
        {
            cout<<endl;
            cout<<stack[top]," : was **DELETED**  ";
            top--;
        }
    }
    void display()
    {
        if(top == -1)
        {
            cout<<"\nStack is empty";
        }
        else
        {
        cout<<endl;
        for(int i = top; i>=0; i--)
        {
            cout<<"| "<<stack[i]<<" |";
            cout<<endl;
        }
        }
    }

};

int main()
{
    Stack s1;
    s1.getData();
    return 0;
}