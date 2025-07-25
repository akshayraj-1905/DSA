class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n ; i++) {
            // Skip duplicate 'i'
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n ; j++) {
                // Skip duplicate 'j'
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int l = j + 1;
                int r = n - 1;

                while (l < r) {
                    long long sum = 1LL * nums[i] + nums[j] + nums[l] + nums[r];

                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});

                        // Skip duplicates for 'l'
                        while (l < r && nums[l] == nums[l + 1]) l++;
                        // Skip duplicates for 'r'
                        while (l < r && nums[r] == nums[r - 1]) r--;

                        l++;
                        r--;
                    }
                    else if (sum < target) {
                        l++;
                    }
                    else {
                        r--;
                    }
                }
            }
        }

        return ans;
    }
};
