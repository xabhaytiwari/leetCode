#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class ReverseString {
    public:
        void reverseString(vector<char> &s) {
            int left = 0, right = s.size() - 1;
            while(left < right) { //Kyunki same ka reverse karne ka koi sense nahin banta
                swap(s[left++], s[right--]);
            }
        }

};

int main() {
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    ReverseString solution;
    solution.reverseString(s);
    for(const char ch : s) {
        cout<< ch;
    }
    return 0;
}