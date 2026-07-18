class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<bool>>obstacle(m,vector<bool>(n,true));
        vector<vector<long long>>dp(m,vector<long long>(n,0));

        if(obstacleGrid[m-1][n-1] == 1 || obstacleGrid[0][0] == 1) return 0;
        dp[m-1][n-1] = 1;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j] == 1){
                    obstacle[i][j] = false;
                }
            }
        }
        // if(obstacle[m-1][n-1] == false || obstacle[0][0] == false) return 0;
        

        for(int i=m-2;i>=0;i--){
            if(!obstacle[i][n-1]) break;
            dp[i][n-1]= dp[i+1][n-1];
        }
        for(int j=n-2;j>=0;j--){
            if(!obstacle[m-1][j]) break;
            dp[m-1][j]=dp[m-1][j+1];
        }

        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                if(obstacle[i][j]){
                    dp[i][j] = dp[i][j+1] + dp[i+1][j];
                }
            }
        }
        return dp[0][0];
    }
};