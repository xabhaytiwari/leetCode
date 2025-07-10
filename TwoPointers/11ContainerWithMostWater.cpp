#include <iostream>
#include <vector>
using namespace std;

class WaterContainer {
    public:
        int maxArea(vector<int> height) {
            int left = 0, right = height.size() - 1, maxArea = 0;
            while(left < right) { //Kyunki container ke lye at least 1 unit width
                maxArea = max(maxArea, (right - left) * min(height[left], height[right]));
                if(height[left] < height[right]) {
                    left++;
                } else {
                    right --;
                }
            }
            return maxArea;
        }
};

int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    WaterContainer solution;
    cout << solution.maxArea(height);
    return 0;
}