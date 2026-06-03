class Solution {
public:
vector<vector<int>> sortTheStudents (vector<vector<int>>& arr, int k)
{
int m = arr.size();
for(int i = 0 ; i<m; i++)
{
for(int j = i + 1; j<m; j++)
{
if(arr[i][k] < arr[j][k]) swap(arr[i], arr[j]);
}
}
return arr;
}
};