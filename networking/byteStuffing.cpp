#include <bits/stdc++.h> 
using namespace std; 


class byteStuffing
{
	public:
	string s;

	void getData()
	{
		cout<<"\nenter any string : ";
		getline(cin, s);
	}

	void strToBi	nary() 
		{ 
			int n = s.length(); 


			for (int i = 0; i <= n; i++) 
			{ 
				int val = int(s[i]); 
				string bin = ""; 
				while (val > 0) 
				{ 
					(val % 2)? bin.push_back('1') : 
							bin.push_back('0'); 
					val /= 2; 
				} 
				reverse(bin.begin(), bin.end()); 

				cout << bin << " "; 
			}
			 
		}

};


int main() 
{ 
	byteStuffing bS;
	bS.getData();
	bS.strToBinary();
	return 0; 
} 
