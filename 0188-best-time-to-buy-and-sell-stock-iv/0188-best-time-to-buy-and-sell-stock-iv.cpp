class Solution {
public:
    int dp[1005][105][2]; //initializing 3d dp
    int helper(vector<int>& prices,int i, int k, bool on){
        if(i==prices.size())return 0;
        if(dp[i][k][on] != -1) return dp[i][k][on];
        int ans = INT_MIN;
        ans = helper(prices,i+1,k,on); //avoid
        
        if(on){ //we can buy
            ans = max(ans, prices[i]+helper(prices,i+1,k-1,false));
        }
        else{
            if(k>0){ //can sell
                ans = max(ans, helper(prices,i+1,k,true)-prices[i]);
            }
        }
        return dp[i][k][on] = ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1, sizeof dp); //to resize array
        return helper(prices,0,k,false);
    }
};