class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n=image.size();
        
        for(int i=0; i<n; i++){
            for(int j=0;j<(n+1)/2; j++){
                int temp = image[i][j]^1;
                image[i][j]=image[i][n-j-1]^1;
                image[i][n-j-1]=temp;
            }
        }
        return image;
    }
};