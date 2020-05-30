#include<iostream>
#include<string.h>
#include<bitset>
using namespace std;

int main()
{
  string str;
  cout<<"enter string : ";
  getline(cin,str);

    int n = str.length();
 
    // cout<<"original string : "<<str;

    for (int i = 0; i <= n; i++)
    {
       
        int val = int(str[i]);
 
        
        string str = "";
        while (val > 0)
        {
            (val % 2)? str.push_back('1') :
                       str.push_back('0');
            val /= 2;
        }
        
        cout << str;
    }
    
    

    int str_len = str.length();
    int count = 0;
    
    for(int i = 0; i<str_len; i++)
    {
      if(str[i] == '1')
      {
        count++;
      }

      else
      {
        count = 0;
        cout<<str;
      }

      if(count == 5)
      {
        cout<<"--0--";
        count = 0;
      }
      
    }

}


