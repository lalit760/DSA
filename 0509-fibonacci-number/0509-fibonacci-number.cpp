class Solution {
public:
    // RECURSSION AND MEMOIZATION
    // int solve(int n, vector<int>&dp){
    //     if(n<=1) return n; //base case
        
    //     else if(dp[n] != -1){
    //         return dp[n]; //if ans already stored then simply return it
    //     }
    //     return dp[n] = solve(n-1,dp) + solve(n-2,dp); //returning and storing at the sametime int he array
    // }
    
    int fib(int n) {
        // vector<int>dp(n+1, -1);
        // return solve(n, dp);

        // TABULATION
        if(n==0 || n==1) return n;
        vector<int>dp(n+1,0);
        dp[0]=0; 
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};