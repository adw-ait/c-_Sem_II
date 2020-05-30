#include<iostream>
#include<math.h>
using namespace std;

class midSquare
{
    public:
        int keep[10], num[100], length, mid1, mid2, midDigit, mid, final_mid;
        int n, temp, sqr, nol;
        void getData()
        {   

            cout<<"enter number of locations : ";
            cin>>nol;

            for(int i = 0; i<nol; i++)
            {
                keep[i] = -1;
            }
            

            length = 0;
            cout<<"enter a number : ";
            cin>>n; //12345
            temp = n * n;
            int power = temp;

            cout<<"power is : "<<power;
            
            
            
            while(temp>0)
            {
                temp  = temp/10;
                length++;
            }   

            cout<<"\nlength is : "<<length;
                
                for(int i = length-1; i>=0; i--)
                {
                    num[i] = power % 10;
                    power = power/10;
                }

            if(length % 2 == 1)
            {
                midDigit = length / 2;
                mid = num[midDigit];
                cout<<"\nmiddle digit is : "<<mid;
            }
            else
            {
                cout<<"\nno middle digit";

                mid1 = num[(length-1)/2];
                mid2 = num[length/2];

                cout<<"\nvalue 1 : "<<mid1;
                cout<<"\nvalue 2 : "<<mid2;
                final_mid = (mid1 * 10) + mid2;
                cout<<"\nfinal value : "<<final_mid;

                if(keep[final_mid] =! NULL && keep[final_mid] <= nol)
                {
                    keep[final_mid] = final_mid;
                    
                }
                else if(keep[final_mid] > nol)
                {
                    
                }
                

                

            }

            // if(keep[mid] != NULL || keep[final_mid] ==! NULL)
            // {
                
            // }

            

            



        }


        void display()
    {
        
        for(int i = 0; i<nol; i++)
        {
            
            cout<<"| "<<keep[i]<<" |"<<endl;

        }
    }

};


int main()
{
    midSquare ms;
    ms.getData();
}