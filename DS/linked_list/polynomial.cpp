#include<iostream>
using namespace std;

struct node
{
    int coeff;
    int expo;
    struct node *next; 
}*eqP = NULL, *p, *r, *s,*q, *temp, *eqQ = NULL, *resultR = NULL;

class polynom
{
    public:

    int choice, value;

    void getData()
    {
        do{
            cout<<"\n\nChoose one : ";
            cout<<"\n1.Enter equation one\n2.Enter equation two\n3.Add\n4.exit\n";
            cout<<"\nChoice : ";
            cin>>choice;

            switch(choice)
            {
                case 1 : equation1();break;
                case 2 : equation2();break;
                case 3 : addition();break;
                case 4 : break;
                default : cout<<"Invalid input";break;
            }
        }
        while(choice!=4);
    }

    void equation1()
    {
        int nOn;
        cout<<"\nEnter number of nodes : ";
        cin>>nOn;
        
        for(int i = 0; i<=nOn;i++)
        {
                createNode();

                if(eqP == NULL)
                {
                     p->next = NULL;
                     eqP = p;
                }

                else
                {
                    q = eqP;
                    while(q->next != NULL)
                    {
                        q = q->next;
                    }
                    q->next = p;
                    p->next = NULL;
                }
        }
        
    }

    void equation2()
    {
        int nOn;
        cout<<"\nEnter number of nodes : ";
        cin>>nOn;
        
        for(int i = 0; i<=nOn;i++)
        {
                createNode();

                if(eqQ == NULL)
                {
                     p->next = NULL;
                     eqQ = p;
                }

                else
                {
                    q = eqQ;
                    while(q->next != NULL)
                    {
                        q = q->next;
                    }
                    q->next = p;
                    p->next = NULL;
                }
        }
    }

    void addition()
    {

        while(eqP->next && eqQ->next)
        {
            if(eqP->expo > eqQ->expo)
            {
                resultR->coeff = eqP->coeff;
                resultR->expo = eqP->expo;
                eqP
            }
        }

    }

    void createNode()
    {
        p = (struct node*)malloc(sizeof(node));
        cout<<endl<<"Enter coeff :";
        cin>>value;
        p->coeff = value;

        cout<<endl<<"Enter exponent : ";
        cin>>value;
        p->expo = value;
    }

       
};

int main()
{
    polynom poly;
    poly.getData();
    return 0;
}



