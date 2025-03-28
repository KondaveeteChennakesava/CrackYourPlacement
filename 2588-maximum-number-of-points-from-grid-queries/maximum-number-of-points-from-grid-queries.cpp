class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size(), k = queries.size();
        
        vector<pair<int, int>>query(k);
        vector<int> ans(k);

        for(int i=0; i<k; i++){
            query[i] = {queries[i], i};
        }
        sort(query.begin(), query.end());

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>minh;

        minh.push({grid[0][0], 0, 0});
        vis[0][0] = true;
        int cnt = 0;

        for(auto &q: query){
            while(minh.size() > 0){
                auto[val, i, j] = minh.top();
                if(val >= q.first){
                    break;
                }
                minh.pop();
                cnt++;
                if(i-1 >=0 and vis[i-1][j] == false)
                    minh.push({grid[i-1][j], i-1, j}), vis[i-1][j] = true;
                if(j-1 >=0 and vis[i][j-1] == false)
                    minh.push({grid[i][j-1], i, j-1}), vis[i][j-1] = true;
                if(i+1 < m and vis[i+1][j] == false)
                    minh.push({grid[i+1][j], i+1, j}), vis[i+1][j] = true;
                if(j+1 < n and vis[i][j+1] == false)
                    minh.push({grid[i][j+1], i, j+1}), vis[i][j+1] = true;
            }
            ans[q.second] = cnt;
        }
        return ans;
    }
};