class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        vector<int> res(deck.size());
        deque<int> q;
        for (int i = 0; i < deck.size(); ++i)
            q.push_back(i);

        for (int n : deck) {
            int i = q.front();
            q.pop_front();
            res[i] = n;
            if (!q.empty()) {
                q.push_back(q.front());
                q.pop_front();
            }
        }

        return res;
    }
};