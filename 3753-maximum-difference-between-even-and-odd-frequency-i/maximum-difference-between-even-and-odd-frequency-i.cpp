class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26);
        for(int i=0; i<s.size(); i++){
            freq[s[i] - 'a']++;
        }
        int maxOdd = 0;
        int minEven = s.size();
        for(auto it: freq){
            cout << it << " ";
            int num = it;
            if(num != 0){
                if(num%2!=0){
                    if(num > maxOdd){
                        maxOdd = num;
                    }
                }else{
                    if(num < minEven){
                        minEven = num;
                    }
                }
            }
        }
        return maxOdd - minEven;
    }
};