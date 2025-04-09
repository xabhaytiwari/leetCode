#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int fib(int n, vector<int>& dp) {
    if(n <= 1) return n;

    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    return dp[n];
}

int main() {
    int n;
    cin >> n;

    vector<int> dp(n+1, -1);

    cout << fib(n, dp);
    return 0;
}