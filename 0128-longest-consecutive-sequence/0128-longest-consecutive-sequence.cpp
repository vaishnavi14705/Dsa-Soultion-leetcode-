class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> s(nums.begin(), nums.end());

        int ans = 0;

        for(int num : s) {

            if(s.find(num - 1) == s.end()) {

                int current = num;
                int length = 1;

                while(s.find(current + 1) != s.end()) {
                    current++;
                    length++;
                }

                ans = max(ans, length);
            }
        }

        return ans;
    }
};