//Codeforces Round 984 (Div. 3) B. Startup
//https://codeforces.com/contest/2036/problem/B
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 8;
int ntests, n, k, t[N];
pair<int, int> a[N];

void solve()
{
    int res = 0;
    cin >> n >> k;
    fill(t + 1, t + 1 + k, 0);
    for(int i = 1; i <= k; i++)
    {
        cin >> a[i].first >> a[i].second;
        t[a[i].first] += a[i].second;
    }

    sort(t + 1, t + 1 + k, greater<int>());

    for(int i = 1; i <= min(n, k); i++)
        res += t[i];
    
    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> ntests;
    while (ntests--)
        solve();
    
    return 0;
}