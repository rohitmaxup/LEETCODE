class Solution {
public:

    int helper(vector<int>& bloomDay , int m ,int k ,int day)
    {
        int count =0;
        int bouquets = 0;

        for(int bloom : bloomDay)
        {
            if(bloom<=day)
            {

            count++;
            if(count == k)
            {
                bouquets++;
                count =0;
            }
            }

            else
            {
                count =0;
            }

        }

        return bouquets >=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {

        int lo = *min_element(bloomDay.begin(),bloomDay.end());
        int hi = *max_element(bloomDay.begin(),bloomDay.end());
         int ans = 0;

         if((long long)m * k > bloomDay.size())
    return -1;
        while(lo<=hi)
        {
            int mid = lo + (hi-lo)/2;
           

            if(helper(bloomDay , m , k , mid))
            {
                ans = mid;
                hi= mid -1;
                
            }

            else
            {
                lo = mid+1;
            }
        }

        return ans;
    }
};