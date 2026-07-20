class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        vector<long long>dp(n+1, 0);
        dp[0]=0; dp[1]=1; dp[2]=1; dp[3]=2;
        if(n<=3) return dp[n];
        for(int i=4;i<=n;i++){
            dp[i] = dp[i-1]*2 - dp[i-4];
        }
        return dp[n];
    }
};