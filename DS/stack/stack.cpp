#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
}*top = NULL, *newNode, *temp, *traverse;



class stack
{
    public:
    int choice, value; 
    void getData()
    {
        
        do
        {
            cout<<"\nChoose :\n 1.Push\n 2.Pop\n 3.Display\n 4.Exit\n";
            cout<<"\nChoice : ";
            cin>>choice;

            switch(choice)
            {
                case 1 : push();break;
                case 2 : pop();break;
                case 3 : display();break;
                case 4 : break;
                default : cout<<"\ninvalid choice bruh\n";
            }
        } while (choice!=4);
    }

    void push()
    {
        createNode();
        if(top == NULL)
        {
            newNode->next = NULL;
            cout<<"\n**INSERTED**\n";
        }
        else
        {
            newNode->next = top;
            top = newNode;
            cout<<"\n**INSERTED**\n";
        }
        top = newNode;
    }

    void pop()
    {
        if(top == NULL)
        {
            cout<<"\nStack is empty bruh\n";
        }
        else
        {
           temp = top;
           top = top->next;
           free(temp);
           cout<<"\n**DELETED**\n";
        }
        
    }

    void display()
    {
        if(top == NULL)
        {
            cout<<"\nStack is empty bruh\n";
        }
        else
        {
            cout<<endl;
            traverse = top;
            while(traverse->next != NULL)
            {
                cout<<"|  "<<traverse->data<<"  |";
                cout<<endl;
                traverse = traverse->next;
            }
            cout<<"|  "<<traverse->data<<"  |";
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
    stack st;
    st.getData();
    return 0;
}

