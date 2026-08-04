class Solution {
public:

    int helper(vector<int>& weights , int cap)
    {
        int load = 0;
        int days  = 1;

        for(int w:weights)
        {
            if(load + w > cap)
            {
                days++;
                load = w;
            }
            else
            {
                load += w;
            }


        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        int lo = *max_element(weights.begin(),weights.end());
        int hi = accumulate(weights.begin(),weights.end(),0);

        while(lo<hi)
        {
            int mid = ((hi-lo)/2) + lo;

            if(helper(weights,mid)<=days)
            {
                hi = mid;
            }
            else
            {
                lo = mid +1;
            }
        }

        return lo;
    }
};