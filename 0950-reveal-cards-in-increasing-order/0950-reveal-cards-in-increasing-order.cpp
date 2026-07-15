class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        queue<int>q;
        vector<int>ans(n,0);
        sort(deck.begin(),deck.end());

        for(int i=0;i<n;i++){ //    imp
            q.push(i);
        }
        int i=0;
        while(i<n && q.size()>0){
            ans[q.front()] = deck[i];
            i++;
            q.pop();
            q.push(q.front());
            q.pop();
        }
        return ans;

    }
};