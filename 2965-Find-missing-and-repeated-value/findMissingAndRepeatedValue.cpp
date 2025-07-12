class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> freq(n*n + 1,0);
        vector<int>ans(2);

        for(int row = 0 ; row < n ; row++){
            for(int col = 0 ; col < n ; col++){
                int idx = grid[row][col];
                freq[idx]++; // storing frequency of each element
            }
        }

        for(int i = 1 ; i < freq.size() ; i++){
            if(freq[i] == 0){ // frequency = 0 means missing
                ans[1] = i;
            }
            else if (freq[i] > 1){// frequency = 2 means repeating  
                ans[0] = i;
            }
        }

        return ans;
    }
};
