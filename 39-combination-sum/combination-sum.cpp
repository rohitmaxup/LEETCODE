class Solution {
public:


    void solve(vector<int>&candidates, int idx , int target , vector<int>& current , vector<vector<int>> &ans)
    {
        if(target == 0)
        {
            ans.push_back(current);
            
            
            return ; 
       }

       if(idx == candidates.size() || target < 0)
       {
        return ;
       }



       current.push_back(candidates[idx]);
       
       solve(candidates,idx,target-candidates[idx],current,ans);

       current.pop_back();


       solve(candidates,idx+1,target,current,ans);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;

        solve(candidates , 0 , target , current , ans);

        return ans;
    }
};