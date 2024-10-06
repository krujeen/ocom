#include <iostream>
#include <string>

using namespace std;

void printMagicalStar(int n) {
    for (int i = 0; i < n; i++) {
        // พิมพ์ช่องว่างด้านซ้าย
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }

        // พิมพ์ดาว
        for (int j = 0; j < 2 * i + 1; j++) {
            if (i == n - 1 || j == 0 || j == 2 * i) {
                cout << "*";
            } else {
                cout << " ";
            }
        }

        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;

    if (n >= 2 && n <= 100) {
        printMagicalStar(n);
    } else {
        cout << "Invalid input. Please enter a number between 2 and 100." << endl;
    }

    return 0;
}
