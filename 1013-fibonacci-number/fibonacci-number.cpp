// class Solution {
// public:
//     int fib(int n) {
//         if(n<2)
//         return n;
//         return fib(n-1)+fib(n-2);
//     }
// };

class Solution {
public:
    int fib(int n) {
        if (n <= 1)
            return n;

        int t1 = 0, t2 = 1, nextTerm = 0;

        while (n > 1) {
            nextTerm = t1 + t2;
            t1 = t2;
            t2 = nextTerm;
            n--;
        }
        return t2;
    }
};

