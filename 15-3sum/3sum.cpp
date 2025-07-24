class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());  // Sort to apply two-pointer approach
        vector<vector<int>> Ans;

        for (int i = 0; i < n; i++) {
            
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int First = -nums[i];
            int second_idx = i + 1;
            int third_idx = n - 1;

            while (second_idx < third_idx) {
                int sum = nums[second_idx] + nums[third_idx];

                if (sum == First) {
                    
                    vector<int> triplet;
                    triplet.push_back(nums[i]);
                    triplet.push_back(nums[second_idx]);
                    triplet.push_back(nums[third_idx]);
                    Ans.push_back(triplet);

                    while (second_idx < third_idx && nums[second_idx] == nums[second_idx + 1]) second_idx++;


                    while (second_idx < third_idx && nums[third_idx] == nums[third_idx - 1]) third_idx--;

                    second_idx++;
                    third_idx--;
                }
                else if (sum < First) {
                    second_idx++;
                }
                else {
                    third_idx--;
                }
            }
        }

        return Ans;
    }
};
