#include <iostream>
#include <cstring>

using namespace std;

int longestCommonSubsequence(string &a, string &b) {
    int lengthA = a.length();
    int lengthB = b.length();

    if (lengthA == 0 || lengthB == 0) {
        return 0;
    }

    int dp[lengthA+1][lengthB+1];
    memset(dp, 0, sizeof dp);

    /**
     * CT De Quy: dp[i][j] = dp[i-1][j-1] + 1 neu a[i-1] = b[j-1]
     *            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) neu a[i-1] != b[j-1]
     */
    for (int i = 1; i <= lengthA; i++) {
        for (int j = 1; j <= lengthB; j++) {
            if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[lengthA][lengthB];
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << longestCommonSubsequence(a, b) << endl;
}
