class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& v) {
        sort(v.begin(),v.end());
        queue<int>q;
        int n=v.size();
        for(int i=0;i<n;i++) {
            q.push(i);
        }
        vector<int>ans(n,0);
        int i=0;
        while(!q.empty()) {
            int k=q.front();
            ans[k]=v[i];
            q.pop();
            if(!q.empty()) {
                int x=q.front();
                q.push(x);
                q.pop();
            }
            i++;
        }
        return ans;
    }
};