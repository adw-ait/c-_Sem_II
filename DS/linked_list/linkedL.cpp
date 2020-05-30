#include <iostream>
#include <stdlib.h>
using namespace std;

//this will create a user defined datatype with name node consisting of 
//data and pointer to next object.
struct node
{
    int data;//to store data in the node
    struct node *next;//to store address of next node.
} *list = NULL, *p, *q, *r, *temp, *s;//pointers for node datatype

class singly_linked_list //class for singly linked list
{

public://all the variables functions are public toh the class
    int value, choice;//value : will be used to store value taken from user, choice will be usedd to get one choice from user from given menu
     int key, count = 0; //key : used to get search key from user to search in the linked list, count : to count number of nodes in the list


    void getdata()//to get data from user
    {
        do//to show menu to the user
        {
            cout << "Enter the choice:";//ask user to enter any one choice from below menu
            cout << "\n 1.Insert an element in the begining.\n2 Insert an element at the end \n3.Insert an element before a particular element \n4.Insert an element after a particular element \n5.Display \n6.Delete from begg.\n7.Delete from end.\n8.Delete particular.\n9.EXIT" << endl;// the menu
            cin >> choice;//user enter choice
            switch (choice)//pass user entered choice to check multiple cases that matches
            {
                case 1 : insert_at_beg(); break;//to insert nodee from beginning
                case 2 : insert_at_end();break;//to insert node from end
                case 3 : insert_before_ele(); break;//to insert before particular element
                case 4 : insert_after_ele(); break;//insert after particular element
                case 5 : display();break;//display linked list
                case 6 : deleteFromBegg();break;//delete node from beginning of list
                case 7 : deleteFromEnd();break;//delete node fromm end of the list
                case 8 : deleteParticular();break;//delete a particular element
                // case 9 : sort();break;//sort the linked list in ascending order
                case 10 : reverse();break;//reverse the linked list
                case 11 : countElements();break;//count number of nodes in the list
                case 12: break;//exit from the program
            }
        } while (choice != 12);
    }

    void display()//function to display linked list
    {
        if (list == NULL)//initially if list is null while displaying give error message
        {
            cout << endl<< "List is empty :( :( ";//error message
        }
        else
        {
            q = list;//assign list pointer to another pointer, because list pointer should not leave it's place while traversing
            while (q != NULL)//q pointer will be true until it doesn't point to NULL
            {
                cout << q->data << "--->";//print data of element which is pointed by q
                q = q->next;//move to next node
            }
        }
    }
    void insert_at_beg()//function to insert at the beginning
    {
        createNode();//made a function to create a new node 
        if (list == NULL) //list is empty so create first node
        {
            p->next = NULL;//next pointer of the node will point to NULL
            list = p;//list pointer will point to the new node created
        }
        else//if there are already nodes in the list
        {
            p->next = list;//next pointer of the new node will be pointed by list pointer
            list = p;//list pointer will be now point to new node 
        }
    }

    void insert_at_end()//function to insert node from end
    {
        createNode();//made a function to create a new node 
        if (list == NULL) //list is empty so create first node
        {

            p->next = NULL;//next pointer of the node will point to NULL
            list = p;//list pointer will point to the new node created
        }
        else//if there are already nodes in the list
        {
            q = list;//a temporary pointer will point the list now
            while (q->next != NULL)//until the last element is found this loops goes on
            {
                q = q->next;//move to next node
            }//loop will end if last element is found
            q->next = p;//q points to the last element, so next pointer of last node will point to newnode And
            p->next = NULL;//new node next pointer will now point to NULL, so this becomes the new last node of list
        }
    }

    void insert_before_ele()//function to insert before particular element
    {
        int key;
        if (list == NULL)//list should not be null, if it is then it will give following error messagge
        {
            cout<<endl<< "List is empty :( :(";
        }
        else//the list is not empty
        {

            cout << endl << "enter a key value before which you want to insert new element" << endl;//asks users 
            cin >> key;//insert a search key
            createNode();//made a function to create a new node 
            q = list;//temporary pointer to point the list
            while (q->data != key && q->next != NULL)//several conditions a re checked here, if you know them!! you know them 
            {
                r = q;//temporary pointer that will take the value of previous pointer
                q = q->next;//moved to next node
            }
            if (q->data == key)//if key is found
            {
                if (list->data == key)//if key is 1st value of the list
                {
                    p->next = q;
                    list = p;
                }
                else//if it is not the 1st value of the list
                {
                    r->next = p;
                    p->next = q;
                }
            }
            else//if key is not present in the list
            {
                cout << endl<< "Element not found :( :(";
            }
        }
    }

    void insert_after_ele()//insert after particular element
    {
        if (list == NULL)//if list is null, it will throw error message
        {
            cout << endl<< "List is empty :( :(";//error message
        }
        else//if list is not null
        {
           
            cout << endl<< "enter a key value after which you want to insert new element" << endl;
            cin >> key;//search key entered by user
            createNode();//made a function to create a new node 
            q = list;
        }
        while (q->data != key && q->next != NULL)//several conditions a re checked here, if you know them!! you know them 
        {
            r = q;
            q = q->next;
        }
        if (q->data == key)//the key is found
        {
            if (list->data == key)//if it is first element of the element
            {
            }
            else
                {
                    r->next = p;
                    p->next = q;
                }
            }
            else
            {
                cout << endl<< "Element not found :( :(";
            }
    }


        void deleteFromBegg()//to delete node from beginning
        {
            if(list == NULL)//list should not be null
            {
                cout<<"\nList is empty bruh ";//error message
            }
            else
            {
                p = list;//new node will be now ppointed by list pointer
                q = p->next;//q pointer will point next element of new node
                free(p);//element deleted
                list = q;//list will popint to ne next element of the deleted element
            }
        }

        void deleteFromEnd()//function to delete from end of the list
        {
            if(list==NULL)//if list is null you're not doing this
            {
                cout<<endl<<endl<<"List is empty :( "<<endl;//error message
            }
            else//if list is not empty
                {
                    q=list;
                    while(q->next!=NULL)//go until node's next pointer is null
                    {
                        r=q;
                        q=q->next;
                    }
                    if(q==list)list=NULL;
                    r->next=NULL;
                    free(q);
                }
        }

        void deleteParticular()//deleting a particular element
        {
            if(list==NULL)//if it is null you're not doing if
            {
                cout<<endl<<endl<<"List is empty :( "<<endl;
            }
            else//if list is not null
            {
                cout<<"Enter key elememt you want tot delete: "<<endl;
                cin>>key;//enter search key
                q=list;//temporary pointer pointing list
                while(q->next!=NULL && q->data!=key)//several conditions are checked here
                {
                r=q;
                q=q->next;//move to next node
                }
            
                if(q->data==key)//if key is found
                {
                if(list->data==key)//if it is 1st node
                {
                    list=list->next;
                    free(q);//delete node
                }
                else//if it is not first node
                {
                    r->next=q->next;
                    free(q);

                    }

                    }
            }
        }

        void countElements()//function to count number of nodes
        {
            if(list == NULL)//if it is null then it's not done
            {
                cout<<"\nList is empty";
            }
            else//list is not null
            {
                q = list;
                while(q!=NULL)//loop until 1 q becomes null
                {
                    ++count;
                    q = q->next;
                }
            }

            cout<<"\nCount : "<<count;//print number of nodes
        }

        void reverse()//function to reverse a list
        {
            q = list;//current
            r = NULL;//prev
            s = NULL;//next
            while(q != NULL)//loop until q becomes null
            {
                s = q->next;
                s->next = r;
                r = q;
                q = s;
            }
        }

        void createNode()//function to create a new node, this will be used everywhere where new node needs to be creted
        {
            cout << endl<< "Enter element" << endl;
            cin >> value;
            p = (struct node *)malloc(sizeof(node));//dynamic allocation of new nodes, new node will be assigned memory dynamically
            p->data = value;//data that will be present in the node
        }
};

        int main()//main function of the program
        {
            singly_linked_list s;//object of the above class
            s.getdata();//calling get function of the above class
            return 0;
        }