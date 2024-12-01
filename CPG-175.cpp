//Rayan Programming Contest 2024 - Selection (Codeforces Round 989, Div. 1 + Div. 2) B. Rakhsh's Revival
//https://codeforces.com/contest/2034/problem/B
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 8;
int ntests, n, m, k, sum[N];
string s;

void solve()
{
    cin >> n >> m >> k >> s;
    
    for(int i = 0; i < n; i++)
        sum[i] = sum[i - 1] + (s[i] - '0');
    
    int res = 0;
    for(int i = m - 1; i < n; i++)
    {
        sum[i] = sum[i - 1] + (s[i] - '0');
        if(sum[i] - sum[i - m] == 0)
        {
            sum[i]++;
            for(int j = 0; j < k && i + j < n; j++)
                s[j + i] = '1';
            res++;
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
    while (ntests--)
        solve();
    
    return 0;
}