class Solution {
public:
    int numberOfSubarrays(std::vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> count(size + 1, 0); 
        count[0] = 1; 

        int answer = 0; 
        int oddCount = 0; 

        for (int num : nums) {
            oddCount += num & 1;
            if (oddCount >= k) {
                answer += count[oddCount - k];
            }
            count[oddCount]++; 
        }
      
        return answer; 
    }
};