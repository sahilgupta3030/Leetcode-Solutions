class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int unsat = 0;

        // Initial unsatisfied customers in the first 'minutes' window
        for (int i = 0; i < minutes; i++) {
            unsat += customers[i] * grumpy[i];
        }

        int maxUnsat = unsat;
        int i = 0;
        int j = minutes;

        while(j < n) {
            unsat += customers[j] * grumpy[j]; // Include current element
            unsat -= customers[i] * grumpy[i]; // Remove element going out of window
            
            maxUnsat = max(maxUnsat, unsat);   // Update maxUnsat
            i++;
            j++;
        }

        int totalCustomers = maxUnsat;

        // Calculate total satisfied customers
        for (int i = 0; i < n; i++) {
            totalCustomers += customers[i] * (1 - grumpy[i]);
        }

        return totalCustomers;
    }
};