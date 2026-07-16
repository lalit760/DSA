class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        int n = start.size();
        int i=0,j=0;
        int rooms=0;
        int ans=0;
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        while(i<n){
            
            if(start[i] < end[j]){
                rooms++;
                ans = max(ans,rooms);
                i++;
            }
            else if(start[i] > end[j]){
                rooms--;
                ans = max(ans,rooms);
                j++;
            }
            else{
                i++;
                j++;
            }
            
        }
        return ans;
    }
};
