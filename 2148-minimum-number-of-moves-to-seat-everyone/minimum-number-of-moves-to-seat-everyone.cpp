class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        vector<int> studentFreq(101, 0);
        vector<int> seatLoc(101, 0);

        // Count the frequency of each seat location
        for (int loc : seats) {
            seatLoc[loc]++;
        }

        // Count the frequency of each student location
        for (int student : students) {
            studentFreq[student]++;
        }

        int ans = 0, j = 0;

        // Calculate the minimum moves
        for (int i = 0; i < seatLoc.size(); i++) {
            if (seatLoc[i] == 0)
                continue;
            while (studentFreq[j] == 0)
                j++;
            ans += abs(i - j);
            studentFreq[j]--;
            seatLoc[i]--;
            if (seatLoc[i] != 0)
                i--;
        }

        return ans;
    }
};