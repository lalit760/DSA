class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int comp = target-nums[i];
            if(m.find(comp) != m.end()){
                return {m[comp],i};
            }
            else m[nums[i]]=i;
        }
        return {};
    }
};