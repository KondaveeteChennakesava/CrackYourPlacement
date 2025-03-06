class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int originalSum = ((n * n)*((n * n)+1))/2;
        unordered_set<int> st;
        int totalSum = 0;
        int repeating = -1;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(st.find(grid[i][j]) != st.end()){
                    repeating = grid[i][j];
                    continue;
                }
                totalSum += grid[i][j];
                st.insert(grid[i][j]);
            }
        }
        // cout << originalSum << " " << totalSum;
        return {repeating, originalSum-totalSum};
    }
};