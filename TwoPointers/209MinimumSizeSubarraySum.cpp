#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MinimumSubarray {
    public:
        int minSubArrayLen(int target, vector<int> &nums) {
            sort(nums.begin(), nums.end());
            int right = nums.size() - 1, left = nums.size() - 2;
            int minLen = INT_MAX, sum;
            while(left < right) {
                sum += nums[left] + nums[right];
                if(sum >= target) {
                    minLen = min(minLen, right - left + 1);
                    break;
                } else {
                    left--;
                }
            }
            return minLen;
        }
};

int main() {
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    MinimumSubarray solution;
    cout << solution.minSubArrayLen(7, nums);
    return 0;
}