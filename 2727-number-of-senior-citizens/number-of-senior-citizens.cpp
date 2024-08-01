class Solution {
public:
    int countSeniors(vector<string>& details) {
        int seniorCount = 0;

        for (const auto& detail : details) {
            int age = stoi(detail.substr(11, 2));
            seniorCount += (age > 60) ? 1 : 0;
        }

        return seniorCount;
    }
};
