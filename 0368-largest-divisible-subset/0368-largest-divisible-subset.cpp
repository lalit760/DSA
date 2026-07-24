class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
        int count=1;
        int maxIndex=0;
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i] % nums[j] == 0){
                    dp[i] += dp[j];
                    break;
                }
            }
        }
        int ultimate = nums[0];
        for(int i=1;i<n;i++){
            if(dp[i]>dp[i-1]){
                ultimate = nums[i];
            }
        }
        vector<int>ans;
        if(ultimate % nums[0] == 0) ans.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(ultimate % nums[i] == 0){
                if(ans.size()==0){
                    ans.push_back(nums[i]);
                }
                else if(nums[i]%ans[ans.size()-1]==0){
                    ans.push_back(nums[i]);
                }
                
            }
        }
        return ans;
    }
};