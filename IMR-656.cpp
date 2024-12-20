//Codeforces Global Round 28 B. Kevin and Permutation
//https://codeforces.com/contest/2048/problem/B
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int ntests, n, k, ans[N];

void solve()
{
    fill(ans + 1, ans + 1 + n, 0);
    cin >> n >> k;
    int idx = 1;
    for(int i = k; i <= n; i += k)
    {
        ans[i] = idx;
        idx++;
    }
    for(int i = 1; i <= n; i++)
    {
        if(ans[i] == 0)
        {
            ans[i] = idx;
            idx++;
        }
    }
    for(int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
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