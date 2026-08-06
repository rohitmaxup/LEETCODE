class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        vector<int> nge(nums2.size());
        stack<int> helper;

        for(int i = nums2.size() - 1; i >= 0; i--)
        {
            int element = nums2[i];

            if(helper.empty())
            {
                nge[i] = -1;
                helper.push(element);
                continue;
            }

            if(helper.top() > element)
            {
                nge[i] = helper.top();
                helper.push(element);
                continue;
            }

            while(!helper.empty() && helper.top() <= element)
            {
                helper.pop();
            }

            if(helper.empty())
                nge[i] = -1;
            else
                nge[i] = helper.top();

            helper.push(element);
        }

        unordered_map<int, int> mp;

        for(int i = 0; i < nums2.size(); i++)
        {
            mp[nums2[i]] = nge[i];
        }

        vector<int> ans;

        for(int x : nums1)
        {
            ans.push_back(mp[x]);
        }

        return ans;
    }
};