#include <iostream>
#include <vector>
using namespace std;

class TwoSum {
    public:
        vector<int> twoSum(vector<int>& numbers, int target) {
            int left = 0, right = numbers.size() - 1;
            while(left < right) { // Kyunki ek element at most ek baar use ho sakta hai
                int sum = numbers[left] + numbers[right];
                if(sum == target) return {left + 1, right + 1}; //Kyunki 1-Based Indexing hai
                else if (sum < target) left++;
                else right--;
            }
            return {};
        }
};

int main() {
    vector<int> numbers = {2, 7, 11, 15};
    TwoSum solution;
    for(int output : solution.twoSum(numbers, 9)) {
        cout << output << " ";
    }
    return 0;
}