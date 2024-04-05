class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Sorting the array
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == nums[i + 1])
                return true;
        }
        return false;
    }
};

// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         // Sets in C++ store only unique elements
//         set<int> s(nums.begin(),nums.end());
//         int x=nums.size();
//         int y=s.size();

//         if(x==y){
//             return false;
//         }
//         else{
//             return true;
//         }
//     }
// };
