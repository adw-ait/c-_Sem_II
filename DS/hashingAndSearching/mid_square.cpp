#include<iostream>
#include<math.h>
using namespace std;

class midSquare
{
    public:
    int nol, *arr, *keep, temp_arr[10], mid;

    void getData()
    {
        //get location from user
        cout<<"\nEnter number of locations : ";
        cin>>nol;

        
        
        //dynamic array allocation
        arr = new int[nol];
        keep = new int[nol];
        // temp_arr = new int[nol];

        //get array data
        cout<<"\nEnter array data : "<<endl;
        for(int i = 0; i<nol; i++)
        {
            cin>>arr[i];
        }

        //assign NULL to for keep array
        for(int i = 0; i<nol; i++)
        {
            keep[i] = '\0';
        }


        //calculate mid square and store data 
        

        for(int i = 0; i<nol; i++)
        {
            int length = 0, pwr, temp;
            pwr = arr[i] * arr[i];
            // cout<<endl<<pwr<<endl;
            temp = pwr;

            //get length of the digit
            while(pwr>0)
            {
                pwr = pwr/10;
                length++;
            }
            // cout<<"\n length of "<<temp<<" is :"<<length;

            for(int i = length-1; i>=0; i--)
            {
                temp_arr[i] = temp%10;
                temp = temp/10;
            }

            //if length is odd
            if(length % 2 == 1)
            {
                int midDig = length/2;  
                mid = temp_arr[midDig];
                // cout<<"\nodd mid value is : "<<mid<<endl;
            }

            //if length is even
            else
            {
                int mid1 = temp_arr[(length - 1)/2];
                int mid2 = temp_arr[(length/2)];
                // cout<<"mid1 : "<<mid1<<" mid 2 : "<<mid2;
                mid = (mid1 * 10) + mid2;
                // cout<<"\neven mid value is : "<<mid;
            }

            if(mid < nol-1)
            {
                if(keep[mid]=='\0')
                {
                    keep[mid] = arr[i];
                }
                else
                {
                    while(keep[mid]!='\0')
                    {
                        mid = (mid + 1)%nol;
                    }
                    keep[mid] = arr[i];
                }   
            }
            else
            {
                int modulo = mid % nol;
                if(keep[modulo] == '\0')
                {
                     keep[modulo] = arr[i];
                }
                else
                {
                    while(keep[modulo] != '\0')
                    {
                        modulo = (modulo + 1) % nol;
                    }
                    keep[modulo] = arr[i];
                }
            }
        }
        display();
    }
   
    void display()
    {
        cout<<endl;
        for(int i = 0; i<nol; i++)
        {
            
            cout<<"| "<<keep[i]<<" |"<<endl;

        }
    }
};

int main()
{
    midSquare mS;
    mS.getData();
    // mS.display();
}