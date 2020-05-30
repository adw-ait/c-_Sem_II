#include<iostream>
using namespace std;



int main()
{
    int *ptr;
    int a;

    a = 10;
    ptr = &a;

cout<<endl<<"ptr : "<<*ptr;
cout<<endl<<"a : "<<a;
return 0;
}
