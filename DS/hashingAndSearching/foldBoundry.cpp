#include<iostream>
using namespace std;


class foldBoundry
{
    public:
    int *arr, *keep, nol;

    void getData()
    {
        cout<<"Enter number of location : ";
        cin>>nol;

        arr = new int[nol];
        keep = new int[nol];
    }

    void foldData()
    {
        for(int i = 0; i<nol; i++)
        {
            int len = arr[i], length;
            while(len>0)
            {
                len = len/10;
                length++;
            }
            
            if(length % 2 == 0)
            {
                int num1, num2, num3, temp = arr[i];
                num1 = temp % 100;
                temp = num1 / 100;
                num2 = temp % 100;
                num3 = num2 / 100;

                reverse(num1);
                reverse(num3);


            }
        }
    }

    void reverse(num)
    {
        int rem, revnum = 0; 
        while(num != 0)
        {
            rem = num % 10;
            revnum = (revnum * 10) + rem;
            num = num/10;
        }
        return revnum
    }
};

int main()
{
    foldBoundry fb;
    fb.getData();
}