//Codeforces Round 992 (Div. 2) A. Game of Division
//https://codeforces.com/contest/2040/problem/A
#include <bits/stdc++.h>
using namespace std;

const int N = 108;
int ntests, n, k, a[N];

void solve()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    
    int res = -1;
    for(int i = 1; i <= n; i++)
    {
        bool check = true;
        for(int j = 1; j <= n; j++)
        {
            if(i == j)
                continue;
            
            if(abs(a[i] - a[j]) % k == 0)
            {
                check = false;
                break;
            }
        }
        if(check)
            res = i;
    }

    if(res == -1)
        cout << "NO" << '\n';
    else
        cout << "YES" << '\n' << res << '\n';
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