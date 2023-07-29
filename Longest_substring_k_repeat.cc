#include <bits/stdc++.h>

using namespace std;

int find(string s, int k)
{
    if (s.size() < k)
        return 0;
    vector<int> fre(26, 0);
    int len = s.size();
    for (int c = 0; c < len; c++)
    {
        fre[s[c] - 'a']++;
    }
    int i = 0, j = 0;
    int valid = 1;
    int maxi = 0;
    for (j = 0; j < len; j++)
    {
        if (fre[s[j] - 'a'] < k)
        {
            maxi = max(maxi, find(s.substr(i, j), k));
            i = j + 1;
            valid = 0;
        }
    }
    if (valid)
        return s.size();
    return maxi;
}
int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    cout << find(s, k);
}