#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a;
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    set<vector<int>> rs;

    for (int i = 0; i < n; i++)
    {

        int j = i + 1, k = n - 1;
        while (j < k)
        {
            int sum = a[i] + a[j] + a[k];
            if (sum == 0)
            {
                rs.insert({a[i], a[j], a[k]});
                break;
            }
            else if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
        }
        while (i + 1 < n && a[i] == a[i + 1])
            i++;
    }
    vector<vector<int>> results;
    for (auto rrs : rs)
    {
        results.push_back(rrs);
    }
    return 1;
}