class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int mostwater = 0;
        int left = 0, right = n - 1;

        while (left < right) {
            int width = right - left;
            int area = width * min(height[left], height[right]);
            mostwater = max(mostwater, area);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return mostwater;
    }
};