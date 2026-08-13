class Solution {
public:

    vector<int> dp = vector<int>(47, -1);

    int CS(int n)
    {
        if(n == 0 || n == 1)
        {
            return n;
        }

        if(dp[n] != -1)
        {
            return dp[n];
        }

        return dp[n] = CS(n-1) + CS(n-2);
    }

    int climbStairs(int n) {
        return CS(n + 1);
    }
};