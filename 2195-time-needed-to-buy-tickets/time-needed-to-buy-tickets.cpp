class Solution {
 public:
  int timeRequiredToBuy(vector<int>& tickets, int k) {
    int ans = 0;

    for (int i = 0; i < tickets.size(); ++i)
      if (i <= k)
        ans += min(tickets[i], tickets[k]);
      else
        ans += min(tickets[i], tickets[k] - 1);

    return ans;
  }
};


// // 2nd approach
// class Solution {
// public:
//     int timeRequiredToBuy(vector<int>& tickets, int k) {
//         int time = 0;
//         for (int i = 0; i < tickets.size(); i++) {
//             if (tickets[i] < tickets[k]) {
//                 time += tickets[i];
//             } else {
//                 time += tickets[k];
//             }

//             if (i > k && tickets[i] >= tickets[k]) {
//                 time--;
//             }
//         }
//         return time;
//     }
// };

// // Naive approach
// class Solution {
// public:
//     int timeRequiredToBuy(vector<int>& tickets, int k) {
//         queue<int> q;
//         for (int i = 0; i < tickets.size(); i++)
//             q.push(i);

//         int timer = 0;

//         while (true) {
//             if (tickets[k] == 0) break;
//             int curr = q.front();
//             tickets[curr]--;
//             timer++;
//             q.pop();
//             if (tickets[curr] != 0)
//                 q.push(curr);
//         }
//         return timer;
//     }
// };
