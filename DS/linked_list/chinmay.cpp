#include<iostream>                                                                                                                                                                                                                                                                                                                                                                                                                #include <iostream>
// #include <stdlib.h>
using namespace std;


struct node
{
    int data;
    struct node *left;
    struct node *right;
} *list = NULL, *p, *q, *r, *s;

class doble{

public:
    int value, choice;
    void getdata()
    {
        do
        {
            cout << "Enter the choice:";
            cout << "\n 1.Insert an element in the begining.\n2 Insert an element at the end \n3.Insert an element before a particular element \n4.Insert an element after a particular element\n5.delete at begning\n6.delete at end \n7.Display \n 8.EXIT" << endl;
            cin >> choice;
            switch (choice)
            {
            case 1:insert_at_beg();
                break;

            case 2:
                insert_at_end();
                break;

            case 3:
                insert_before_ele();
                break;

            case 4:
                insert_after_ele();
                break;
            case 5:
            	delete_at_beg();
            	break;

            case 6:delete_at_end();
            break;
            case 7:
                display();
                break;
            case 8:
                break;
            }
        } while (choice != 8);
    }

 	void display()
    {
        if (list == NULL)
        {
            cout << endl
                 << "List is empty :( :( ";
        }
        else
        {
            q = list;
            while (q != NULL)
            {
                cout << q->data << "--->";
                q = q->right;
            }
      }
	}

	void insert_at_beg()
	{
		p = (struct node *)malloc(sizeof(node));
	        cout << endl<< "Enter element" << endl;
	        cin >> value;
	        p->data = value;
		if(list == NULL)
		{
			p->left=NULL;
			p->right=NULL;
			list = p;
		}
		else
		{
			p->right=list;
			p->left=NULL;
			list->left=p;
			list=p;
		}

		
	}
	void insert_at_end()
	{
		p = (struct node *)malloc(sizeof(node));
	        cout << endl<< "Enter element" << endl;
	        cin >> value;
	        p->data = value;
		if(list==NULL)
		{
			p->left=NULL;
			p->right=NULL;
			list=p;
			
		}
		else
		{
			q=list;
			while(q->right !=NULL)
			{
				q=q->right;
			}
			q->right=p;
			p->left=q;
			p->right=NULL;
			
		}

		
	}
	void insert_before_ele()
	{
		int key;
        if (list == NULL)
        {
            cout << endl
                 << "List is empty :( :(";
        }
        else
        {

            cout << endl
                 << "enter a key value before which you want to insert new element" << endl;
            cin >> key;
            cout << endl
                 << "Enter element" << endl;
            cin >> value;
            p = (struct node *)malloc(sizeof(node));
            p->data = value;
            q = list;
			 while (q->data != key && q->right != NULL)
            {
                r = q;
                q = q->right;
            }
			if (q->data == key)
            {
                if (list->data == key)
                {
                    p->right = q;
					p->left = NULL;
					q->left = p;
					list = p;
				}
                else
                {
                    r->right = p;
					p->left = r;
					p->right = q;
					q->left = p;
				}
			}
		}
	}
	
	void insert_after_ele()
	 {
        int key;
        if (list == NULL)
        {
            cout << endl
                 << "List is empty :( :(";
        }
        else
        {

            cout << endl
                 << "enter a key value after which you want to insert new element" << endl;
            cin >> key;
            cout << endl
                 << "Enter element" << endl;
            cin >> value;
            p = (struct node *)malloc(sizeof(node));
            p->data = value;
            q = list;
        }
        while (q->data != key && q->right != NULL)
        {
            q = q->right;
        }
        if (q->data == key)
        {

            p->right = q->right;
            q->right->left=p;
			p->left = q;
			q->right = p;
		}
		
	}

	void delete_at_beg()
	{
		if(list==NULL)
		{
			cout << "empty";
		}
		else
		{
			q = list;
			q = q->right;
			free(list);
			list = q;
		}
	}
	
		void delete_at_end()
	{
		if(list==NULL)
		{
			cout << "empty";
		}
		else
		{
			q=list;
			while(q->right!=NULL)
			{
				r=q;
				q=q->right;
			}
			r->right=NULL;
			free(q);
		}
	}
	


};

int main()
{
    doble s;
    s.getdata();
    return 0;
}