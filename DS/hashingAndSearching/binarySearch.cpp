#include<iostream>

using namespace std;

class binarySearch

{

   int nol, n, *arr, key, flag, temp, lsb, msb, mid, pass;
   public:

      void getdata()

   {

      cout << "Enter size of array" << endl;

      cin >> nol;

      arr = new int[nol];

      cout<<"\nEnter array data :\n";
      for (int i = 0; i < nol; i++)

      {

         cin >> arr[i];

      }

   }

   void sort()

   {

      for (int i = 0; i < nol - 1; i++)

      {
        pass = i;

         int pos = i;

         for (int j = i + 1; j < nol; j++)

         {

            if (arr[j] < arr[pos])

            {

               pos = j;

            }

         }

         if (pos != i)

         {

            temp = arr[i];

            arr[i] = arr[pos];

            arr[pos] = temp;

         }

      }

   }

   

   void search()

   {

      cout << endl;

      cout << "Enter element to be searched: ";

      cin >> key;

      lsb = 0;

      msb = nol - 1;

      flag = 0;

      while (lsb <= msb)

      {

         mid = (lsb + msb) / 2;

         if (key == arr[mid])

         {

            flag = 1;

            cout << "Number found at " << mid + 1 << endl;
            break;

         }

         if (key < arr[mid])
         {

            msb = mid - 1;

         }

         if (key > arr[mid])

         {

            lsb = mid + 1;

         }

      }

      if (flag != 1)

      {

         cout << endl << "Element not found";

      }

   }

   void display()

   {

      for (int i = 0; i < nol; i++)

      {

         cout << arr[i] << "\t";

      }

      cout << endl;

   }

};

int main()

{

   binarySearch bs;

   bs.getdata();

   bs.sort();

   bs.display();

   bs.search();

   return 0;

}