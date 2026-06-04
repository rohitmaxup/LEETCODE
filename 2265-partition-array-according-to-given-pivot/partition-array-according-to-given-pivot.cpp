class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        


        vector<int>ltp;
        vector<int>etp;
        vector<int>gtp;

        for(int i =0 ; i < nums.size() ; i ++)
        {
            if(nums[i]>pivot)
            {
                gtp.push_back(nums[i]);
            }
            else  if(nums[i]==pivot)
            {
                etp.push_back(nums[i]);
            }
            else  if(nums[i]<pivot)
            {
                ltp.push_back(nums[i]);
            }
        }

      ltp.insert(ltp.end(),etp.begin(),etp.end());
      ltp.insert(ltp.end(),gtp.begin(),gtp.end());

      return ltp;
    }
};