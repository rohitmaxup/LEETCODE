class Solution {
public:
vector<int>dp = vector<int> (39,-1);

int solve(int n)
{

    
    if(n==0)
    {
        return n;
    }
    if(n==1 || n==2)
    {
        return 1;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }

    return dp[n] = solve(n-1) + solve(n-2)+solve(n-3);
}
    int tribonacci(int n) {
        return solve(n);
    }
};