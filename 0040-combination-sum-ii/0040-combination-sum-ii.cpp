class Solution {
public:
    vector<vector<int>> result;
    void helper(int idx,vector<int>& cad,int target,vector<int>&subset){
        if(target==0){
            result.push_back(subset);
            return;
        }

        if(idx == cad.size()) return;
        if(cad[idx] <= target){ // we hace two choice pick or not pick
            subset.push_back(cad[idx]);
            helper(idx+1, cad, target-cad[idx], subset);
            subset.pop_back();
        }
        int j = idx+1;
        while(j<cad.size() && cad[j]==cad[j-1]) j++;
        helper(j,cad,target,subset);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>subset;
        helper(0, candidates, target, subset);
        return result;
    }
};