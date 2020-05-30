#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev; 
}*list = NULL, *p, *r, *s,*q, *temp;

class doubly
{
    public:

    int value, choice;

    void getData()
    {
        do
        {
            cout<<"\n\nChoose one : ";
            cout<<"\n1.Insert @ beginning\n2.Insert @ ending\n3.Insert after particular element\n4.Insert before particular element\n5.Display\n6.Delete from beginning\n7.Delete from end\n8.Delete particular element\n9.Count Node\n10.reverse\n11.Exit\n";
            cout<<"\nChoice : ";
            cin>>choice;
            
            switch(choice)
            {
                case 1: insertAtbeg();break;
                case 2: insertAtend();break;
                case 3: insertAfter();break;
                case 4: insertBefore();break;
                case 5: display();break;
                case 6: deleteFromBeg();break;
                case 7: deleteFromEnd();break;
                case 8: deleteElement();break;
                case 9: nodeCount();break;
                case 10: reverseLinkedList();break;
                case 11: break;
                default: cout<<"\ninvalid input bruh";
            }
        }
        while(choice!=11);
    }

    void insertAtbeg()
    {
       createNode();

        if(list == NULL)
        {
            firstNode();
        }
        else
        {
            p->next = list;
            list->prev = p;
            p->prev = NULL;
            list = p;
        }
    }

    void insertAtend()
    {
        createNode();

        if(list == NULL)
        {
            firstNode();
        }
        else
        {
            q = list;
            while(q->next != NULL)
            {
                q = q->next;
            }
            q->next = p;
            p->prev = q;
            p->next = NULL;
        }
    }

    void insertBefore()
    {
        int key;
        if(list == NULL)
            {
                cout<<"\nlist is empty";
            }
        else
        {
            cout<<"\ninsert before : ";
            cin>>key;
            createNode();
            q = list;
            while(q->data != key && q->next != NULL)
            {
                r = q;
                q = q->next;
            }

            if(q->data == key)
                if (list->data == key)
                {
                    p->next = q;
                    list = p;
                }

            else    
            {
                r->next = p;
                p->prev = r;
                p->next = q;
                q->prev = p;
            }
            else
            {
                cout<<"element not found bruh";
            }
        }
    }

    void insertAfter()
    {
        int key;
        
        if(list == NULL)
        {
            cout<<"list is empty";
        }
        else
        {
            cout<<"\nInsert after : ";
            cin>>key;
            createNode();
            q = list;
            while (q->data != key && q->next != NULL)
            {
                q = q->next;
            }
            if(q->data == key)
            {
                if(q->next == NULL)
                {
                    p->next = q->next;
                    p->prev = q;
                    q->next = p;

                }
                else
                {

                p->next = q->next;
                q->next->prev = p;
                p->prev = q;
                q->next = p;
                }
            }
            else
            {
                cout<<"element not found bruh";
            }
            
        }
        
    }

    void deleteFromBeg()
    {
        if(list == NULL)
        {
            cout<<"\nList is empty bruh";
        }
        else
        {
            q = list;
			q = q->next;
			free(list);
			list = q;
        }
    }

    void deleteFromEnd()
    {
        if(list == NULL)
        {
            cout<<"\nlist is empty bruh\n";
        }
        else
        {
            q = list;
            while(q->next != NULL)
            {
                q = q->next;
            }
            if(list->next == NULL)
            {
                list = NULL;
                free(q);
            }
            else
            {
            q->prev->next = NULL;
            free(q);
            }
        }

    }

    void deleteElement()
    {
        int key;
        if(list == NULL)
        {
            cout<<"\nList is empty bruh\n";
        }
        else
        {
            cout<<"\nEnter element to delete : ";
            cin>>key;
            q=list;
            while(q->data != key && q->next != NULL)
            {
                q=q->next;
            }
            if(q->data == key)
            {
                if(list->next == NULL)
                {
                    list = NULL;
                    free(q);
                }
                
                else if(q->next == NULL)
                {
                    q->prev->next = NULL;
                    free(q);
                }

                else if(q == list)
                {
                    q = q->next;
			        free(list);
			        list = q;
                }

                else 
                {
                    q->prev->next = q->next;
                    q->next->prev = q->prev;
                    free(q);
                }
            }
            else
            {
                cout<<"\nElement not found bruh\n";
            }
        }
    }

    void nodeCount()
    {
        q = list;
        int count = 1;
        if(list == NULL)
        {
            cout<<"list is empty";
        }
        else
        {
        while (q->next != NULL)
        {
            count++;
            q=q->next;
        }
        cout<<"\nNos of nodes : "<<count;
        }
    }

    void reverseLinkedList()
    {
        struct node * last;
        if(list == NULL)
        {
            cout<<"list is empty";
        }
        else
        {
            q = list;
            while(q->next != NULL)
            {
                q = q->next;
            }
            
            last = q;
            
            while(q!=list)
            {
                cout<< q->data <<"-->";
                q = q->prev;
            }
            cout<< q->data <<"-->";
            cout<<endl;
        }

    }

    void display()
    {
        if (list == NULL)
        {
            cout <<"\nList is empty";
        }
        else
        {
            q = list;
            while (q != NULL)
            {
                cout << q->data << "--->";
                q = q->next;
            }
        }
    }

    void firstNode()
    {
        p->prev = NULL;
        p->next = NULL;
        list = p;
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
    doubly db;
    db.getData();
    return 0;
}