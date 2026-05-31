class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //brute force solution

        for(int i =  0 ;  i < nums.size() ; i++)
        {
            for(int j = i ; j<nums.size() ; j++)
            {
                
                if(nums [i]+ nums[j]==target)
                {
                    if(i != j){
                    return {i,j};}
                }
                
            }
        }
        
        return {};
    }
    
};