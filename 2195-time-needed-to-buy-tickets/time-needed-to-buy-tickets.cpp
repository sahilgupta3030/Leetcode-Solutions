class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size(); // Size of tickets array
        queue<int> q; // Queue for people buying tickets

        for (int i = 0; i < n; ++i) {
            q.push(i); // Initialize queue
        }

        int times = 0; // Total time taken

        while (true) {
            bool allBought = true; // Check if all tickets bought
            for (int i = 0; i < n; ++i) {
                if (tickets[i] > 0) { // Check if tickets left
                    allBought = false;
                    break;
                }
            }
            if (allBought) // Break if all tickets bought
                break;

            int curr = q.front(); // Current person
            q.pop(); // Remove from queue
            int ticketsToBuy = min(tickets[curr], 1); // Buy one ticket at a time
            times += ticketsToBuy; // Update time
            tickets[curr] -= ticketsToBuy; // Update tickets count
            if (curr == k && tickets[curr] == 0) // If person at k bought all tickets
                break;
            if (tickets[curr] > 0) // Add back to queue if tickets left
                q.push(curr);
        }
        return times; // Return total time taken
    }
};
