class Solution {
public:   
    // Recursive helper function to calculate max total satisfaction
    int hlo(vector<int>& satisfaction, int i, int time) {
        // Base case: if all dishes are considered, return 0
        if (i >= satisfaction.size()) {
            return 0; 
        }

        // Option 1: Include the current dish at the current 'time'
        // and move to the next dish with incremented time
        int include = time * satisfaction[i] + hlo(satisfaction, i + 1, time + 1);

        // Option 2: Skip the current dish, keep time the same
        int exclude = hlo(satisfaction, i + 1, time);

        // Take the maximum of including or excluding the current dish
        return max(include, exclude);
    }

    // Main function to return the maximum satisfaction
    int maxSatisfaction(vector<int>& satisfaction) {  
        // Sort the satisfaction values to try picking dishes from least to greatest
        sort(satisfaction.begin(), satisfaction.end()); 

        // Start the recursive process from index 0 and time = 1
        return hlo(satisfaction, 0, 1);
    }
};
