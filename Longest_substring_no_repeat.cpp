#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int a[255];
    int len = s.length();
    int curr_len = 0;
    int max_len = -1;
    int curr_loop;
    for (int i = 0; i < len; i++)
    {
        curr_loop = i + 1;
        curr_len = 1;
        a[s[i]] = curr_loop;
        for (int j = i + 1; j < len; j++)
        {
            if (a[s[j]] != curr_loop)
            {
                curr_len++;
                a[s[j]] = curr_loop;
            }
            else
            {
                max_len = max(max_len, curr_len);
                break;
            }
        }
        max_len = max(max_len, curr_len);
    }
    cout << max_len;
    return 1;
}