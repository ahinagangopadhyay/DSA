class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
        return 0;
        int l=0;
        unordered_set<int>set;
        int ml=INT_MIN;
        for(int r=0;r<s.size();r++)
        {
            if(set.find(s[r])!=set.end())
            {
                while(l<r&&set.find(s[r])!=set.end()){
                set.erase(s[l]);
                l++;
            }
            }
            set.insert(s[r]);
            ml=max(ml,r-l+1);
            
        }
        return ml;
        
    }
};
