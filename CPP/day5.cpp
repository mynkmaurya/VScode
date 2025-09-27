#include <iostream>
using namespace std;

int main() {
    int ch;
    cout << " Enter the case no : ";
    cin >> ch;
    switch (ch) {
        case 1: {
            cout << " Print number from 280 to 250 with the help of for loop.";
            int i;
            for (i = 280; i >= 250; i--) {
                cout << i << " ";
            }
            break;
        }
        case 2:
        {
            cout << " Print char from ‘A’ to ‘Z’ with the help of a for loop.";
            char i;
            for ( i = 'A'; i <= 'Z'; i++)
            {
             cout << i << " ";
             
            }
            break;
        }
        case 3:{

cout << "Print char from ‘Z’ to ‘A’ with the help of a for loop";
 char i;
            for ( i = 'Z'; i >= 'A'; i--)
            {
             cout << i << " ";
            }
            break;
        }
         case 4:{
            cout << " There is an Arithmetic Progression, First number is 220 and Common Difference is 7. So print all the numbers from 220 to 730 which follow the AP.";
            int i, d=7;
           
            for (i = 213;  i<=730; i=i+d)
            {
                cout << i << " ";
            }
            
            break;
        }
         case 5:{
            cout << "Print Sum of square of first n natural number.";
               int sum, a, n;
      sum = 0;
      cin >> n;
           
           for ( a = 1; a <= n; a++)
           {
           
            sum = sum + (a*a);
              
           }
           cout << sum <<" \n";
            break;
        }
         case 6:
        {
            cout << " Print Sum of cube of first n natural number";
                 int sum, a, n;
      sum = 0;
      cin >> n;
           
           for ( a = 1; a <= n; a++)
           {
           
            sum = sum + (a*a*a);
              
           }
           cout << sum <<" \n";
            break;
        }
         case 7:
        {
            cout << " Print n’th Fibonacci number";
             int n, t1 = 0, t2 = 1, nextTerm;

    cout << "Enter the number of terms: ";
    cin >> n;

    cout << "Fibonacci Series: ";

    for (int i = 1; i <= n; ++i) 
    {
         cout << t1 << " ";
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
       
    }
            break;
        }
        default: 
            cout << "Invalid choice" << endl;
            break;
    }
    return 0;
}
