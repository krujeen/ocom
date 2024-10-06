#include <iostream>
#include <vector>

using namespace std;

vector<long long> generateFibonacci(int n) {
    vector<long long> fib(n);
    if (n >= 1) fib[0] = 0;
    if (n >= 2) fib[1] = 1;
    
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    
    return fib;
}

int main() {
    int n;
    cin >> n;
    
    if (n < 1 || n > 50) {
        cout << "Invalid input. Please enter a number between 1 and 50." << endl;
        return 1;
    }
    
    vector<long long> fibonacci = generateFibonacci(n);
    
    for (int i = 0; i < n; i++) {
        cout << fibonacci[i];
        if (i < n - 1) cout << " ";
    }
    cout << endl;
    
    return 0;
}
