#include<iostream>
#include<math.h>

using namespace std;

class RR
{
    public:
    // int bursT, arrivalT, timeQ, compTime;
    int process[100][100][100], pro, bursTime, arrTime;  

    void getData()
    {
        cout<<"enter number of processes : ";
        cin>>pro;
        
    }

    void setData()
    {
        for(int i = 0; i<pro; i++)
        {
            for(int j = 0; j<pro; j++)
            {
                for(int k = 0; k<pro; k++)
                {
                    cout<<"enter burst time : ";
                    cin>>process[j];

                    cou
                }
            }
        }
    }

    void display(){}
};

int main()
{
    RR rr;
    rr.getData();
    rr.setData();
    rr.display();
    return 0;
}