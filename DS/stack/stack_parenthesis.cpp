#include<iostream>
using namespace std;

class Stack
{
    public:

    int size, top, *arr, count;
    char *stack;
    string expr;
    
    void getData()
    {
        count = 0;
        top = -1;

        cout<<"Enter expression : ";
        getline(cin,expr);

        stack = new char[expr.length()];

        for(int i = 0; i<expr.length(); i++)
        {
            if(expr[i] == '(')
            {
                // cout<<expr[i];
                push(expr[i]);
            }
            else if(expr[i] == ')')
            {
                // cout<<endl<<expr[i];
                pop();
            }
        }

        cout<<"\ntop is : "<<top;
        cout<<"\ncount is : "<<count;

         if(top == -1)
        {
            cout<<"\nParentheses  are balanced";
        }
        else
        {
            cout<<"\nParentheses aren't balanced";
        }
    }
        


    void push(char val)
    {
        
            top++;
            stack[top] = val;
        
    }
    void pop()
    {
       
            count++;
            top--;
        
    }

};

int main()
{
    Stack s1;
    s1.getData();
    return 0;
}