class Solution {
public:
    int distributeCandies(vector<int>& candyType) {

        int n = candyType.size();
        set<int> st; // Set ...stores unique elements

        for (auto i : candyType) {
            st.insert(i);
        }
        return min((int)st.size(), n / 2);
    }
};