#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
}*list = NULL, *traverse, *temp, *newNode, *traverse2, *list2 = NULL, *traverse3;


class evenAtBeginning
{
    public:
    int choice, value;
    void getData()
    {
        

      do
        {
            cout<<"\nChoose :\n 1.Insert\n 2.Even at beginning\n 3.Display\n 4.Exit\n";
            cout<<"\nChoice : ";
            cin>>choice;

            switch(choice)
            {
                case 1 : insert();break;
                case 2 : evenSort();break;
                case 3 : display();break;
                case 4 : break;
                default : cout<<"\ninvalid choice bruh\n";
            }
        } while (choice!=4);
        
    }

    void insert(){

        createNode();
        if (list == NULL)
        {
            list = newNode;
            newNode ->next = NULL;
        }
        else
        {
            newNode->next = list;
            list = newNode;
        }
        
        
    }

    void evenSort(){

        traverse3 = list2;

        traverse2 = traverse = list;

        while (traverse != NULL)
        {
            if(traverse->data % 2 == 0 && traverse->data != 0)
            {
                temp = traverse;
                traverse = traverse->next;
                traverse2->next = traverse;

                if(list2 == NULL)
                {
                    list2 = temp;
                    temp->next = NULL;
                }
                else
                {
                    while(traverse3->next != NULL)
                    {
                        traverse3 = traverse3->next;
                    }
                    traverse3->next = temp;
                    temp->next = NULL;
                }
            }
            else
            {
                traverse2 = traverse;
                traverse = traverse -> next;
            }
        }
        
        
        
    }
    void display(){
        if(list == NULL)
        {
            cout<<"\nList is empty";
        }
        else
        {
            traverse = list2;
            while (traverse != NULL)
            {
                cout<<traverse -> data<<" --> ";
                traverse = traverse->next;
            }
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
    evenAtBeginning evb;
    evb.getData();
    return 0;
}