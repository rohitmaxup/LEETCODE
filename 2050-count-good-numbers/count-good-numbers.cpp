class Solution {
public:


    long long power(long long x,long long n , long long mod)
    {
        long long ans =1;

        while(n)
        {
            if(n&1) ans = (ans*x) % mod;
            x = (x*x)%mod;
            n = n>>1;
        }

        return ans;
    }
    int countGoodNumbers(long long n) {
        long long evenExpo = (n+1)/2;
        long long oddExpo = n/2;
        long long mod = 1e9 + 7;

        return (int)((power(5,evenExpo,mod)*power(4,oddExpo,mod))%mod);
    }
};