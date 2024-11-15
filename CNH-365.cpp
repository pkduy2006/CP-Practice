//Codeforces Round 987 (Div. 2) A. Penchick and Modern Monument
//https://codeforces.com/contest/2031/problem/A
#include <bits/stdc++.h>
using namespace std;

const int N = 57;
int ntests, n, a[N], cnt[N];

void solve()
{
    cin >> n;
    fill(cnt, cnt + N, 0);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    
    cout << n - *max_element(cnt + 1, cnt + 1 + n) << '\n';
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