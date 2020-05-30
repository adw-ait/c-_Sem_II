#include<iostream>
#include<string>
using namespace std;

int main()
{
    cout<<"enter any number";
    int num;
    cin>>num;

    string str;
    str = to_string(num);

    // cout<<str;

    // str.insert(0,"0");

    cout<<str;

    int n = stoi(str.insert(0,"0"));


    cout<<"\nthis is integer string : "<<n;

    return 0;
}