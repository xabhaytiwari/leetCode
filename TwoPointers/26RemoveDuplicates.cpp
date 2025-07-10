#include <iostream>
#include <vector>
using namespace std;

class RemoveDupliactes {
    public:
        int removeDuplicates(vector<int> &nums) {
            int slow = 1, fast = 1; 
            for(fast = 1; fast < nums.size(); fast++) {
                if(nums[fast] != nums[fast - 1]) {
                    nums[slow++] = nums[fast];
                }
            }
            return slow;
        }
};

int main() {
    vector<int> nums = {1, 1, 2};
    RemoveDupliactes solution;
    cout << solution.removeDuplicates(nums);
    return 0;
}