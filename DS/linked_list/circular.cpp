#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
  int data;
  struct node *next;
};
class list
{
  int choice,value,key,counter;//,data;
  struct node *list=NULL,*p,*q,*r,*s,*temp,*t;
  public:
  void get()
  {
      do
      {
      cout<<endl<<endl<<"/----Functions of link list----/"<<endl;
      cout<<"1.Insertion at beginning\n2.Insertion at back\n3.Insertion after perticular element\n4.Insertion before perticular element";
      cout<<"\n5.Deletion at beginning\n6.Deletion at end\n7.delete pert element\n8.Display\n9.Sort";
      cout<<"\n10.Reverse\n11.Count\n12.Exit"<<endl;
      cin>>choice;
    
          switch(choice)
          {
              case 1:insertion_beginning();break;
              case 2:insertion_end();break;
              case 3:insertion_after_pert();break;
              case 4:insertion_before_pert();break;
              case 5:deletion_beginning();break;
              case 6:deletion_end();break;
              case 7:delete_pert_ele();break;
              case 8:display();break;
              case 9:sort();break;
              case 10:reverse();break;
              case 11:count();break;
              case 12:exit(0);
              default:cout<<"Enter proper choice :( :("<<endl;
          }
      }while(choice!=12);
  }
  void insertion_beginning()
  {
      cout<<"Enter value: ";
      cin>>value;
      p=(struct node*)malloc(sizeof(node));
      p->data=value;
      if(list==NULL)
      {
          p->next=p;
          list=p;
      }
      else
      {
          p->next=list;
          q=list;
          while (q->next!=list)
          {
              q=q->next;
          }
          q->next=p;
         
          list=p;
      }
  }
  void insertion_end()
  {
      cout<<"Enter value: ";
      cin>>value;
      p=(struct node*)malloc(sizeof(node));
      p->data=value;
      if(list==NULL)
      {
          p->next=p;
          list=p;
      }
      else
      {
 
          q=list;
          while(q->next!=list)
          {
              q=q->next;
          }
          q->next=p;
          p->next=list;
      }
  }
  void insertion_after_pert()
  {
      cout<<"Enter value: ";
      cin>>value;
      cout<<"Enter key element after you want to enter element: ";
      cin>>key;
      p=(struct node*)malloc(sizeof(node));
      p->data=value;
      if(list==NULL)
      {
          cout<<endl<<endl<<"List is empty :( "<<endl;
      }
      else
      {
          q=list;
          while(q->next!=list && q->data!=key)
          {
              r=q;
              q=q->next;
          }
          
          r=q->next;
          if(q->data==key)
          {
              q->next=p;
              p->next=r;
           }
           else if (list->data==key)
           {
               q->next=p;
              p->next=list;
           }
           
          else
          {
              cout<<"Key not found:( "<<endl;
          }
       }
   }
  void insertion_before_pert()
  {
      cout<<"Enter value: ";
      cin>>value;
      cout<<"Enter key element before you want to enter element: ";
      cin>>key;
      p=(struct node*)malloc(sizeof(node));
      p->data=value;
      if(list==NULL)
      {
          cout<<endl<<endl<<"List is empty :( "<<endl;
      }
      else
      {
          q=s=list;
          while(q->next!=list && q->data!=key)
          {
              r=q;
              q=q->next;
          }
          if(q->data==key && list->data!=key)
          {
              r->next=p;
              p->next=q;
          }
          else if(list->data==key)
          {
              while(s->next!=list)
              {
                  s=s->next;
              }
              p->next=list;
              s->next=p;
              list=p;
           }
          else
          {
              cout<<"Key not found:( "<<endl;
          }
      }
   }
  void sort()
  {
      q=list;
       if(list==NULL)
      {
          cout<<endl<<endl<<"List is empty :( "<<endl;
      }
      else{
      while(q->next!=list)
      {
      r=q->next;
      while(r!=list)
      {
          if(q->data>r->data)
          {
              int temp;
              temp=q->data;
              q->data=r->data;
              r->data=temp;
             
          }r=r->next;
      }
      q=q->next;
      }
  }
  }
  void reverse()
  {
      q=s=list;
      temp=NULL;
      r=q->next;
       if(list==NULL)
      {
          cout<<endl<<endl<<"List is empty :( "<<endl;
      }
      else{
      while(r!=list)
      {
          temp=q;
          q=r;
          r=q->next;
          q->next=temp;
      }list=q;
      s->next=list;
      }
  }
  void count()
  {
      counter=0;
      q=list;
      if(list==NULL)
      {
          cout<<endl<<endl<<"List is empty :( "<<endl;
      }
      else{
          counter =1;
      while(q->next!=list)
      {
          counter++;
          q=q->next;
      }
      }
      cout<<"\nLink list contains "<<counter<<"  elements :)";
  }
  void deletion_beginning()
  {
  if(list==NULL)
  {
      cout<<endl<<endl<<"List is empty :( "<<endl;
    
  }
  else
  {
      p=r=list;
      if(p->next==list)
      {
          list=NULL;
          free(p);
      }
      else
      {
          q=p->next;
      while(r->next!=list)
      {
          r=r->next;
      }
      r->next=q;
      list=q;
      free(p);
       }
  }
  }
  void deletion_end()
  {
      if(list==NULL)
      {
      cout<<endl<<endl<<"List is empty :( "<<endl;
      }
      else
      {
          q=list;
          while(q->next!=list)
          {
              r=q;
              q=q->next;
          }
          if(q==list)list=NULL;
          r->next=list;
          free(q);
      }
  }
  void delete_pert_ele()
  {
      if(list==NULL)
      {
      cout<<endl<<endl<<"List is empty :( "<<endl;
      }
      else
      {
          cout<<"Enter key elememt you want to delete: "<<endl;
          cin>>key;
          q=s=list;
          while(q->next!=list && q->data!=key)
          {
              r=q;
              q=q->next;
          }
          if(q->data==key)
          {
              if(list->data==key)
              {
                  deletion_beginning();
              }
              else
              {
                  r->next=q->next;
                  free(q);
              }
            
          }
          else
          {
              cout<<"Key not found:( "<<endl;
          }
      }
  }
  void display()
  {
      p=list;
      if(list==NULL)
      {
          cout<<endl<<endl<<"List is empty :( "<<endl;
      }
       else if(p->next==list)
       {
           cout<<p->data<<"--->"<<"\t";
 
       }
      else
      {
          while(p->next!=list)
          {
              cout<<p->data<<"--->"<<"\t";
              p=p->next;
          }
          cout<<p->data<<"--->"<<"\t";
          }
  }
};
int main()
{
list obj;
obj.get();
 return 0;
}
