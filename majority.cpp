#include <iostream> 
#include <vector> 
 
using namespace std; 
 
int majority_element(vector<int>& arr) {     int n      = arr.size();     int count  = 0;     int retval = 0; 
 
    for (int i = 0; i < n; i++) {         if (count == 0) {             retval = arr[i];             count  = 1; 
        } else if (arr[i] == retval) {             count++;         } else {             count--; 
        } 
    }  
    return retval; 
} 
int main() {     vector<int> t;     int n = 0;     cout << "Size : ";     cin >> n; 
 
    cout << "Array : \n";     for (int i = 0; i < n; i++) {         int x = 0;         cin >> x; 
        t.emplace_back(x); 
    }  
    cout << "\nMajority Element : " << majority_element(t) << endl;     return 0; 
} 
