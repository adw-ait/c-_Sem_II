#include<iostream>
 
using namespace std;
 
int main() {
    int data[10];
    int finalData[10],p,p1,p2,p3,i;
 
    cout<<"Enter 4 bits of data one by one\n";
    
    cin>>data[0];
    cin>>data[1];
    cin>>data[2];
    cin>>data[4];
 
    
    data[6]=data[0]^data[2]^data[4];
	data[5]=data[0]^data[1]^data[4];
	data[3]=data[0]^data[1]^data[2];
 
	cout<<"\nSender data will be :\n";
	for(i=0;i<7;i++)
        cout<<data[i];
    
	cout<<"\n\nEnter received data :\n";
    for(i=0;i<7;i++)
        cin>>finalData[i];
 
    p1=finalData[6]^finalData[4]^finalData[2]^finalData[0];
    cout<<"\np1 : "<<p1;
	p2=finalData[5]^finalData[4]^finalData[1]^finalData[0];
    cout<<"\np2 : "<<p2;
	p3=finalData[3]^finalData[2]^finalData[1]^finalData[0];
    cout<<"\np3 : "<<p3;
	p=p3*4+p2*2+p1 ;
    cout<<"\np : "<<p;
 
    if(p==0) {
		cout<<"\nNo error while transmission of data\n";
    }
	else {
		cout<<"\nError on position "<<p;
		
		cout<<"\nData sent : ";
		for(i=0;i<7;i++)
        	cout<<data[i];
        
		cout<<"\nData received : ";
        for(i=0;i<7;i++)
        	cout<<finalData[i];
        
		cout<<"\nCorrect message is\n";
        
		if(finalData[7-p]==0)
			finalData[7-p]=1;
        else
		 	finalData[7-p]=0;
		for (i=0;i<7;i++) {
			cout<<finalData[i];
		}
	}
	
	return 0;
}