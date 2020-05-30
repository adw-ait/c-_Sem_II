#include<iostream>
using namespace std;

class alternateDifference
{
    public:
            int arrSize, *arr, largest;
    void getData()
    {
        cout<<"\nEnter array size : ";cin>>arrSize;

        arr = new int[arrSize];

        cout<<"\nEnter array data :";
        
        for(int i = 0; i<arrSize; i++)
        {
            cout<<"element "<<i<<" :";cin>>arr[i];
        }
    }

    void getAlternativeNumbers()
    {
        for(int i = 0; i < 2; i++)
        {
            for(int j = i; j<arrSize/2; j=j+2)
            {
                largest = arr[i] - arr[i+2];
            }

        }   
    }
};

int main()
{
    alternateDifference altDiff;
    return 0;
}