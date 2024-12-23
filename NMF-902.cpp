//Codeforces Round 995 (Div. 3) C. Preparing for the Exam
//https://codeforces.com/contest/2051/problem/C

#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 7;
int n, m, k, ntests, a[N], q[N], res[N], sum[N], mark[N];

void solve()
{
    fill(res, res + N, 0);
    fill(sum, sum + N, 0);
    fill(mark, mark + N, 0);
    
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++)
        cin >> a[i];
    for(int i = 1; i <= k; i++)
    {
        cin >> q[i];
        mark[q[i]] = 1;
    }

    
    for(int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + mark[i];
    for(int i = 1; i <= m; i++)
    {
        if(sum[a[i] - 1] + sum[n] - sum[a[i]] == n - 1)
            res[i] = 1;
    }
    for(int i = 1; i <= m; i++)
        cout << res[i];
    cout << '\n';
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