#include <bits/stdc++.h>
using namespace std;

#define ll long long int

bool isPossible(vector<int> &arr, int a, int mid)
{

    ll sum = 0, painters = 1;
    for (ll i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum > mid)
        {
            sum = arr[i];
            painters++;
        }
        if (painters > a)
            return false;
    }

    return true;
}

int paint(int a, int b, vector<int> &c) // a = total painters , b = time taken to paint 1 unit
{

    int start = INT_MIN, mid, end = 0;
    ll res;
    for (int i : c)
    {
        start = max(start, i);
        end += i;
    }

    if (c.size() <= a)
        return start * b;

    res = start;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (isPossible(c, a, mid))
        {
            res = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }

    return res * b;
}
