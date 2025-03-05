class Solution {
public:
    long long ans = 0;
    long long coloredCells(int n) {
        if(n == 1)return 1;
        ans = ans + ((n-1) * 4) + coloredCells(n-1);
        return ans;
    }
};