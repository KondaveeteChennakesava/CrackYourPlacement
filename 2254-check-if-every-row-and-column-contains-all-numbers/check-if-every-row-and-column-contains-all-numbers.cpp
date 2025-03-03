class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int r=0; r<n; r++){
            vector<int>cnt(n+1, 0);
            for(int c=0; c<n; c++){
                int num = matrix[r][c];
                cnt[num]++;
                if(cnt[num] > 1)return false;
            }
        }
        for(int r=0; r<n; r++){
            vector<int>cnt(n+1, 0);
            for(int c=0; c<n; c++){
                int num = matrix[c][r];
                cnt[num]++;
                if(cnt[num] > 1)return false;
            }
        }
        return true;
    }
};