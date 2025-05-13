class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        if(fruits.size()==1)
        return 1;
        unordered_map<int,int>mp;
        int maxi=INT_MIN;
        int left=0;
        for(int r=0;r<fruits.size();r++)
        {
            mp[fruits[r]]++;
            while(mp.size()>2)
            {
                mp[fruits[left]]--;
   if(mp[fruits[left]]==0) mp.erase(fruits[left]);
                left++ ;
            }
             maxi = max(r-left+1 , maxi);
        }
     
        return maxi ;   
    }
};
