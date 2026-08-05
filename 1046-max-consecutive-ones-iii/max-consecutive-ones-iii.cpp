class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeroCount = 0;
        int start = 0 ;
        int max_ones = 0;

        for(int end = 0;end < nums.size() ; end++)
        {
            if(nums[end]==0)
            {
                zeroCount++;
            }

            while(zeroCount > k)
            {
                if(nums[start]==0)
                {
                    zeroCount--;
                }

                start++;
            }

            max_ones = max(max_ones , end - start + 1);
        }

        return max_ones;
    }
};