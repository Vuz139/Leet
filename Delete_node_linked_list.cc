#include <bits/stdc++.h>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int main()
{

    int n;
    cin >> n;
    int x;
    cin >> x;
    ListNode *l = new ListNode(x);
    ListNode *curr = l;

    for (int i = 1; i < n; i++)
    {
        cin >> x;
        ListNode *temp = new ListNode(x);
        curr->next = temp;
        curr = curr->next;
    }
    int node;
    cin >> node;
    if (l->val == node)
        l = l->next;
    else
    {
        curr = l;
        while (curr->next->val != node && curr != NULL)
            curr = curr->next;
        ListNode *temp_next = curr->next->next;
        curr->next->next = NULL;
        curr->next = temp_next;
    }
    while (l != NULL)
    {
        cout << l->val << " ";
        l = l->next;
    }
}