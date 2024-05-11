class Solution {
public:
    int maxProfit(vector<int>& a) {
        
        int maxProfit=0;
        int minSoFar=a[0];
        
        for(int i = 0; i < a.size(); i++){
            minSoFar = min(minSoFar, a[i]);
            int Profit = a[i]-minSoFar;
            maxProfit = max(maxProfit,Profit); 
        }
        return maxProfit;
    }
};