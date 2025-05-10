/*You are given two arrays nums1 and nums2 consisting of positive integers.

You have to replace all the 0's in both arrays with strictly positive integers such that the sum of elements of both arrays becomes equal.

Return the minimum equal sum you can obtain, or -1 if it is impossible.*/

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
    long long s1=0,s2=0;
    long long z1=0,z2=0;
    for(int n:nums1)
    {
            if (n == 0) z1++;
            s1 += n;
    }
       for(int n:nums2)
    {
            if (n == 0) z2++;
            s2 += n;
    }
    if(z1==0&&z2==0)
    return s1==s2?s1:-1;
    else if(z1==0)
    return s2+z2<=s1?s1:-1;
    else if(z2==0)
    return s1+z1<=s2?s2:-1;
    
    return(max(s1+z1,s2+z2));
    }
};
