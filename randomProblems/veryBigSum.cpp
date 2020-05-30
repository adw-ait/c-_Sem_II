#include<iostream>
#include<math.h>
using namespace std;

class veryBigSum
{
    public:
            long long int arrSize, arr[10], sum = 0;
    void getData()
    {
        cout<<"\nEnter Size of Array : ";
        cin>>arrSize;

        // arr = new int[arrSize];

        cout<<"\nEnter Array data :"<<endl;
        for(int i = 0; i < arrSize; i++)
        {
            cout<<"\nElement "<<i+1<<" ";
            cin>>arr[i];
            while(arr[i] < 0 || arr[i] > pow(10,10))
            {
                cout<<"\nValue not in range!!!, Enter again :";
                cin>>arr[i];
            }
        }

        sumOfElements();
    }

    void sumOfElements()
    {
        cout<<"\nSum of elements : ";
        for(int i = 0; i<arrSize; i++)
        {
            sum = sum + arr[i];
        }

        cout<<sum;
    }
};

int main()
{
    veryBigSum vbs;
    vbs.getData();
    return 0;
}