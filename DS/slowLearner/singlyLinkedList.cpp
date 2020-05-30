#include<iostream>
using namespace std;

struct node 
{
    int data;
    struct node * next;
}*list = NULL, *traverse, *temp, *traverse2, *newNode;

class singlyLinkedList
{


};

void createNode()
{
    newNode = (struct node *)malloc(sizeof(node));
    cout<<"\nEnter element : ";
    cin>>value;
    

}

int main()
{
    singlyLinkedList ll;
    return 0;
}