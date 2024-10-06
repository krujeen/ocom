#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector<vector<int>> generatePascalTriangle(int n) {
    vector<vector<int>> triangle(n);
    
    for (int i = 0; i < n; i++) {
        triangle[i].resize(i + 1);
        triangle[i][0] = triangle[i][i] = 1;
        
        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
        }
    }
    
    return triangle;
}

void printPascalTriangle(const vector<vector<int>>& triangle) {
    int n = triangle.size();
    int width = 0;
    
    // Find the width of the largest number
    for (const auto& row : triangle) {
        for (int num : row) {
            width = max(width, static_cast<int>(to_string(num).length()));
        }
    }
    
    // Print the triangle
    for (int i = 0; i < n; i++) {
        // Print leading spaces
        cout << setw((n - i - 1) * (width + 1)) << "";
        
        // Print numbers in the current row
        for (int j = 0; j <= i; j++) {
            cout << setw(width) << triangle[i][j];
            if (j < i) cout << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    
    if (n < 1 || n > 20) {
        cout << "Invalid input. Please enter a number between 1 and 20." << endl;
        return 1;
    }
    
    vector<vector<int>> pascalTriangle = generatePascalTriangle(n);
    printPascalTriangle(pascalTriangle);
    
    return 0;
}
