class Solution {
    bool canPlace(int &mid, vector<int> &nums, int k){
        int n = nums.size();
        int idx = 0;
        while(idx < n){
            if(nums[idx] <= mid){
                k--;
                idx += 2;
            }else{
                idx += 1;
            }
            if(k == 0)return true;
        }
        return false;
    }
public:
    int minCapability(vector<int>& nums, int k) {
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        int ans = -1;
        int mid;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(canPlace(mid, nums, k)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};