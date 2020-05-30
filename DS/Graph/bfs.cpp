#include<iostream>
using namespace std;

class dfs
{
    public:

    int nodes;
    bool arrMatrix[10][10] = {0};
    string response;
    bool visited;
    int front = 0, rear = -1;
    int *queue;
    int recentAdd = -1;
    
    
    void getData()
    {
        cout<<"\nEnter number of nodes : ";
        cin>>nodes;

        queue = new int[nodes];
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
        cout<<"\nMatrix : ";
        cout<<endl;
        for(int i = 0; i < nodes; i++)
        {
            cout<<i<<" : ";
            for(int j = 0; j < nodes; j++)
            {
                cout<<arrMatrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void scanMatrix()
    {
        for(int i = 0; i<nodes; i++)
        {
            for(int j = 0; j < nodes; j++)
            {
                if(arrMatrix[i][j] == 1 && i!=j && i != recentAdd)
                {
                    recentAdd = i;
                    addToQueue(i);
                    
                }
            }
        }
    }

    void addToQueue(int addThisToQueue)
    {
        rear++;
        queue[rear] = addThisToQueue;
    }

    void deleteFromQueue()
    {

    }

    void displayQueue()
    {
        
        cout<<"\nQueue : ";
        for(int i=front; i<=rear; i++)
        {
            cout<<queue[i]<<" | ";
        }
        cout<<endl;
    }
};

int main()
{
    dfs d;
    d.getData();
    d.scanMatrix();
    d.displayQueue();
    return 0;
}