// Write a java program to read an array of integer elements. 
//The program should find the difference between the alternate 
//numbers in the array and find the index position of the smallest 
//element with largest difference. If more than one pair has the same 
//largest difference consider the first occurrence.

// If the array size is less than 3,Display “Invalid array size”.

// Sample Input1:

// 6

// 4

// 3

// 2

// 10

// 8

// 6

// Sample Output1:

// 1



// Sample Input2:

// 7

// 7

// 6

// 2

// 2

// 3

// 1

// 8

// Sample Output2:

// 2


#include<iostream>
using namespace std;

class alternateDifference
{
    public:
    int arrSize, *arr, *altNumArr, largest, minIndex;

    void getData()
    {
        cout<<"\nEnter array size : ";
        cin>>arrSize;

        arr = new int[arrSize];

        for(int i = 0; i<arrSize; i++)
        {
            cout<<"element "<<i<<": ";
            cin>>arr[i];
        }

        // getAlternateNumbers();
    }

    void getAlternateNumbers()
    {
        altNumArr = new int[arrSize/2];
        for(int i = 0; i<arrSize; i+2)
        {
            cout<<"\ninside getalternatenumbers for loop"
            for(int j = 0; j<arrSize/2; j++)
            {
                altNumArr[j] = arr[i]; 
            }
        }

        for(int i = 0; i<(sizeof(altNumArr)-1); i++)
        {
            if(altNumArr[i] > largest)
            {
                largest = altNumArr[i] - altNumArr[i+1];
                abs(largest);
                minIndex = i;
            }
        }

    }


    void display()
    {
        cout<<"\n largest difference : "<<largest;
        cout<<"\n of minimum index : "<<minIndex;
    }

};

int main()
{
    alternateDifference altDiff;
    altDiff.getData();
    altDiff.getAlternateNumbers();
    altDiff.display();
    return 0;
}

