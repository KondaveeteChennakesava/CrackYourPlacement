class Solution {
public:
    int assign(char c){
        if(c == 'N')return 0;
        if(c == 'S')return 1;
        if(c == 'E')return 2;
        if(c == 'W')return 3;
        return -1;
    }
    
    int findMax(vector<int>&cnt, int k){
        int result = 0;
        
        int mx = max(cnt[0], cnt[1]);
        int my = min(cnt[0], cnt[1]);
        int rem = min(my, k);
        mx += rem;
        my -= rem;
        k -= rem;
        result += (mx - my);
        mx = max(cnt[2], cnt[3]);
        my = min(cnt[2], cnt[3]);
        rem = min(my, k);
        mx += rem;
        my -= rem;
        k -= rem;
        result += (mx - my);
        return result;
    }
    int maxDistance(string s, int k) {
        vector<int> cnt(4);
        int ans = 0;
        for(int i=0; i<s.size();i++){
            cnt[assign(s[i])]++;
            ans = max(ans, findMax(cnt, k));
        }
        return ans;
    }
};