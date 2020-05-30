#include<iostream>
#include<time.h>
using namespace std;


//***********Creating Nodes for linkedlist, tree, and queue ***********
struct treeNode
{
    int treeData;
    struct treeNode * treeRight;
    struct treeNode * treeLeft;
}*root = NULL;

struct queueNode
{
    int queueData;
    struct queueNode * queueNext;
}*rear = NULL, *front = NULL, *queueNode, *queueTemp;

struct node
{
    int data;
    struct node * next;
}*head = NULL, *traverse, *newNode;

// *********************************************************


// *************** Class for the heapSort ******************

class headSort
{
    // ****************** Public variable declaration ******************
    public:
            int linkedListSize, valueToInsert;

    // ****************************************************************

    //****************** Function to get data from user ******************
    void getData()
    {

        cout<<"\nEnter array size bruh : ";
        cin>>linkedListSize;

        
    }
    // *******************************************************************



//******************Inserting Array Data ******************
    void insertArrayData()
    {

        srand(time(0));

        for(int i = 0; i<linkedListSize; i++)
        {
            //random 2-digit number
            valueToInsert  = rand()%100;
            createNode(valueToInsert);
            
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
        cout<<"\nLinked list made bruh : ";
    }
//*********************************************************




// ***********real game starts here***********

void createNode(int value)
{
    newNode = (struct node*)malloc(sizeof(node));
    newNode->data = value;

}

//****************** New Tree node creation ******************

//************************************************************

//****************** New Queue Node creation ******************
void createQueueNode(int value)
{
    queueNode = (struct queueNode*)malloc(sizeof(queueNode));
    newNode->data = value;
}
//*************************************************************

//****************** Insert into the Queue *********************
void enQueue(int data)
{
    createQueueNode(data);
        if(rear == NULL)
        {
            queueNode->queueNext = NULL;
            rear = queueNode;
            front = queueNode;
            cout<<"\n**INSERTED**\n";
        }
        else
        {
            rear->queueNext = queueNode;
            queueNode->queueNext = NULL;
            rear = queueNode;

            cout<<"\n**INSERTED**\n";
        }
}
//***************************************************************


//****************** Remove From the Queue **********************
        void deQueue()
        {
            if(front->queueNext != NULL)
            {
                queueTemp = front;
                front = front->queueNext;
                free(queueTemp);
                cout<<"\n**DELETED**\n";
            }
            else
            {
                free(front);
                cout<<"\n**DELETED**\n";
                front = NULL;
                rear = NULL;
            }       
        }
//*****************************************************************

//****************** Creating Tree ******************

void createTree()
{
    traverse = head;
    while(traverse != NULL)
    {
        if(traverse == head)
        {
            enQueue(traverse->data);
            traverse = traverse->next;
        }

        else
        {

        }

        deQueue(traverse->data)
        
    }
}

};

int main()
{
    // randArray ra;
    // ra.getData();
    // ra.insertArrayData();
    
    return 0;
}