class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;
        for (int i = 0; i < tickets.size(); i++)
            q.push(i);

        int timer = 0;

        while (true) {
            if (tickets[k] == 0) break; 
            int curr = q.front();
            tickets[curr]--;
            timer++;
            q.pop();
            if (tickets[curr] != 0)
                q.push(curr);
        }
        return timer;
    }
};
