#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(vector<int>& arr, int left, int K) {
    int q = 0;

    if (left == 0) {
        for (int i = 1; i < K; ++i) {
            if (arr[i] > 0) {
                arr[i]--;
                q = max(q, 1 + dfs(arr, K - i, K));
                arr[i]++;
            }
        }
    } else {
        for (int i = 1; i < K; ++i) {
            if (arr[i] > 0) {
                arr[i]--;
                int nleft = (i <= left ? left - i : K + left - i);
                q = max(q, dfs(arr, nleft, K));
                arr[i]++;
            }
        }
    }
    return q;
}

int maxGroups(int K, const vector<int>& arr) {
    vector<int> V(K, 0);

    for (int x : arr) {
        V[x % K]++;
    }

    int ans = V[0] + dfs(V, 0, K);
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int K = 3;

    cout << "Maximum Groups: " << maxGroups(K, arr) << endl;
    return 0;
}

