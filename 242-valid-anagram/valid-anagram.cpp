class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> s1(26, 0);
        vector<int> t1(26, 0);
        for(int i=0; i<s.size(); i++)s1[s[i] - 'a']++;
        for(int i=0; i<t.size(); i++)t1[t[i] - 'a']++;
        return s1==t1;
    }
};