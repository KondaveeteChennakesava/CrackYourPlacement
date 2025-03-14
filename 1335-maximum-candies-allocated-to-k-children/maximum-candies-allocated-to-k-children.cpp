class Solution {
    #define ll long long
    bool canAssign(ll &mid, vector<int>& candies, ll &k){
        ll count = 0;
        for(ll it: candies){
            if(it >= mid) count += it/mid;
        }
        return count >= k;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        ll low = 1;
        ll high = *max_element(candies.begin(), candies.end());
        ll mid;
        ll ans = 0;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(canAssign(mid, candies, k)){
                ans = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return ans;
    }
};