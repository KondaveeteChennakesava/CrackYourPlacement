class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        if(blocks.size() == k){
            int count = 0;
            for(int i=0; i<blocks.size(); i++){
                if(blocks[i] == 'W')count++;
            }
            return count;
        }
        int Min = INT_MAX;
        for(int i=0; i<blocks.size()-k+1; i++){
            int count = 0;
            for(int j=i; j<k+i; j++){
                if(blocks[j] == 'W')count++;
                // cout << blocks[j] << " ";
            }
            // cout << endl;
            Min = (Min > count ? count : Min);
        }
        return Min;
    }
};