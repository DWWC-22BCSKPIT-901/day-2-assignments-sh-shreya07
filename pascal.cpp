#include <iostream> 
#include <vector> 
 
using namespace std; 
 
vector<vector<int>> pascal_triangle(int rows) {     vector<vector<int>> retval;     for (int i = 0; i < rows; i++) {         if (i == 0) { 
            retval.push_back({1});         } else if (i == 1) { 
            retval.push_back({1, 1}); 
        } else { 
            vector<int> row(i + 1);             row[0] = row[i] = 1;             for (int j = 1; j < i; j++) { 
                row[j] = retval[i-1][j] + retval[i-1][j-1]; 
            } 
            retval.push_back(row); 
        }     } 
    return retval; 
} 
int main() {     int n = 0;     cin >> n; 
 
    vector<vector<int>> t = pascal_triangle(n);     for (const auto &row : t) {         for (const auto &val : row) {             cout << val << " "; 
        } 
        cout << endl; 
    }      
    return 0; 
} 
