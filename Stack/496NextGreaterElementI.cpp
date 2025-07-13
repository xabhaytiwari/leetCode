#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class NextGreaterElement {
    public:
        vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
            stack<int> decreasingNumbers;
            unordered_map<int, int> hashMP;
            vector<int> output;
            for(const int num : nums2) {
                while(!decreasingNumbers.empty() && num > decreasingNumbers.top()) {
                    hashMP[decreasingNumbers.top()] = num;
                    decreasingNumbers.pop();
                }
                decreasingNumbers.push(num);
            }
           
            while(!decreasingNumbers.empty()) {
                hashMP[decreasingNumbers.top()] = -1;
                decreasingNumbers.pop(); 
            }

            for(int i = 0; i < nums1.size(); i++) {
                output.push_back(hashMP[nums1[i]]);
            }

            return output;
        }
};

int main() {
    vector<int> nums1 = {4, 1, 2}, nums2 = {1, 3, 4, 2};
    NextGreaterElement solution;
    for(const int num : solution.nextGreaterElement(nums1, nums2)) {
        cout << num << ", ";
    }
    return 0;
}