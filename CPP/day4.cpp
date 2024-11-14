#include<iostream>
using namespace std;
int main()
{
    int z;
    cout << "Enter no from 1 to 3: ";
    cin >> z;
switch (z)
{
case 1:
{
     int a, b;
    cin >> a >> b;
    if (a > b)
    {
        cout << a << endl;
    }
    else if (a == b)
    {
        /* code */
        cout << "ERROR, Both no can not be same" << endl;
    }
    else
    {
        cout << b << endl;
    }
    return 0;
    
   
    break;
}
case 2:
{
    cout << "age of a person is given, print Adult if his/her age is greater than 18, otherwise print Teenager.";
      int a;
    cout << "Enter the age: ";
    cin >> a;
    if (a>=18)
    {
        /* code */
        cout << "Adult" << endl;
    }
    else if (0 <a)
    {
        /* code */
        cout << "Teenager" << endl;
    }
    else 
    {
        cout << "Syntax Error" << endl;
    }
    return 0;
    break;
}
case 3:
{ 
    cout <<"Ticket Price Calculator: Create a program that asks the user for their age and checks if they qualify for a discounted ticket price (e.g., under 12 and over 65 get discounts), If they are eligible print “YES” else “NO”.";
      int n;
    cout << "Enter the age: ";
    cin >> n;
    if (n < 0)
    {
      cout << "Age can't be negative" << endl;

    }
    else if (n<12)
{
    cout << "Yes, Eligible for discounted ticket" << endl;
}
else if (n <=65)
{
 cout << "Not Eligible for discounted ticke" << endl;
}
else
{
     cout << "Yes, Eligible for discounted ticket" << endl;
}
return 0;
    break;
}
default:
{
    cout << "Invalid input";
    break;
}
} 
}