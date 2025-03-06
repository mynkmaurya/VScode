#include <iostream>
using namespace std;

int main() 
{
     /*
      First Pattern: Take an input n from the user, and create a pattern like below, for n=5, we have output like this.
    
            1
         2 1
      3 2 1
   4 3 2 1
5 4 3 2 1          
*/  
  
 int n, i, j, k;
cout << "Enter the value of n: ";
 cin >> n;
 for ( i = 1; i <= n; i++)
 {
   for (k = 1; k <= n-i; k++)
    { 
      cout << " "; 
      }
    
    for ( j = i; j >= 1; j--)
    {cout << j;
       cout << " "; 
      }
    
  
   cout << endl; 
   }
    return 0;
  }                    