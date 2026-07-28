class Solution {
public:
    int helper(int n){
        int sum=0;
        if(n==0 || n==1)return 1;
        if(n==2)return 2;

        for(int i=1;i<=n;i++){
            int lst = helper(i-1); //no of ways to make lst
            int rst = helper(n-i); //no. of ways to make rst
            sum += lst*rst;
        }
        return sum;
    }
    int numTrees(int n) {
        return helper(n);
    }
};