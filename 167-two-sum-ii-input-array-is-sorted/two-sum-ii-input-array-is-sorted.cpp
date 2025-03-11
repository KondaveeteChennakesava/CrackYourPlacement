class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int left = 0, right = n-1;
        while(left <= right){
            int sum = numbers[left] + numbers[right];
            // cout << left << " " << right << " " << sum << endl;
            if(sum == target)return {left+1, right+1};
            else if(target > sum)left++;
            else right--;
        }
        return {left+1, right+1};
    }
};