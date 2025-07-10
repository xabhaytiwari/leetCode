#include <iostream>
#include <unordered_set>
using namespace std;

class LongestSubstring {
    public:
        int lengthOfLongestSubstring(string s) {
            unordered_set<char> seen;
            int left = 0, right = 0, maxLen = 1;
            for(right = 0; right < s.length(); right++) { // A character itself can be the longest substring
                while(seen.count(s[right])) {
                    seen.erase(s[left++]); 
                }
                seen.insert(s[right]);
                maxLen = max(maxLen, right - left + 1);
            } 
            return maxLen;
        }
};
int main() {
    string s = "abcabcbb";
    LongestSubstring solution;
    cout << solution.lengthOfLongestSubstring(s) << endl;
    return 0;
}