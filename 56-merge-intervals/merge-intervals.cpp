class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mi;
        sort(intervals.begin(), intervals.end());
        int s = intervals[0][0];
        int e = intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            int cs = intervals[i][0], ce = intervals[i][1];
            if(cs <= e){
                e = max(e, ce);
                s = min(s, cs);
            }else{
                mi.push_back({s, e});
                s = cs;
                e = ce;
            }
        }
        mi.push_back({s, e});
        return mi;
    }
};