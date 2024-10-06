#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int nextPrime(int n) {
    if (n <= 1) return 2;
    
    int prime = n;
    bool found = false;
    
    while (!found) {
        prime++;
        if (isPrime(prime)) found = true;
    }
    
    return prime;
}

int main() {
    int n;
    cin >> n;
    
    if (n < 1 || n > 1000000) {
        cout << "Invalid input. Please enter a number between 1 and 1,000,000." << endl;
        return 1;
    }
    
    int result = nextPrime(n);
    cout << result << endl;
    
    return 0;
}
