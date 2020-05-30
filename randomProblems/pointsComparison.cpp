#include<iostream>
using namespace std;

class pointsComparison
{
    public:
            int A[3], B[3], points[2]={0};
            string s[3] = {"problem clarity", "originality", "difficulty"};

    void getData()
    {
        cout<<"\nEnter Alice and Bobs's points between 1 to 100 : ";

        for(int i = 0; i<3; i++)
        {
            cout<<endl;
            cout<<"\nAlice :";
            cout<<s[i]<<" : ";cin>>A[i];
            while(A[i] < 0 || A[i] > 100)
            {
                cout<<"\nInvalid input, Enter again : ";cin>>A[i];
            }

            cout<<"\nBob :";
            cout<<s[i]<<" : ";cin>>B[i];
            while(B[i] < 0 || B[i] > 100)
            {
                cout<<"\nInvalid input, Enter again : ";cin>>B[i];
            }

        }
    }

    void comparePoints()
    {
        cout<<"\nComparing points........";

        for(int i = 0; i<3; i++)
        {
            if(A[i] > B[i])
            {
                points[0] += 1;
            }
            else if(A[i] < B[i])
            {
                points[1] += 1;
            }
        }
    }

    void displayData()
    {
        cout<<endl;
        cout<<"\nPoints for Alice:";
        cout<<"\n[ ";
        for(int i = 0; i<3; i++)
        {
            cout<<A[i]<<" ";
        }
        cout<<"]";

        cout<<"\nPoints for Bob:";
        cout<<"\n[ ";
        for(int i = 0; i<3; i++)
        {
            cout<<B[i]<<" ";
        }
        cout<<"]";

        comparePoints();

        cout<<"\nPoints : ["<<points[0]<<" "<<points[1]<<"]";

        cout<<endl;

    }
};

int main()
{
    pointsComparison pc;
    pc.getData();
    pc.displayData();
    return 0;
}