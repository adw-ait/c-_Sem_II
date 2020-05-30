#include<iostream>
#include<math.h>

using namespace std;

class max_cap
{
    public:


    float bandWidth, n, data_rate;
    void getData()
    {
        cout<<"\nenter Bandwidth : ";
        cin>>bandWidth;

        cout<<"\nEnter Signal to Noise Ratio(SNR) or Signal level(L) : ";
        cin>>n;

        if((int)n%2 == 0)
            {
                henry();
            }
        else
        {
            shannon();
        }
    }
    void shannon()
    {
        cout << "\n*********Using Shannon Theorem*********\n";
        int dataRate = bandWidth * (log(1+n)/log(2));
        cout<<"\nData Rate : "<<dataRate<<" bps";
        cout<<"\nSNR : "<<n;
        cout<<"\nchannel is Noisy";
    }

    void henry()
    {
        cout << "\n*********Using Henry Nyquist Theorem*********\n";
        int dataRate = bandWidth * (log(1 + n)/ log(2));
        cout<< "\nData Rate : "<<dataRate<<" bps";
        cout<< "\nSNR : "<<n;
        cout<<"\nChannel is noisy\n";
    }

};

int main()
{
    max_cap mc;
    cout<<"\n************** Maximum Capacity of Bandwidth using Shannon theorem or Nyquist theorem **************\n";
    mc.getData();

    return 0;
}