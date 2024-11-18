/*
    cout << "
       4 4 4 4 4 4
       4 4 4 4 4 4
       4 4 4 4 4 4  
       4 4 4 4 4 4
       4 4 4 4 4 4 ";

Second Pattern:
   
       1 4 9 16 25
       1 4 9 16 25
       1 4 9 16 25
       1 4 9 16 25
       1 4 9 16 25
       1 4 9 16 25


   Third Pattern:
  
    1 8 27 64 125 216
    1 8 27 64 125 216
    1 8 27 64 125 216
    1 8 27 64 125 216
    1 8 27 64 125 216

   


Fourth Pattern:

F G H I J K  
F G H I J K
F G H I J K
F G H I J K
F G H I J K
*/
#include<iostream>
using namespace std;
int  main()
{
    int z;
    cin >> z;
    switch (z)
    {
    case 1:
    {

       int n = 5, m = 6;
       for (int i = 1; i < n; i++)
       {
      
        for ( int j = 1; i < m; j++)
        {
            cout << "4 ";
        }
        cout << endl; 
       }
       
        break;
    }
    default:
        cout << "invalid choice";
        break;
    }
  return 0;
}