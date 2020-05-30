#include<iostream>
#include<string>
#include<sstream>
using namespace std;
class ipAddressing
{
    public:

        string ipAddr;
        int length, dot=0, counter = 0;
        char dl = '.';
        string word = "";
        int valid = 0;
        int A=0,B=0,C=0,D=0;

    void getData()
    {
        cout<<"\nEnter ip address : ";
        getline(cin, ipAddr);

        

        ipAddr = ipAddr + dl;
        cout<<"\nip adddress : "<<ipAddr;

        //length of string
        length = ipAddr.length();


        for(int i = 0; i<ipAddr.length(); i++)
        {
            if(ipAddr[i] != dl)
            {
                word = word + ipAddr[i];
            }
            
            else
            {
                if(stoi(word) >= 255 && stoi(word) < 0)
                {
                    counter = 1;
                }
                dot++;
                if(dot == 1)
                {
                   whatClass(stoi(word)); 
                }
                word = "";
            }
            

            
        }

       

        // cout<<"\nword : "<<word;

        dot--;
        cout<<"\ndot : "<<dot;
        if(dot == 3 && counter == 0)
        {
            cout<<"\nip address is valid";
        }
        else
        {
            cout<<"\nip address is not valid";
        }
        
        if(A == 1)
        {
            cout<<"ip address belongs to class A";
        }
        else if(B == 1)
        {
            cout<<"ip address belongs to class B";
        }
        else if(C == 1)
        {
            cout<<"ip address belongs to class C";
        }
        else if(D == 1)
        {
            cout<<"ip address belongs to class D";
        }

        
        
    }

    void whatClass(int x)
    {
        if(x >= 1 && x<= 126)
        {
            A = 1;
        }
        else if(x >= 128 && x <= 191)
        {
            B = 1;
        }
        else if(x >= 192 && x <= 223)
        {
            C = 1;
        }
        else if(x >= 224 && x <= 239)
        {
            D = 1;
        }
    }
};

int main()
{
    ipAddressing ip;
    ip.getData();
    return 0;
}