class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        return recursive(numbers, target, 0, numbers.size()-1);
    }
    
    vector<int> recursive(vector<int>& numbers, int target, int i, int j) {
        if (i >= j) {
            return {};
        }
        
        if (numbers[i] + numbers[j] == target) {
            return {i+1, j+1};
        }
        
        if (numbers[i] + numbers[j] > target) {
            return recursive(numbers, target, i, j-1);
        } else {
            return recursive(numbers, target, i+1, j);
        }
    }
};


// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target) {
//         int i = 0, j = numbers.size()-1;

//         while(i < j) {
//             if(numbers[i]+numbers[j] == target) {
//                 return {i+1, j+1};
//             }

//             if(numbers[i]+numbers[j] > target)
//                 j--;
//             else
//                 i++;
//         }
//         return {};
//     }
// };