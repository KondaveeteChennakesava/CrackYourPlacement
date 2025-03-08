class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans = INT_MAX;
        int cnt = 0;
        for(int i=0; i<blocks.size(); i++){
            if(blocks[i] == 'B')cnt++;
            if(i-k>=0 && blocks[i-k]=='B')cnt--;
            ans = min(ans, k-cnt);
        }
        return ans;
    }
};