#include<iostream>
#include<math.h>
// #include<sstream>
using namespace std;

class foldBoundry
{
    public:

    int arrSize, nol, *inpArray, *opArray;
    
    void getData()
    {
        cout<<"\nenter array size : ";
        cin>>arrSize;

        cout<<"\nenter Number of locations : ";
        cin>>nol;

        inpArray = new int[arrSize];
        opArray = new int[nol];

        for(int i = 0; i<nol; i++)
        {
            opArray[i] = '\0';
        }

        cout<<"\nenter array data : ";
        for(int i = 0; i<arrSize; i++)
        {
            cin>>inpArray[i]; 
        }
    }

    void fold()
    {
        for(int i = 0; i<arrSize; i++)
        {
            int length = 0;
            
            
            int copyNo = inpArray[i];

            while(copyNo>0)
            {
                copyNo = copyNo/10;
                length++;
            }

            copyNo = inpArray[i];

            if(length % 2 == 0)
            {
                int addition = 0;
                int power = pow(10, length-2);
                int left = copyNo / power;
                // cout <<"\nleft : "<<left;
                left = reverse(left);
                // cout <<"\nreverse left : "<<left;
                int right = copyNo % 100;
                // cout <<"\nright : "<<right;
                right = reverse(right);
                // cout <<"\nreverse right : "<<right;
                copyNo = copyNo % power;
                copyNo = copyNo / 100;

                int tmp;
                while(copyNo > 0)
                {
                    tmp = copyNo % 100;
                    addition = addition + tmp ; 
                    copyNo = copyNo / 100;

                }

                // cout<<"\naddition of middle nos. : "<<addition;

                addition = addition + left + right;
                // cout<<"\nlocation : "<<addition;

                int num = inpArray[i];
                collision(addition, num);
            }
            else
            {
                int addition = 0;
                int power = pow(10, length-1);
                int left = (copyNo / power) * 10;
                // cout <<"\nleft : "<<left;
                // left = reverse(left);
                // cout <<"\nreverse left : "<<left;
                int right = copyNo % 100;
                // cout <<"\nright : "<<right;
                right = reverse(right);
                // cout <<"\nreverse right : "<<right;
                copyNo = copyNo % power;
                copyNo = copyNo / 100;

                int tmp;
                while(copyNo > 0)
                {
                    tmp = copyNo % 100;
                    addition = addition + tmp ; 
                    copyNo = copyNo / 100;

                }
                // cout<<"\naddition of middle nos. : "<<addition;

                addition = addition + left + right;
                // cout<<"\nlocation : "<<addition;


                int num = inpArray[i];
                collision(addition, num);

                

            }
            
            

        }
    }

            int reverse(int n)
            {
                int reversedNumber = 0, remainder;
                    while(n != 0)
                    {
                        remainder = n%10;
                        reversedNumber = reversedNumber*10 + remainder;
                        n /= 10;
                    }
                    return reversedNumber;
            }


            void collision(int add, int n)
            {
                //location check if available or not
                if(add < nol-1)
                {
                    if(opArray[add] == '\0')
                    {
                        opArray[add] = n;
                    }
                    else
                    {
                        while(opArray[add] != '\0')
                        {
                            add = (add + 1)%nol;
                        }
                        opArray[add] = n;
                    }
                    
                }
                else
                {
                    int modulo = add % nol;
                    if(opArray[modulo] == '\0')
                    {
                        opArray[modulo] = n;
                    }

                    else
                    {
                        while(opArray[modulo] != '\0')
                        {
                            modulo = (modulo + 1)%nol;
                        }
                        opArray[modulo] = n;
                    }
                }
            }


            void display()
            {
                cout<<"\n\n";
                for(int i = 0; i<nol; i++)
                {
                    cout<<"| "<<opArray[i]<<" |"<<endl;
                }
            }
};

int main()
{
    foldBoundry fB;
    fB. getData();
    fB.fold();
    fB.display();
    return 0;
}