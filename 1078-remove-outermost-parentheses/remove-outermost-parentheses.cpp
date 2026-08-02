class Solution {
public:
    string removeOuterParentheses(string s) {
        int level = 0;
        string ans = "";
        int o = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (level == 0 && s[i] == '(') {
                level++;
                continue;
            }

            if (s[i] == '(')
            {
                ans.insert(ans.begin() + o, s[i]);
                level++;
                o++;
            }

            if (s[i] == ')')
            {
                level--;
                if (level == 0)
                    continue;

                ans.insert(ans.begin() + o, s[i]);
                o++;
            }
        }
        return ans;
    }
};