class Solution {
    bool canPlace(int &mid, vector<int> &nums, int &k){
        int idx = 0;
        int count = 0;
        while(idx < nums.size()){
            if(nums[idx] <= mid){
                count++;
                idx += 2;
            }else{
                idx += 1;
            }
            if(count >= k)return true;
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