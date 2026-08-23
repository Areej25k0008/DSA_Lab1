#include <iostream>
using namespace std;
void MinMax(int* a, int sz, int* minVal, int* maxVal) {
    *minVal=a[0];
    *maxVal=a[0];
    
    for(int i = 1; i < sz; i++) {
        if(*(a+i) < *minVal) {
            *minVal = *(a+i);
        }
        if(*(a + i) > *maxVal) {
            *maxVal= *(a+i);
        }
    }
}
int main() {
    int arr[] = {25, 10, 45, 5, 30, 60, 15};
    int size = 7;
    int min, max;
    
    MinMax(arr, size, &min, &max);
    
    cout << "Smallest element: " << min << endl;
    cout << "Largest element: " << max << endl;
    return 0;
}