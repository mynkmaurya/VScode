#include<iostream>
using namespace std;
int main()
{
    int i, c;
    
    
    for ( i = 1; i <= 6 ; i++)
    { 
        for ( c = 1; c <= 6-i ; c++)
        {
            cout << " ";
        }
        for ( c = 1; c <= i; c++)
        {
            cout << "*" ;
        }
        
       cout << endl;
    }
    
}