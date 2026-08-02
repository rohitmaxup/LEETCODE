class Solution {
public:
    int maxDepth(string s) {
        int res = 0;
        int curr = 0;

        for(int i = 0 ; i  < s.length(); i++)
        {
            if(s[i]=='(')
            {
                curr++;
                res = max(curr,res);
            }
            else if(s[i]==')')
            {
                curr--;

            }

        }

        return res;
    }
};