#include <iostream>
#include <vector>
// #include <unordered_set> Multiple occurences ho sakte hain
#include <unordered_map>
#include <algorithm>
using namespace std;

class ThreeSum {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
             sort(nums.begin(), nums.end());
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]--;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < nums.size(); j++) {
                count[nums[j]]--;
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int target = -(nums[i] + nums[j]);
                if (count[target] > 0) {
                    res.push_back({nums[i], nums[j], target});
                }
            }

            for (int j = i + 1; j < nums.size(); j++) {
                count[nums[j]]++;
            }
        }

        return res;
        }
};

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    ThreeSum solution;
    for(const auto &list : solution.threeSum(nums)) {
        for(const int num : list) {
            cout << num << ", ";
        }
    }
    return 0;
}