#include<iostream>
using namespace std;

class modulo
{
    public:
    int first, second, result, choice;

    void option()
    {
    do{
        cout<<"\n1. modulo\n2. Exit\nEnter Choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1 : mod();break;
            case 2 : break;
            default : cout<<"invalid INput gandu\n";
        }
    }
    while(choice!=2); 
    }

    void mod()
    {
        cout<<"\nenter First number : ";
        cin>>first;
        cout<<"\nenter second number : ";
        cin>>second;
        result = first % second ;
        cout<<"SO ,"<<first<<" % "<<second<<" is : "<<result;
        cout<<endl;
    }
};

int main()
{
    modulo m1;
    m1.option();
    return 0;
}