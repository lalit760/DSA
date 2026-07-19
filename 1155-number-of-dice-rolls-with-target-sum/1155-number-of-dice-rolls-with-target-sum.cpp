class Solution {
public:
    const int MOD= 1000000007;
    int solve(int n, int k, int target, vector<vector<int>>&dp){
        // if(n==0 && target==0) return 1;
        // if(n==0 && target!=0) return 0;
        if(n==0){
            return target==0; //it will return 1 for success, otherwise return 0
        }
        if(target < 0) return 0;

        if(dp[n][target] != -1) return dp[n][target];

        dp[n][target] = 0;
        for(int i=1;i<=k;i++){
            // dp[n][target] += solve(n-1,k, target-i, dp) % MOD;
            dp[n][target] = (dp[n][target] + solve(n-1,k, target-i, dp)) % MOD; //instead of above line use this one
        }
        return dp[n][target];

    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1, vector<int>(target+1, -1)); //2d dp vector initilized
        
        return solve(n,k,target,dp);
    }
};