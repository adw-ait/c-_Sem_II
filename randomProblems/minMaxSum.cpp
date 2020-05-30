#include<iostream>
#include<math.h>
using namespace std;


class minMaxSum
{
    public:
            long long int arr[5];
            long long int sum = 0;
            long long int max;
            long long int min;

    void getData()
    {
        // cout<<"\nEnter array data : ";
        for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
        {
            cin>>arr[i];
            while(arr[i] < 1 || arr[i] > pow(10,9))
            {
                cout<<"/nValue not in range, enter again : ";
                cin>>arr[i];
            }
        }

        minElement();
        maxElement();
        Sum();
    }

    void minElement()
    {
        min = arr[0];   
        for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
        {
            if(arr[i] <= min)
            {
                min = arr[i];
            }
        }
        
    }

    void maxElement()
    {
        max = arr[0];
        for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
        {
            if(arr[i] >= max)
            {
                max = arr[i];
            }
        }   
    }

    void Sum()
    {
        
        sum = 0;
        for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
        {
            if(arr[i] != max )
            {
                sum = sum + arr[i];
            }
        }

        // cout<<endl;
        cout<<sum<<" ";

        sum = 0;

        for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
        {
            if(arr[i] != min)
            {
                sum = sum + arr[i];
                // cout<<"\nsum : "<<sum;
            }
        }

        
        cout<<sum;
        cout<<endl;
    }
};

int main()
{
    minMaxSum mms;
    mms.getData();
    return 0;
}