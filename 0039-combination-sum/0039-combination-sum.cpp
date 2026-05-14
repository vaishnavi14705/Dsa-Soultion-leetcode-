class Solution {
public:
    vector<vector<int>> ans; // This stores all the valid combinations we find
    vector<int> cur; // This is the current combination we're building

    void solve(int i, vector<int>& a, int target) {
        // If target is exactly 0, we found a valid combination
        if (target == 0) {
            ans.push_back(cur);
            return;
        }

        // If target is negative or we've run out of numbers, we stop this path
        if (target < 0 || i == a.size())
            return;

        // Option 1: Take the current number a[i]
        cur.push_back(a[i]);
        // Recurse with the same index because we can reuse the same number
        solve(i, a, target - a[i]);
        // Backtrack: remove the number after exploring that path
        cur.pop_back();

        // Option 2: Skip the current number and move to the next index
        solve(i + 1, a, target);
    }

    vector<vector<int>> combinationSum(vector<int>& a, int target) {
        // Start solving from the first index with the full target
        solve(0, a, target);
        return ans; // Return all found combinations
    }
};
