#include <vector>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int circularSandwiches = 0;
        int squareSandwiches = 0;

        // Count the number of students preferring each type of sandwich
        for (int student : students) {
            if (student == 0) {
                ++circularSandwiches;
            } else {
                ++squareSandwiches;
            }
        }

        // Serve sandwiches to students
        for (int sandwich : sandwiches) {
            if (sandwich == 0) {
                if (circularSandwiches == 0) {
                    return squareSandwiches;
                }
                --circularSandwiches;
            } else {
                if (squareSandwiches == 0) {
                    return circularSandwiches;
                }
                --squareSandwiches;
            }
        }

        return circularSandwiches + squareSandwiches;
    }
};
