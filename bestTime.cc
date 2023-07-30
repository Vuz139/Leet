#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> prices;
    prices.resize(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    priority_queue<int> pq;
    int maxProfit = 0;
    pq.push(prices[0]);
    for (int i = 1; i < n; i++)
    {
        int profit = prices[i] - pq.top();
        maxProfit = maxProfit < profit ? profit : maxProfit;
        pq.push(prices[i]);
    }
    cout << maxProfit;
}