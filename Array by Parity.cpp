/*Sort array by Parity using two pointers*/
class Solution {

public:
    vector<int> sortArrayByParity(vector<int>& nums) {     
       int i=0;
       int j=nums.size()-1;
       while(i<j){
           if(nums[i]%2 == 0 & nums[j]%2 == 0){
               i = i+1;
           }
           else if(nums[i]%2 == 0 & nums[j]%2 != 0){
                i = i+1;
                j = j-1;   
           }
           else if(nums[i]%2 != 0 & nums[j]%2 == 0){
                swap(nums[i],nums[j]);
                i = i+1;
                j = j-1;
           }
           else{
               j = j-1;
           }
       }
        return nums;
    }
};
