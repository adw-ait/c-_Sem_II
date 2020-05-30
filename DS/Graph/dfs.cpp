#include<iostream>
using namespace std;
class dfs
{
	int stack[100],n,adaj[100][100],top,ele;
	bool visited[100];
public:
	dfs()
	{
		top=-1;
	}
	
	void adjacency()
	{	
		cout<<"Enter the number of nodes:- ";
		cin>>n;

		char c;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<"Is there an edge at["<<i<<","<<j<<"](press y if yes / else press n): ";
				cin>>c;
				if(c == 'y')
				{
					adaj[i][j] = 1; 
				}
				else
				{
					adaj[i][j] = 0;		
				}		
			}
		}
		for(int i=0;i<n;i++)
		{
			visited[i] = false;
		}
		dfslogic(n,adaj,0,visited);
	}
	void dfslogic(int n,int adaj[100][100],int ele,bool visited[100])
	{
		top++;
		stack[top]=ele;
		visited[ele]=true;
		for(int i=0; i<n; i++)
		{
			if(i ==ele)
			{
				continue;
			}
			if(adaj[ele][i] == 1)
			{
				if(visited[i])
				{
					continue;
				}
				dfslogic(n,adaj,i,visited);
			}
			
		}
	}
	
	void display()
	{
		cout<<"\n \n "<<"Adjacenecy matrix:- "<<endl;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<adaj[i][j]<<"\t";
			}
			cout<<endl;
		}	
		
		cout<<endl<<"Stack:-"<<endl;
		for(int k=0;k<=top;k++)
		{
			cout<<stack[k]<<"\t";
		}
	}	
};
int main()
{
	dfs d;
	d.adjacency();
	d.display();
}