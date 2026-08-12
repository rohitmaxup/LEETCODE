class Solution {
public:

    int divide(int dividend, int divisor) {

        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        bool sign = (dividend >= 0) == (divisor >= 0);

        long long dvd = abs((long long)dividend);
        long long dvs = abs((long long)divisor);

        long long result = 0;

        while (dvd - dvs >= 0)
        {
            int count = 0;

            while (dvd - (dvs << 1 << count) >= 0)
            {
                count++;
            }

            result += 1LL << count;
            dvd -= dvs << count;
        }

        return sign ? result : -result;
    }
};