#include <iostream>
using namespace std;

int main() {
    long long number;
    
    // รับค่าตัวเลขจากผู้ใช้
    cin >> number;
    
    // ตรวจสอบว่าเป็นเลขคู่หรือเลขคี่
    if (number % 2 == 0) {
        cout << "Even" << endl;
    } else {
        cout << "Odd" << endl;
    }
    
    return 0;
}
