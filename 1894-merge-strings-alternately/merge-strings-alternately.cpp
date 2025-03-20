class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int m = word1.length(), n = word2.length();
        int idx = 0;
        while(idx < min(m, n)){
            ans = ans + word1[idx] + word2[idx];
            idx++;
            // cout << ans << endl;
        }
        while(idx < m){
            ans += word1[idx++];
        }
        while(idx < n){
            ans += word2[idx++];
        }
        return ans;
    }
};