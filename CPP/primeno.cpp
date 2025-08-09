#include<iostream>
#include<cmath> // For sqrt()
using namespace std;
int main ()
{ 
    int i, n;
    bool isPrime = true;

    cout << "Enter a number: ";
    cin >> n; // Input number

    // 0 and 1 are not prime numbers
    if (n <= 1) {
        isPrime = false;
    } else {
        for (i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                isPrime = false;
                break; // Exit loop if a divisor is found
            }
        }
    }

    if (isPrime)
        cout << n << " is a prime number" << endl;
    else
        cout << n << " is not a prime number" << endl;

    return 0; // Default return
}