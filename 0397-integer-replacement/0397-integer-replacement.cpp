class Solution {
public:
    int solve(long long n,  unordered_map<long long, int> &dp){
        if(n==1)return 0;
        
        if(dp.count(n)) return dp[n]; //if n is already there in the map then return it

        if(n%2==0) dp[n] = 1 + solve(n/2,dp);
       
        else dp[n] = 1 + min(solve(n-1,dp),solve(n+1,dp));

        return dp[n];
        
    }
    int integerReplacement(int n) {
        unordered_map<long long, int> dp;
        // vector<long long>dp(n+2, -1);  // can't use vector due to MLE
        return solve(n,dp);
    }
};