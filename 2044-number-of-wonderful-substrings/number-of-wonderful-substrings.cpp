class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long ans=0;
        vector<int>cnt(1024,0);
        cnt[0]=1;
        int mask=0;
        for(auto c: word)
        {
            mask= mask ^ (1<<(c-'a'));
            ans+=cnt[mask];
          
            for(int i=0;i<10;i++)
            {
               int newmask= mask ^ (1<<i);
                ans+=cnt[newmask];
            }
            cnt[mask]++;
        }
        return ans;
    }
};