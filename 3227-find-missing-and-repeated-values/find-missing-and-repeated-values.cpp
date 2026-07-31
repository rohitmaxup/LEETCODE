class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        
        int missing = 0;
        int repeated = 0;

        vector<int> hash(n * n + 1, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                hash[grid[i][j]]++;              
            }
        }

        for (int i = 1; i <= n * n; i++) {       
            if (hash[i] > 1) {
                repeated = i;                   
            }
            if (hash[i] == 0) {
                missing = i;                
            }
        }

        return {repeated, missing};
    }
};