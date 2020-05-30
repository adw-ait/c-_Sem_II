#include<iostream>

#include<string.h>

using namespace std;

class infixToPostfix

{

   public:

    int top, choice, nol, element, num1, num2, ans;

    int *arr;

    string exp;

    void getData()

   {

      top = -1;

      cout << "Enter size of stack: ";

      cin >> nol;

      arr = new int[nol];

      cin.ignore();

      cout << "Enter Expression: ";

      getline(cin, exp);

      cout << "\nExpression: " << exp << endl;

      for (int i = 0; i < exp.length(); i++)

      {

         if (int(exp[i]) >= 48 && int(exp[i]) <= 57)

         {

            push(exp[i] - 48);

         } else if (exp[i] == '+')

         {

            num1 = arr[top];

            pop();

            num2 = arr[top];

            cout << num2;

            pop();

            ans = num2 + num1;

            push(ans);

         } else if (exp[i] == '*')

         {

            num1 = arr[top];

            pop();

            num2 = arr[top];

            cout << num2;

            pop();

            ans = num2 * num1;

            push(ans);

         } else if (exp[i] == '/')

         {

            num1 = arr[top];

            pop();

            num2 = arr[top];

            cout << num2;

            pop();

            ans = num2 / num1;

            push(ans);

         } else if (exp[i] == '-')

         {

            num1 = arr[top];

            pop();

            num2 = arr[top];

            cout << num2;

            pop();

            ans = num2 - num1;

            push(ans);

         } else if (exp[i] == ')')

         {

            display();

         }

      }

   }

   void push(int element)

   {

      if (top == nol - 1)

      {

         cout << "\noverflow" << endl;

      } else {

         top += 1;

         arr[top] = element;

      }

   }

   void pop()

   {

      if (top == -1)

      {

         cout << "\nunderflow" << endl;

      } else

      {

         top--;

      }

   }

   void display()

   {

      if (top == -1)

      {

         cout << "\nstack is empty" << endl;

      } else {

         cout << "\nValue of a[top]: " << arr[top];

      }

      cout << endl;

   }

};

int main()

{

   infixToPostfix i2f;

   i2f.getData();

   return 0;

}