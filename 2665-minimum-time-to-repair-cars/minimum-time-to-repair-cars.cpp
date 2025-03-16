class Solution {
    #define ll long long
    bool canDo(ll &time, vector<int> &ranks, int &cars){
        ll count = 0;
        for(int rank: ranks){
            count += sqrt(time / rank);
        }
        return count >= cars;
    }
public:
    long long repairCars(vector<int>& ranks, int cars) {
        ll low = 1;
        ll high = (ll)*min_element(ranks.begin(), ranks.end()) * cars * cars;
        ll mid, ans = -1;
        while(low <= high){
            mid = low + (high - low) / 2;
            // cout << low << " " << mid << " " << high << endl;
            if(canDo(mid, ranks, cars)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};