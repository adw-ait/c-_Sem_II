#include<iostream>
using namespace std;

class adjacencyMatrix
{
    public:

    int nodes;
    bool arrMatrix[10][10] = {0};
    string response;
    
    
    void getData()
    {
        cout<<"\nEnter number of nodes : ";
        cin>>nodes;
        matrix();
    }

    void matrix()
    {
        for(int i = 0; i < nodes; i++)
        {
            for(int j = 0; j < nodes; j++)
            {
                
                if(i != j && arrMatrix[j][i] != 1)
                {
                    cout<<"\nDo, ("<<i<<", "<<j<<") have a edge (y/n) : ";
                    cin>>response;
                    if(response == "y")
                    {
                        arrMatrix[i][j] = 1;
                        arrMatrix[j][i] = 1;   
                    }
                    else
                    {
                        arrMatrix[i][j] = 0;
                    }
                }
                
            }
        }
        display();
    }

    void display()
    {
        cout<<endl;
        for(int i = 0; i < nodes; i++)
        {
            cout<<i+1<<" : ";
            for(int j = 0; j < nodes; j++)
            {
                cout<<arrMatrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    adjacencyMatrix aj;
    aj.getData();
    return 0;
}