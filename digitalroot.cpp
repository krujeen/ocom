#include <iostream>

using namespace std;

int digitalRoot(long long n) {
    if (n < 10) {
        return n;
    }
    
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    
    return digitalRoot(sum);
}

int main() {
    long long n;
    cin >> n;
    
    if (n < 1 || n > 1000000000) {
        cout << "Invalid input. Please enter a number between 1 and 1,000,000,000." << endl;
        return 1;
    }
    
    int result = digitalRoot(n);
    cout << result << endl;
    
    return 0;
}
