#include<iostream>
using namespace std;

class twoStackUsingArray
{
    public:
    int choice;
    void getData()
    {
        
        do{
            switch(choice)
            {
                cout<<"\n1. Insert in S1\n2. Insert in S2\n3. Remove from S1\n4. Remove from S2\n5. Exit";
                cout<<"choice : ";
                cin>>choice;
            }
        }while(choice != 5);
    }

    void insert_in_s1()
    {
        
    }

    
};

int main()
{
    twoStackUsingArray tstack;
    return 0;
}