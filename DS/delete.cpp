#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
}*head = NULL,*traverse, *newNode, *temp, *traverse2;

class linkedList
{
    public:
    int size, value, deleteNum;

    void getData()
    {
        cout<<"\nEnter length of linked list : ";
        cin>>size;

        //create linkedList
        for(int i = 0; i<size; i++)
        {
            createNode();

            if(head == NULL)
            {
                newNode->next = NULL;
                head = newNode;
                
                
            }
            else
            {
                newNode->next = head;
                head = newNode;
            }

            
        }
        
        // display();
        deleteOccurance();

    }

    void deleteOccurance()
    {
        cout<<"\nEnter number to be deleted : ";
        cin>>deleteNum;

        traverse2 = traverse = head;

        while(traverse->next != NULL)
        {

            if(traverse->data == deleteNum)
            {
                if(head->data == deleteNum)
                {
                    // cout<<"\nim here bruh";
                    temp = head;
                    head = head->next;
                    traverse2 = traverse = head;
                    free(temp);
                    
                }
                else if(traverse->next == NULL)
                {
                    cout<<"\nim here bruh";
                    temp = traverse;
                    traverse = traverse2;
                    traverse2->next =NULL;
                    free(temp);
                }
                else
                {
                    cout<<"\nim here in else";
                    temp = traverse;
                    traverse2->next = traverse->next;
                    traverse = traverse2->next;
                    free(temp);
                    
                }
            }
            else if(traverse->data != deleteNum && traverse->next != NULL)
            {
                traverse2 = traverse;
                traverse = traverse->next;
            }
            else if(traverse->data != deleteNum && traverse->next == NULL)
            {
                cout<<"\nElement not present in the list";
            }
            

        }
        

        
        
        
    }

    void display()
    {
        if(head == NULL)
        {
            cout<<"\nList is empty";
        }
        else
        {
            traverse = head;
            while(traverse != NULL)
            {
                cout<<traverse->data<<" -->";
                traverse = traverse->next;
            }
        }
    }

    void createNode()
    {
        newNode = (struct node*)malloc(sizeof(node));
        cout<<endl<<"Enter element : ";
        cin>>value;
        newNode->data = value;
    }
};

int main()
{
    linkedList l;
    l.getData();
    // l.display();

    return 0;
}