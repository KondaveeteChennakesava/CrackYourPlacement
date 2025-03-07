class Solution {
private:
    void fillPrimes(vector<int>& prime, int high){
        bool ck[high + 1];
        memset(ck, true, sizeof(ck));
        ck[1] = false;
        ck[0] = false;
        for (int i = 2; (i * i) <= high; i++) {
            if (ck[i] == true) {
                for (int j = i * i; j <= sqrt(high); j = j + i) {
                    ck[j] = false;
                }
            }
        }
        for (int i = 2; i * i <= high; i++) {
            if (ck[i] == true) {
                prime.push_back(i);
            }
        }
}
public:
    vector<int> closestPrimes(int low, int high) {
        if (low<2 and high>=2){
            low = 2;
        }
        bool prime[high - low + 1];
        memset(prime, true, sizeof(prime));
    
        vector<int> chprime;
        fillPrimes(chprime, high);
        for (int i : chprime) {
            int lower = (low / i);        
            if (lower <= 1) {
                lower = i + i;
            }
            else if (low % i) {
                lower = (lower * i) + i;
            }
            else {
                lower = (lower * i);
            }
            for (int j = lower; j <= high; j = j + i) {
                prime[j - low] = false;
            }
        }
        vector<int>ans;
        for (int i = low; i <= high; i++) {
            if (prime[i - low] == true) {
                ans.push_back(i);
                cout << i << endl;
            }
        }
        if(ans.size() < 2)return {-1, -1};
        vector<int> finalAns;
        int diff = INT_MAX;
        for(int i=0; i<ans.size()-1; i++){
            int currDiff = ans[i+1] - ans[i];
            if(currDiff < diff){
                diff = currDiff;
                finalAns = {ans[i], ans[i+1]};
            }
        }
        return finalAns;
    }
};