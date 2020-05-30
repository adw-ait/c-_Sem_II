#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
}*list = NULL, *p, *q, *temp, *r;

class circular
{
    public:
    int choice, value;

    void getData()
    {
        do
        {
            cout<<"\nOptions\n1.Insert At beginning\n2.Insert At the end\n3.Insert before particular element\n4.Insert after particular element\n5.Delete from beginning\n6.Delete from end\n7.Delete a particular element\n8.Count elements\n9.Display\n10.Exit\n";
            cout<<"\nChoice : ";
            cin>>choice;
            switch(choice)
            {
                case 1 : insertAtBeg();break;
                case 2 : insertAtEnd();break;
                case 3 : insertBefore();break;
                // case 4 : insertAfter();break;
                // case 5 : deleteFromBeg();break;
                // case 6 : deleteFromEnd();break;
                // case 7 : deleteParticular();break;
                // case 8 : count();break;
                case 9 : display();break;;
                case 10 : break;
                default : cout<<"Invalid Input bruh";

            }
        }
         while(choice!=10);
    }

    void insertAtBeg()
    {
        createNode();
        if(list == NULL)
        {
            
            p->next = p;
            list = p;
            
        }
        else
        {
            
            q = list;
            while(q->next != list)
            {
                q = q->next;
            }
            q->next = p;
            p->next = list;
            list = p;
        }
    }

    void insertAtEnd()
    {
        createNode();
        if(list == NULL)
        {
            p->next = p;
            list = p;
        }
        else
        {
            q = list;
            while(q->next != list)
            {
                q = q->next;
            }
            q->next = p;
            p->next = list;
        }   
    }

    void insertBefore()
    {
        int key;
        if(list == NULL)
        {
            cout<<"\nlist is empty bruh";
        }
        else
        {
            q = list;
            cout<<"Enter key : ";
            cin>>key;
            createNode();
            while(q->data != key && q->next != list)
            {
                r = q;
                q = q->next;
            }
            if(q->data == key)
            {
                if(q == list)
                {
                    q = list;
                    while(q->next != list)
                        {
                            q = q->next;
                        }
                    q->next = p;
                    p->next = list;
                    list = p;
                }
            
                else
                {
                    q = p->next;
                    r->next = p;    
                }
            }
            else
            {
                cout<<"\nelement not found bruh";
            } 
        }
    }


    

     void display()
    {
        if (list == NULL)
        {
            cout <<endl<< "List is empty";
        }
        else
        {
            q = list;
            while (q->next != list)
            {
                cout << q->data << "--->";
                q = q->next;
            }
            cout<<q->data,"--->";
        }
    }

    void createNode()
    {
        p = (struct node*)malloc(sizeof(node));
        cout<<endl<<"Enter element :";
        cin>>value;
        p->data = value;
    }

};

int main()
{
    circular cl;
    cl.getData();
    return 0;
}