class Solution {
public:
    vector<vector<int>>dp;
    int helper(vector<int>& nums, int target,int i,int sum){
        if(sum==target) return 0; //we reached the target so we need 0 more elements
        if(i==nums.size()) return -1;
        
        if(dp[i][sum] != -2) return dp[i][sum];
        if(sum+nums[i] > target){ //can leave only
            return dp[i][sum] = helper(nums,target,i+1,sum);
        }
        else{
            int take = helper(nums, target,i+1, sum+nums[i]);
            if(take!=-1) take++;
            int leave = helper(nums,target,i+1,sum);

            return dp[i][sum] = max(take,leave);
        }
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        dp.resize(n, vector<int>(target+1,-2));
        int ans = helper(nums,target,0,0);
        return ans;
    }
};