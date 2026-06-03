class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int minsum = nums[0];
        int minbest = nums[0];

        int maxsum = nums[0];
        int maxbest = nums[0];

        int total = nums[0];

        for(int i=1;i<nums.size();i++){

            total += nums[i];

            maxsum = max(nums[i], maxsum + nums[i]);
            maxbest = max(maxbest, maxsum);

            minsum = min(nums[i], minsum + nums[i]);
            minbest = min(minbest, minsum);
        }

        if(maxbest < 0)
            return maxbest;

        return max(maxbest, total - minbest);
    }
};