#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int num1[n];
    int num2[m];
    for (int i = 0; i < n; i++)
    {
        cin >> num1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> num2[i];
    }
    if (n == 0)
    {
        if (m % 2 == 0)
        {
            return (num2[m / 2 - 1] + num2[m / 2]) / 2;
        }
        else
        {
            return num2[m / 2];
        }
    }
    if (m == 0)
    {
        if (n % 2 == 0)
        {
            return (num1[n / 2 - 1] + num1[n / 2]) * 1.0 / 2;
        }
        else
        {
            return num1[n / 2] * 1.0;
        }
    }
    int i = 0, j = 0;
    int k = 0;
    int num[n + m];
    while (i < n && j < m)
    {
        while (num1[i] < num2[j] && i < n)
        {
            num[k++] = num1[i];
            i++;
        }
        while (num2[j] < num1[i] && j < m)
        {
            num[k++] = num2[j];
            j++;
        }
    }
    while (i < n)
    {
        num[k++] = num1[i++];
    }
    while (j < m)
    {
        num[k++] = num2[j++];
    }
    if ((m + n) % 2 == 0)
    {
        return (num[(m + n) / 2 - 1] + num[(m + n) / 2]) * 1.0 / 2;
    }
    else
    {
        return num[(m + n) / 2] * 1.0;
    }
}