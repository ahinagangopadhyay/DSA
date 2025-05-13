class Solution {
public:
int countatmost(vector<int>&nums,int goal){
 if(goal<0)return 0;
        int l=0,r=0,sum=0,c=0;
        while(r<nums.size())
        {
            sum+=nums[r];
            while(sum>goal)
            {
                sum-=nums[l];
                l++;
            }
            c+=r-l+1;
            r++;
        }
        return c;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return (countatmost(nums,goal)-countatmost(nums,goal-1));
    }
};
