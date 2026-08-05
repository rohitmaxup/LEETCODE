class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // int n = s.size();
        // if(s.size()==1 || s.size()==0)
        // {
        //     return s.size();
        // }
        // int p1 = 0 , p2 = 1;

        unordered_map<char,int> mp;

        // for(int i = 0 ; i<n ; i++)
        // {
        //     mp[s[i]]++;
        // }



        // while(p1<= n && p2<= n)
        // {
            
        // }

        int n = s.size();
        int p1 = 0;
        int ans = 0;

        for(int p2 = 0 ; p2<n ; p2++)
        {
            mp[s[p2]]++;

            while(mp[s[p2]]>1)
            {
                mp[s[p1]]--;
                p1++;
            }

            ans = max(ans,p2-p1+1);
        }

        return ans;




    }
};