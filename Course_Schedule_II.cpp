#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> edges;
queue<int> st;
queue<int> q;
vector<int> visited;

vector<int> solve(int numCourses, vector<vector<int>> &prerequisites)
{
    edges.resize(numCourses);
    for (int i = 0; i < numCourses; i++)
    {
        edges[i].resize(numCourses, 0);
    }
    vector<int> node_in(numCourses);
    for (vector<int> e : prerequisites)
    {
        edges[e[1]][e[0]] = 1;
        node_in[e[0]] = 1;
    }
    for (int i = 0; i < numCourses; i++)
    {
        if (!node_in[i])
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        st.push(top);
        for (int i = 0; i < numCourses; i++)
        {
            if (edges[top][i])
            {
                edges[top][i] = 0;
                for (int j = 0; j < numCourses; j++)
                {
                    if (edges[j][i])
                        break;
                    st.push(i);
                }
            }
        }
    }
    for (int i = 0; i < numCourses; i++)
    {
        for (int j = 0; j < numCourses; j++)
        {
            if (edges[j][i])
                return vector<int>();
        }
    }
    vector<int> res;
    while (!st.empty())
    {
        res.push_back(st.front());
        st.pop();
    }
    return res;
}