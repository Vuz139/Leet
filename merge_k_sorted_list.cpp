#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
};

vector<ListNode *> lists;
struct compare
{
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};

int main()
{
    int n;
    cin >> n;
    lists.resize(n + 1);
    int len;
    int temp_in;
    for (int i = 0; i < n; i++)
    {
        cin >> len;
        cin >> temp_in;
        ListNode *head = new ListNode(temp_in);
        lists[i] = head;
        for (int j = 1; j < len; j++)
        {
            cin >> temp_in;
            head->next = new ListNode(temp_in);
        }
    }

    priority_queue<ListNode *, vector<ListNode *>, compare> minHeap;
    for (int i = 0; i < n; i++)
    {
        ListNode *l = lists[i];
        while (l != NULL)
        {
            minHeap.push(l);
            l = l->next;
        }
    }
    ListNode *tail = new ListNode();
    ListNode *head = tail;
    while (!minHeap.empty())
    {
        ListNode *top = minHeap.top();
        minHeap.pop();
        tail->next = top;
        tail = top;
    }

    return 1;
}