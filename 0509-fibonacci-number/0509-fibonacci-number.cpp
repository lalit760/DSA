class Solution {
public:
    int solve(int n, vector<int>&dp){
        if(n<=1) return n; //base case
        
        else if(dp[n] != -1){
            return dp[n]; //if ans already stored then simply return it
        }
        return dp[n] = solve(n-1,dp) + solve(n-2,dp); //returning and storing at the sametime int he array
    }
    
    int fib(int n) {
        vector<int>dp(n+1, -1);
        return solve(n, dp);
    }
};