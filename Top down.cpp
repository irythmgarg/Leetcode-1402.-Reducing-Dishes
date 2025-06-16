class Solution {
public: 
    // dp[i][time] stores the maximum satisfaction from index i with given time
    int dp[501][501];  

    // Recursive helper function with memoization
    int hlo(vector<int>& satisfaction, int i, int time) {
        // Base case: no more dishes to consider
        if (i >= satisfaction.size()) {
            return 0; 
        }

        // If result is already computed, return it
        if (dp[i][time] != -1)
            return dp[i][time];

        // Option 1: Include the current dish
        // Add satisfaction[i] * time and move to next index with time+1
        int include = time * satisfaction[i] + hlo(satisfaction, i + 1, time + 1);

        // Option 2: Exclude the current dish and keep the same time
        int exclude = hlo(satisfaction, i + 1, time);

        // Store and return the max of including or excluding
        return dp[i][time] = max(include, exclude);
    }

    // Main function to return the maximum satisfaction
    int maxSatisfaction(vector<int>& satisfaction) {  
        // Sort the satisfaction values to evaluate in increasing order
        sort(satisfaction.begin(), satisfaction.end()); 

        // Initialize dp table with -1 (uncomputed state)
        memset(dp, -1, sizeof(dp));

        // Start recursion from the 0th dish with time = 1
        return hlo(satisfaction, 0, 1);
    }
};
