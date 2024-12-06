//Codeforces Round 991 (Div. 3) A. Line Breaks
//https://codeforces.com/contest/2050/problem/A
#include <bits/stdc++.h>
using namespace std;

const int N = 57;
int ntests, n, m;
string s[N];

void solve()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> s[i];
    
    int res = 0, cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        if(cnt + s[i].size() <= m)
        {
            res++;
            cnt += s[i].size();
        }
        else
            break;
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