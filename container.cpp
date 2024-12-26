#include <iostream> 
#include <algorithm> 
#include <vector> 
 
using namespace std; 
 
int max_water(vector<int>& heights) {     int retval = 0;     int i      = 0; 
    int j      = heights.size() - 1; 
 
    while (i < j) { 
        int water = (j - i) * min(heights[i], heights[j]);         retval = max(retval, water); 
 
        if (heights[i] < heights[j]) { i++; }         else                         { j--; } 
    }  
    return retval; 
}  
void plot_graph(vector<int>& heights) { 
    int max = *max_element(heights.begin(), heights.end()) + 1;     int heights_size = heights.size(); 
     
    char symbols[max][heights_size]; 
     
    for (int j = heights_size - 1; j > -1; j--) {         int height = heights[j]; 
        for (int i = max - 1; i > -1; i--) { 
            if (height > 0) { symbols[i][j] = '|'; }             else            { symbols[i][j] = ' '; }             height--; 
        }     } 
    cout << endl;     cout << "  +"; 
    for (int j = 0; j < heights_size * 2; j++) {         cout << "-"; 
    } 
    cout << "+" << endl; 
    for (int i = 1; i < max; i++) {         cout << max - i << " |"; 
        for (int j = 0; j < heights_size; j++) {             cout << symbols[i][j] << " "; 
        } 
        cout << "|" << endl; 
    } 
    cout << "  +"; 
    for (int j = 0; j < heights_size * 2; j++) {         cout << "-"; 
    } 
    cout << "+" << endl;     cout << "   ";  
    for (int j = 0; j < heights_size; j++) {         cout << j + 1 << " "; 
    } 
}  
int main(int argc, char* argv[]) {     cout << "\nGraph : \n"; 
    vector<int> heights = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };     plot_graph(heights); 
    cout << "\n\nMaximum water : " << max_water(heights) << endl << endl;     return 0; 
} 
