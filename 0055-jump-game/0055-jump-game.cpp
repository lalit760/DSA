class Solution {
public:
    bool canJump(vector<int>& nums) {
        // BOTTOM-UP DP
        int n = nums.size();
        // vector<bool> dp(n, false);
        // dp[n-1] = true;
        // for(int i=n-2;i>=0;i--){
        //     if(nums[i] != 0){
        //         for(int j=1;j<=nums[i];j++){
        //             if(dp[i+j]==true){
        //                 dp[i] = true; break;
        //             }
        //         }
        //     }   
        // }
        // return dp[0];

        //Greedy
        int goal = n-1;
        for(int i=n-2;i>=0;i--){ //travelling form 2nd last to oth index
            if(i + nums[i] >= goal){ //checking if it is possilbe to achieve goal index from that index
                goal = i;
            }
        }
        return goal==0;
    }
};