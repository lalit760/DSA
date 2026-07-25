class Solution {
public:
    vector<vector<int>>dp;
    int helper(int amt,vector<int>& coins, int i, int sum){
        if(sum==amt)return 1;
        if(i==coins.size()) return 0;

        if(dp[i][sum] != -1) return dp[i][sum];
        if(sum + coins[i] > amt) return dp[i][sum] = helper(amt,coins,i+1,sum);
        else{
            int take = helper(amt,coins,i,sum+coins[i]);
            int leave = helper(amt,coins,i+1,sum);

            return dp[i][sum] = (take+leave);
        }
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        sort(coins.begin(),coins.end());
        dp.resize(n,vector<int>(amount+1,-1));
        int ans = helper(amount,coins,0,0);
        return ans;
    }
};