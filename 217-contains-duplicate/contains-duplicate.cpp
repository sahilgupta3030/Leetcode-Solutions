class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Sets in C++ store only unique elements
        set<int> s(nums.begin(),nums.end());
        int x=nums.size();
        int y=s.size();

        if(x==y){
            return false;
        }
        else{
            return true;
        }
    }
};