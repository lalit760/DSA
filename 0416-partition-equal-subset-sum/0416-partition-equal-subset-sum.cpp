class Solution {
public:
    vector<vector<int>>dp;
    bool check(vector<int>& nums, int idx, int n,int sum, int target){
        if(idx == n){
            if(sum==target) return true;
            else return false;
        }
        if(sum==target) return dp[idx][sum] = true;
        if(dp[idx][sum] != -1) return dp[idx][sum];
        if((sum+nums[idx]) > target) return dp[idx][sum] = check(nums,idx+1,n,sum,target); //only leave

        else{
            bool take = check(nums,idx+1,n,sum+nums[idx],target);
            bool leave = check(nums,idx+1,n,sum,target);

            return dp[idx][sum] = take || leave;
        }
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum=0;
        for(int ele:nums) totalSum += ele;
        if(totalSum % 2 != 0) return false;
        int target = totalSum/2;
        dp.resize(n,vector<int>(target+1, -1));

        return check(nums,0,n,0,target);
    }
};