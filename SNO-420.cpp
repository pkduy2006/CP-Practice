//Codeforces Round 988 (Div. 3) B. Intercepted Inputs
//https://codeforces.com/contest/2037/problem/B
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 8;
int ntests, a[N], k, m, n, res_m, res_n, mark[N];

void solve()
{
    fill(mark, mark + N, 0);
    cin >> k;
    for(int i = 1; i <= k; i++)
    {
        cin >> a[i];
        mark[a[i]]++;
    }

    for(int i = 1; i <= k; i++)
    {
        if((k - 2) % a[i] != 0)
            continue;
        
        mark[a[i]]--;
        if(mark[(k - 2) / a[i]] >= 1)
        {
            res_n = a[i];
            res_m = (k - 2) / a[i];
        }
        mark[a[i]]++;
    }

    cout << res_n << ' ' << res_m << '\n';
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