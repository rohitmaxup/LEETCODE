class Solution {
public:

    int isPossible(int h , vector<int>& piles , int k)
    {
        long long hours = 0;

        for( int p : piles)
        {
            hours += (p+k-1)/k;

            if(hours > h) return false;

        }

        return (hours <=h);
    }



    int minEatingSpeed(vector<int>& piles, int h) {
        //now comes the real part of the koko eating banana , here we have top write the code , which help us to do binary search on this 
        if(h<piles.size()) return -1;
        int lo = 1;
        int hi = *max_element(piles.begin(),piles.end());
         int ans = hi;
        while(lo<=hi)
        {
        int mid = ((hi - lo)/2) + lo;
       

        if(isPossible(h,piles,mid))
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