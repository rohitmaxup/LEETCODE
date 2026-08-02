class Solution {
public:
    int romanToInt(string s) {

        unordered_map<char, int> mp;
        long long result = 0;

        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        for (int i = 0; i < s.length() - 1; i++)
        {
            if (mp[s[i]] < mp[s[i + 1]])
            {
                result = result - mp[s[i]];
            }
            else
            {
                result = result + mp[s[i]];
            }
        }

        result += mp[s[s.length() - 1]];

        return result;
    }
};