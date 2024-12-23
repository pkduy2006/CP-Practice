//Codeforces Round 995 (Div. 3) E. Best Price
//https://codeforces.com/contest/2051/problem/E

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
int ntests, n, k;
long long res, a[N], b[N];

void solve()
{
    res = 0;

    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cin >> b[i];
    
    set<long long> strictPrice;
    for(int i = 1; i <= n; i++)
    {
        strictPrice.insert(a[i]);
        strictPrice.insert(b[i]);
    }
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    int bid = 1, aid = 1;
    for(auto it = strictPrice.begin(); it != strictPrice.end(); it++)
    {
        int bid = n - (lower_bound(b + 1, b + 1 + n, *it) - b) + 1;
        int aid = n - (lower_bound(a + 1, a + 1 + n, *it) - a) + 1;
        if(bid - aid <= k)
        {
            long long cnt = (*it) * bid;
            res = max(res, cnt);
        }
    }

    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> ntests;
    while(ntests--)
        solve();
    
    return 0;
}