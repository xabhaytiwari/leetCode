#include <iostream>

using namespace std;

class ValidPalindrome {
    private:
        string removeNonAlphaNumeric(string s) {
            string goodString;
            for(int i = 0; i < s.length(); i++) {
                int check = s[i] - '0';
                if((check >= 17 && check <= 42) || (check >= 49 && check <= 74) || (check >= 0 && check <= 9)) { 
                if (isupper(s[i])) {
                s[i] = tolower(s[i]);
            }       
                goodString.push_back(s[i]);
                }
            }
            return goodString;
        }
    public:
        bool isPalindrome(string s) {
            string goodString = removeNonAlphaNumeric(s);
            int left = 0, right = goodString.length() - 1;
            while(left < right) {
                if(goodString[left++] != goodString[right--]) {
                    return false;
                }
            }
            return true;
        }

};

int main() {
    string s = "A man, a plan, a canal: Panama";
    ValidPalindrome solution;
    cout << solution.isPalindrome(s);
    return 0;
}