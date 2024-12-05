#include<iostream>
using namespace std;
int main ()
{
  
    int z;
     cout << " Enter the case no : ";
    cin >> z;
    switch (z)
    {
    case 1:
    {
        /*
        First Pattern:
       
     1
     1 2
     1 2 3
     1 2 3 4
     1 2 3 4 5 
     1 2 3 4 5 6 
    
       */
        int i, j;
        for ( i = 1; i <= 6 ; i++)
        {
            /* code */
            for ( j = 1; j <= i; j++)
            {
                /* code */
                cout << j << " ";
            }
            cout << endl;
        }
        
    
        break;
    }
      case 2:
    {
        /*
        Second Pattern:
   
    A
    A B
    A B C
    A B C D
    A B C D E
        */
     char a = 'A';
     int i, j;
     for ( i = 0; i <= 4; i++)
     {
        /* code */
        for ( j = 0; j <= i; j++)
        {
          cout << char(a + j) << " ";
             
        
        }
        cout << endl;
     }
     
        break;
    }
      case 3:
    {/*
    Third Pattern:
     
       10
       10 11
       10 11 12
       10 11 12 13
       10 11 12 13 14
       10 11 12 13 14 15 

      */
        int i, j;
         for ( i = 0; i <= 5; i++)
     {
        /* code */
        for ( j = 0; j <= i; j++)
        {
          cout << int(10 + j) << " ";
             
        
        }
         cout << endl;
     }
    
        break;
    }
      case 4:
    {
      /*

      Fourth Pattern:

      A B C D
      A B C
      A B
      A


      */
      int i, j;
      char a = 'A';
        for (i = 4; i >= 0; i--)
        {
          /* code */
          for ( j = 0; j <= i ; j++)
          {
            cout << char('A' + j) << " ";
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
