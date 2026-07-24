class Solution {
public:
    vector<vector<int>>dp;
    int helper(vector<int>& coins, int amt, int i, int sum){
        if(sum==amt) return 0;
        if(i==coins.size()) return INT_MAX;

        if(sum+coins[i] > amt){
            return dp[i][sum] = helper(coins,amt,i+1,sum);
        }
        if(dp[i][sum] != -1) return dp[i][sum];

        else{
            int take = helper(coins, amt, i, sum + coins[i]);
            if (take != INT_MAX) take++;               
            int leave = helper(coins,amt,i+1,sum);

            return dp[i][sum] = min(take,leave);
        }
        
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp.resize(n, vector<int>(amount+1,-1));
        sort(coins.begin(),coins.end());
        reverse(coins.begin(),coins.end());
        int ans = helper(coins,amount,0,0);

        return (ans==INT_MAX) ? -1 : ans;
    }
};