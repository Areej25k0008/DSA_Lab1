#include <iostream>
using namespace std;
int main() {
    int num;
    
    while(true) {
        cout << "Enter a positive number: ";
        cin >> num;
        
        if (num == -1) {
            break;
        }
        
        if (num <= 0) {
            cout << "invalid input" << endl;
            continue;
        }
        
        int sum = 0;
        cout << "Factors of " << num << " are: ";
        for(int i = 1; i <= num; i++) {
            if(num % i == 0) {
                cout << i << " ";
                sum = sum + i;
            }
        }
        cout << endl;
        cout << "Sum of factors: " << sum << endl;
    }
    return 0;
}