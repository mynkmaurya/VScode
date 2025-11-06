#include<bits/stdc++.h>
using namespace std;    

int main () 
{
   int i = 1;
    int n;
    cout << "Enter the nth fibonacci number you want: "; 

    cin >> n;
    int a = 0, b = 1, c;
    if (n == 1) {       
        cout <, a <<  endl;
    } else if (n == 2) {        
        cout << a << " " << b << endl;
    } else {
        cout << a << " " << b << " ";
        for (i = 3; i <= n; i++) {
            c = a + b;
            cout << c << " ";
            a = b;
            b = c;
            
        }
        cout << endl;
    }
}