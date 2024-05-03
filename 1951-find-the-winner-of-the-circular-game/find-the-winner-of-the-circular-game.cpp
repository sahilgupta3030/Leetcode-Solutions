class Solution {
public:
    // Recursive function to find the winner's index in a circle of n people
    int winner(int n, int k){
        if(n == 1) return 0; // Base case: Only one person left
        // Calculate winner's index for n-1 people, add k, and take modulo n
        return (winner(n - 1, k) + k) % n;
    }
    
    // Finds the winner's index (1-based) given the number of people (n) 
    // and the count to skip (k)
    int findTheWinner(int n, int k) {
        return winner(n, k) + 1; // Add 1 to convert 0-based index to 1-based
    }
};
