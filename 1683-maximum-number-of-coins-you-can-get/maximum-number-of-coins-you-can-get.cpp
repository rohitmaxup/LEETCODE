class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        
        long long result =0;
        for(int i = piles.size()/3 ; i<piles.size();i+=2)
        {
            result = result + piles[i];
        }

        return result;
    }
};