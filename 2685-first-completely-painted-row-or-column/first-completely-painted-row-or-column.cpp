class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        map<int, pair<int, int>> mp;
        int rows = mat.size();
        int columns = mat[0].size();
        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                mp[mat[i][j]] = make_pair(i, j);
            }
        }
        
        vector<int> rowCount(rows, 0);
        vector<int> colCount(columns, 0);

        for(int i=0; i<arr.size(); i++){
            pair<int, int>axis = mp[arr[i]];
            int currRow = axis.first;
            int currCol = axis.second;
            rowCount[currRow]++;
            colCount[currCol]++;
            if(rowCount[currRow] == columns || colCount[currCol] == rows){
                return i;
            }
        }
        return 0;
    }
};