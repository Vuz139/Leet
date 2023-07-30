#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s, p;
    cin >> s;
    cin >> p;

    int len1 = s.size();
    int len2 = p.size();
    if (len1 < 1 || len2 < 1)
    {
        cout << 0;
        return false;
    }

    vector<vector<bool>> dp(len1 + 1);
    for (int i = 0; i < len1; i++)
    {
        dp[i].resize(len2 + 1, false);
    }
    dp[0][0] = true;
    for (int i = 1; i < len2; i++)
    {
        if (p[i] == '*' && dp[0][i - 1])
        {
            dp[0][i + 1] = true;
        }
    }

    for (int i = 1; i < len1 + 1; i++)
    {
        char curS = s[i - 1];
        for (int j = 1; j < len2 + 1; j++)
        {
            char curP = p[j - 1];
            if (curS == curP || curP == '?')
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (curP == '*')
            {
                if (j - 2 < 0)
                {
                    dp[i][j] = true;
                }
                else
                {
                    char preCurP = p[j - 2];
                    if (preCurP != '?' && preCurP != curS)
                    {
                        dp[i][j] = dp[i][j - 2];
                    }
                    else
                    {
                        dp[i][j] = (dp[i][j - 2] || dp[i - 1][j - 1] || dp[i - 1][j]);
                    }
                }
            }
        }
    }
    cout << dp[len1][len2] << endl;
}