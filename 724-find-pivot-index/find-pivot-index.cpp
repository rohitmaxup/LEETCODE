class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        vector<int> prefix(nums.size());

        prefix[0] = 0;

        for(int i = 1; i < nums.size(); i++)
        {
            prefix[i] = prefix[i-1] + nums[i-1];
        }

        int total = prefix[nums.size()-1] + nums[nums.size()-1];

        for(int i = 0; i < nums.size(); i++)
        {
            if(prefix[i] == total - prefix[i] - nums[i])
            {
                return i;
            }
        }

        return -1;
    }
};