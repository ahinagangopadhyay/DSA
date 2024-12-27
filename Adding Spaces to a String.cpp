class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string s1 = "";
        int j = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (j < spaces.size() && i == spaces[j]) {
                s1.push_back(' ');  
                j++;  
            }
            s1.push_back(s[i]);  
        }
        
        return s1;
    }
};
