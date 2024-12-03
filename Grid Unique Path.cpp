/*62. Unique Paths

There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.*/

 class Solution {
public:
int count(int m,int n,vector<vector<int>>&dp)
{
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(i==0&&j==0)
            {
                dp[i][j]=1;
                continue;
            }
            int up=0;
            int left=0;
            if(i>0)
            up=dp[i-1][j];
            if(j>0)
            left=dp[i][j-1];
            dp[i][j]=up+left;
        }
    }
    return dp[m-1][n-1];

}
    int uniquePaths(int m, int n) {
   vector<vector<int>> dp(m, vector<int>(n, -1));
    return count(m, n, dp);

    }
};
