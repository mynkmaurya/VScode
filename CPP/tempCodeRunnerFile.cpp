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
 cout << " Take an input: ";
cin >> n ;
 for ( i = 1; i <= n; i++)
 {
    cout << " ";
    for ( j = 1; j <= (n + 10) - (i+2); j++)
    {
        cout << " ";
    }
    for(k=i; k>=1; k--)
 {
   cout << k ;
 }
     cout << endl;
 }
 
    return 0;
}
 