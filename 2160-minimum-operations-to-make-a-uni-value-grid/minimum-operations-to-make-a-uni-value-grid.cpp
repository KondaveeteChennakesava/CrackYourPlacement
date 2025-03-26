class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> ans;
        int total = 0;
        int rem = grid[0][0]%x;
        for(auto ele: grid){
            for(auto it: ele){
                if(rem != it%x)return -1;
                ans.push_back(it);
                total += it;
            }
        }
        int res = INT_MAX;
        int prefix = 0;
        sort(ans.begin(), ans.end());
        for(int i=0; i<ans.size(); i++){
            int l = ans[i] * i - prefix;
            int r = total - prefix - (ans[i] * (ans.size() - i));
            int op = (l + r) / x;
            res = min(res, op);
            prefix += ans[i];
        }
        return res;
    }
};