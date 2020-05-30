#include<iostream>
using namespace std;

class modulo
{
    public:
    int nol, *inpArray, *opArray;

    void getData()
    {
        
        cout<<"\nEnter number of locations : ";
        cin>>nol;

        inpArray = new int[nol];
        opArray = new int[nol];

        cout<<"\nenter array data : ";
        for(int i = 0; i<nol; i++)
        {
            cin>>inpArray[i];
        }

        for(int i = 0; i<nol; i++)
        {
            opArray[i] = '\0';
        }
    }

    void division()
    {
        for(int i = 0; i<nol; i++)
        {
            // int temp = inpArray[i];
            int mod = inpArray[i] % nol;
            // if(mod < nol-1)
            // {
                if(opArray[mod] == '\0')
                {
                    opArray[mod] = inpArray[i];
                }
                else
                {
                    while(opArray[mod]!='\0')
                    {
                        mod = (mod + 1)%nol;
                    }
                    opArray[mod] = inpArray[i];
                }
                
            // }
        }
    }

    void display()
        {
            cout<<endl;
            for(int i = 0; i<nol; i++)
            {
                cout<<"| "<<opArray[i]<<" |"<<endl;
            }
        }
};

int main()
{
    modulo m1;
    m1.getData();
    m1.division();
    m1.display();
}