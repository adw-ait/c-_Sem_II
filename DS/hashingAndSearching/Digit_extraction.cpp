#include<iostream>
using namespace std;

class digitExtraction
{
    public:
    int *arr, nol,*extDigs, *keep, length, n, tmp[10], final, digs;

    void getData()
    {
        
        cout<<"\nenter no of locations : ";
        cin>>nol;

        keep = new int [nol];
        arr = new int [nol];

        cout<<"\nhow many digits to extract : ";
        cin>>digs;

        extDigs = new int[digs];

        cout<<"\nenter "<<digs<<" digits to extract : ";
        for(int i = 0; i<digs; i++)
        {
            cin>>extDigs[i];
            
        }

        for(int i = 0; i<nol; i++)
        {
            keep[i] = '\0';
        }


        cout<<"enter array data : \n";
        for(int i=0; i<nol; i++)
        {
            cin>>arr[i];
        }
        
        
        
        for(int i=0; i<nol; i++)
        {
            length = 0;
            int copyNo = arr[i];
            while(copyNo>0)
            {
                copyNo  = copyNo/10;
                length++;
            }

            copyNo = arr[i];

            for(int i = 0; i<=length-1; i++)
                
                {
                    tmp[i] = copyNo % 10;
                    copyNo = copyNo/10; 
                }

            
            // for(int i = 0; i<=length-1; i++)
            // {
            //     cout<<tmp[i]<<" ";
            // }
            // cout<<endl;

            

            //extraction part

             int extrct = 0;
                for(int i = digs-1; i>=0; i--)
                {
                    extrct = extrct * 10;
                    extrct = extrct + tmp[extDigs[i]-1];
                }

                cout<<"\nextracted digit is : "<<extrct<<endl;;

                final = extrct % nol;
                
               
                if(keep[final] != '\0')
                {
                    //collision occured
                    while(keep[final]!='\0') 
                        {
                            final = (final + 1)%nol;
                        }

                        keep[final] = arr[i];
                }
                else
                {
                    keep[final] = arr[i];
                }

        }
    }


    
    void display()
    {
        cout<<endl;
        for(int i = 0; i<nol; i++)
        {
            
            cout<<"| "<<keep[i]<<" |"<<endl;

        }
    }
};

int main()
{
    digitExtraction de;
    de.getData();
    de.display();
    return 0;
}