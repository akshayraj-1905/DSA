class Solution {
private:
    bool binarysearch(vector<vector<int>>& matrix, int sr, int ec, int target) { 
        int start = 0;
        int end = ec;

        while(start <= end) {
            int mid = start + (end - start) / 2;

            if(matrix[sr][mid] == target) {
                return true;
            }

            if(matrix[sr][mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return false;
    }

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) { 
        int ec = matrix[0].size() - 1;

        if(matrix.size() == 1) { //only one row exist 
            return binarysearch(matrix, 0, ec, target);
        }
      
        // Row-wise searching
        for(int sr = 0 ; sr < matrix.size() ; sr++) {
            if(target >= matrix[sr][0] && target <= matrix[sr][ec]) {
                return binarysearch(matrix, sr, ec, target);
            }
        }

        return false;
    }
};
