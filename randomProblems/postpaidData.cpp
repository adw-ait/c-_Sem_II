#include<iostream>
using namespace std;

class extractValues
{
    public:
            int count = 0;
            string callDetails, callID, calledNo, Duration;
    void getData()
    {
        
        cout<<"\nEnter call details : ";
        getline(cin, callDetails);
        extract(callDetails);
    }

    void extract(string tempCallDetails)
    {
        
        string wordExtraction = "";
        tempCallDetails = tempCallDetails + ':';

        for(int i = 0; i<tempCallDetails.length(); i++)
        {
            if(tempCallDetails[i] != ':')
            {
                wordExtraction = wordExtraction + tempCallDetails[i];
            }

            else
            {
                count++;
                if(count == 1)
                {
                    callID = wordExtraction;
                }
                else if(count == 2)
                {
                    calledNo = wordExtraction;
                }
                else if(count == 3)
                {
                    Duration = wordExtraction;
                }
                wordExtraction = "";
            }
            
        }

        
    }

    void display()
    {
        cout<<"\nCall ID : "<<callID<<"\nCalled Number : "<<calledNo<<"\nDuration : "<<Duration<<endl;
    }

};

int main()
{
    extractValues eV;
    eV.getData();
    eV.display();
    return 0;
}