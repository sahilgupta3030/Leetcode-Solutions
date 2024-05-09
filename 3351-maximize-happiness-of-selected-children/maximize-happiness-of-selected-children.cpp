class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        // sort in descending order
        sort(happiness.rbegin(), happiness.rend());

        long long result = 0;         
        int count = 0;   
                     
        for (int i = 0; i < k; i++) { 
            result += max(happiness[i] - count, 0);
            count++; 
        }
        return result;
    }
};
