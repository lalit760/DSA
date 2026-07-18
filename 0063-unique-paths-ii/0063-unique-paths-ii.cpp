class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<bool>>obstacle(m,vector<bool>(n,true));
        vector<vector<long long>>dp(m,vector<long long>(n,0)); //have to use long long

        if(obstacleGrid[m-1][n-1] == 1 || obstacleGrid[0][0] == 1) return 0; //special case
        dp[m-1][n-1] = 1;       

        // for last column
        for(int i=m-2;i>=0;i--){
            if(obstacleGrid[i][n-1] == 1) break;
            dp[i][n-1]= dp[i+1][n-1];
        }

        // for last row
        for(int j=n-2;j>=0;j--){
            if(obstacleGrid[m-1][j] == 1) break;
            dp[m-1][j]=dp[m-1][j+1];
        }

        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                if(obstacleGrid[i][j] == 0){ //ignoring obstacles
                    dp[i][j] = dp[i][j+1] + dp[i+1][j];
                }
            }
        }
        return dp[0][0];
    }
};