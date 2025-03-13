class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n, 0);
        int k = bookings.size();
        for(int i=0; i<k; i++){
            int start = bookings[i][0] - 1;
            int end = bookings[i][1] - 1;
            int val = bookings[i][2];
            while(start <= end){
                ans[start] += val;
                start++;
            }
        }
        return ans;
    }
};