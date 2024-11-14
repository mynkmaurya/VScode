#include <iostream>
using namespace std;
int main() 
{
   int r, c, i;


 for (i = 1; i <= 5; i++) 
  {
    for (c = 5-(i-1); c >= 1 ; c--)
    {
        cout <<c << " " ;
    }
   cout << endl; 
  }

    return 0;
}
