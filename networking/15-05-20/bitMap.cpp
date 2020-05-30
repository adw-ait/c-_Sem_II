#include<iostream>
#include<stdio.h>
#include<conio.h>
 
void main()
{
 
int i,j,k;
 
int sn;
int st[20];
cout<<"\n How many stations: ";
cin>>sn;
char op;
do
{
cout<<"\n Enter status of stations";
for (i=0;i<sn;i++)
{
    cout<<"\n Enter status of station "<<i+1<<" : ";
    cin>>st[i];
}
//Print ready stations
for (i=0;i<sn;i++)
{
    if(st[i]==1)
    {
        cout<<"\n Station "<<i+1<<" is ready to transmit";
    }
}
cout<<"\n Repeat? Press Y :";
cin>>op;
}
while(op=='y' || op=='Y');
getch();
}