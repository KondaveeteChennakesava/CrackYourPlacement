class Solution {
    struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2; // Combine the two hash values
    }
};
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<int>>rows;
        unordered_map<int, unordered_set<int>>cols;
        unordered_map<pair<int, int>, unordered_set<int>, hash_pair>squares;
        for(int r=0; r<9; r++){
            for(int c=0; c<9; c++){
                if(board[r][c] != '.'){
                    int current = board[r][c] - '0';
                    if(rows[r].find(current) != rows[r].end() ||
                        cols[c].find(current) != cols[c].end() || 
                        squares[{r/3, c/3}].find(current) != squares[{r/3, c/3}].end()){
                            return false;
                        }
                    rows[r].insert(current);
                    cols[c].insert(current);
                    squares[{r/3, c/3}].insert(current);
                }
            }
        }
        return true;
    }
};