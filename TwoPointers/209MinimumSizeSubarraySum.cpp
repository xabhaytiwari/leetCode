#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MinimumSubarray {
    public:
        int minSubArrayLen(int target, vector<int> &nums) {
        int left = 0, sum = 0, minLen = INT_MAX;

        for (int right = 0; right < nums.size(); ++right) {
            sum += nums[right];

            while (sum >= target) {
                minLen = min(minLen, right - left + 1);
                sum -= nums[left++];
            }
        }

        return minLen == INT_MAX ? 0 : minLen;
        }
};

int main() {
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    MinimumSubarray solution;
    cout << solution.minSubArrayLen(7, nums);
    return 0;
}