#include <iostream>
using namespace std;

int main() {
    int size = 5;
    for (int i = 1; i <= size; ++i) {
        // Print spaces
        for (int j = 1; j <= size - i; ++j) {
            cout << " ";
        }
        
        // Print stars and numbers
        bool isStar = true;
        for (int k = 0; k < 2 * i - 1; ++k) {
            if (isStar) {
                cout << "*";
                isStar = false;
            } else {
                cout << (i);
                isStar = true;
            }
        }
        
        // Move to next line
        cout << endl;
    }
    return 0;
}
