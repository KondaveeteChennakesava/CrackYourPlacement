class Solution {
public:
    long long ans = 0;
    long long coloredCells(int n) {
        long long ans = 1 + (long long)2 * n * (n-1);
        return ans;
    }
};