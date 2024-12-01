
#include<iostream>
using namespace std;
int  main()
{
    int z;
     cout << " Enter the case no : ";
    cin >> z;
    switch (z)
    {
case 1:
    {
        /*
        4 4 4 4 4 4
       4 4 4 4 4 4
       4 4 4 4 4 4  
       4 4 4 4 4 4
       4 4 4 4 4 4 */
         
    int rows = 5;  // Number of rows
    int columns = 6;  // Number of columns

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << "4 ";
        }
        cout << endl;  // Move to the next line after printing each row
    }

    
        break;
    }
 case 2:
    {
        /*
        Second Pattern:
   
       1 4 9 16 25
       1 4 9 16 25
       1 4 9 16 25
       1 4 9 16 25
       1 4 9 16 25
       1 4 9 16 25
       */
   int i, j;
        for ( i = 1 ; i <= 6; i++)
        {
            /* code */
            for ( j = 1; j <= 5; j++)
            {
                /* code */
                cout << j*j << " ";
            }
            cout << endl;
        }
        break;
    }
case 3:
        {
            /*
            
   Third Pattern:
  
    1 8 27 64 125 216
    1 8 27 64 125 216
    1 8 27 64 125 216
    1 8 27 64 125 216
    1 8 27 64 125 216
            */
             int i, j;
        for ( i = 1 ; i <= 6; i++)
        {
            /* code */
            for ( j = 1; j <= 5; j++)
            {
                /* code */
                cout << j*j*j << " ";
            }
            cout << endl;
        }
           break;
        }
        case 4:
        {
            /*
 
Fourth Pattern:

F G H I J K  
F G H I J K
F G H I J K
F G H I J K
F G H I J K
*/
        char a;
        int i, j;
        for ( i = 1; i <=5; i++)
        {
          for ( a = 'F'; a <= 'K' ; a++)
          {
            /* code */ cout << a << " ";

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