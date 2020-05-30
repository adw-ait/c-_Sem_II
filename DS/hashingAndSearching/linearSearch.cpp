#include<iostream>

using namespace std;

class linearSearch

{
public:

  int nol, n, *arr, key, flag;

    void getData()

  {
    flag = 0;

    cout << "Enter size of array" << endl;

    cin >> nol;

    arr = new int[nol];

    cout<<"\nEnter array data : ";

    for (int i = 0; i < nol; i++)
    {
      cin >> arr[i];
    }

    cout << endl;

    cout << "Enter element to be searched: ";

    cin >> key;

  }

  void search()

  {

    for (int i = 0; i < nol; i++)

    {

      if (key == arr[i])

      {

        flag = 1;

        n = i;

        break;

      }

    }

    if (flag == 1) 
    {
      cout << "Number found at " << n + 1 <<endl;
    } 
    
    else
    {

      cout << "Number not found " << endl;

      arr[nol] = key;

      for (int i = 0; i <= nol; i++)

      {

        cout << arr[i] << "\t";

      }

    }

  }

};

int main()

{

  linearSearch ls;

  ls.getData();
  ls.search();

  return 0;

}