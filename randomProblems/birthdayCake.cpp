#include<iostream>
#include<math.h>
using namespace std;

class birthdayCakeCandels
{
    public:

    long long int noOfCandles, *heightArr;
    int candlesBlowOut = 0;

    void getData()
    {
        // cout<<"\nEnter number of candles on the cake : ";
        cin>>noOfCandles;

        while(noOfCandles < 1 || noOfCandles > pow(10, 5))
        {
            // cout<<"\nValue not in range, Enter again : ";
            cin>>noOfCandles;
        }

        heightArr = new int[noOfCandles];

        // cout<<"\nEnter heights of candles : ";
        for(int i = 0; i < noOfCandles; i++)
        {
            // cout<<"\nHeight of candle "<<i+1<<" : ";
            cin>>heightArr[i];
        }

        getHeight();
    }

    void getHeight()
    {
        long long int max = heightArr[0];

        for(int i = 0; i < noOfCandles; i++)
        {
            if(max > heightArr[i])
            {
                max = heightArr[i];
            }
        }

        candlesBlowOut = 1;

        for(int i = 0; i < noOfCandles; i++)
        {
            if(max == heightArr[i])
            {
                candlesBlowOut++;
            }
        }

        cout<<candlesBlowOut;

    }
};

int main()
{
    birthdayCakeCandels bcc;
    bcc.getData();
    return 0;
}