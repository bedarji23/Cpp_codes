#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define space << " " <<

using namespace std;

vector<int> v;

bool helper(int n, int sum)
{
    if (sum == 0 && n == 1)
    {
        return true;
    }
    if (sum == 0 && n != 1)
        return false;
    if (n == 1)
    {
        v.push_back(1);
        helper(n, sum - 1);
    }
    for (int i = sum; i >= 2; i--)
    {
        if (n % i == 0)
        {
            if (helper(n / i, sum - i))
            {
                v.push_back(i);
                return true;
            }
        }
    }
    if (n != 1)
        return false;
}

// vector<int> solve(int n, int t)
// {
//     v.clear();
//     if (!helper(n, 41))
//     {
//         cout << "Case #" << t
//              << ": -1" << endl;
//         return {};
//     }
//     return v;
// }

vector<int> solve(vector<int> arr, int diff)
{
    int n = arr.size();
    int cnt = 1, mc = 0;
    int start = 0, end = 0;
    vector<int> v;
    for (int i = 1; i < n; i++)
    {
        int currdiff = arr[i - 1] - arr[i];
        if (abs(currdiff) <= diff)
            cnt++;
        else
        {
            if (mc < cnt)
            {
                end = i - 1;
                v.clear();
                v.push_back(start);
                v.push_back(end);
                mc = cnt;
            }
            cnt = 1;
            start = i;
        }
    }
    if (mc < cnt)
    {
        end = n - 1;
        v.clear();
        v.push_back(start);
        v.push_back(end);
        mc = cnt;
    }
    return v;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int t;
    // cin >> t;
    // int tt = t;
    // while (t--)
    // {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int diff;
    cin >> diff;
    vector<int> res = solve(v, diff);
    cout << res[0] << " " << res[1] << endl;
    // }
    return 0;
}