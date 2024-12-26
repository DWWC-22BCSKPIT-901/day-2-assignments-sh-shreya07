#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

bool can_assign_jobs(vector<int>& jobs, int k, long long maxTime) {
    int workers = 1;
    long long current_load = 0;

    for (int job : jobs) {
        // If a single job exceeds the maxTime, return false
        if (job > maxTime) return false;

        // Check if adding the current job exceeds maxTime
        if (current_load + job > maxTime) {
            workers++;        // Assign to a new worker
            current_load = job;

            // If the number of workers exceeds k, return false
            if (workers > k) return false;
        } else {
            current_load += job;
        }
    }
    return true;
}

long long minimum_time_required(vector<int>& jobs, int k) {
    // Sort jobs in descending order to assign larger jobs first
    sort(jobs.rbegin(), jobs.rend());

    long long left = jobs[0];  // Minimum possible time is the largest job
    long long right = accumulate(jobs.begin(), jobs.end(), 0LL); // Sum of all jobs

    while (left < right) {
        long long mid = left + (right - left) / 2;

        if (can_assign_jobs(jobs, k, mid)) {
            right = mid;  // Try to lower the max time
        } else {
            left = mid + 1; // Increase the max time
        }
    }
    return left;
}

int main() {
    vector<int> jobs1 = {3, 2, 3};
    int k1 = 3;

    cout << "Minimum Time Required: " << minimum_time_required(jobs1, k1) << endl;
    return 0;
}
