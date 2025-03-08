class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> items = nums;
        int size = 0;
        for(auto it: nums){
            items.push_back(it);
            if(it)size++;
        }
        int cnt = 0, ans = INT_MAX;
        for(int i=0; i<items.size(); i++){
            if(items[i] == 1)cnt++;
            if(i-size>=0 && items[i-size]==1)cnt--;
            ans = min(ans, size-cnt);
        }
        return ans; 
    }
};