//Educational Codeforces Round 172 (Rated for Div. 2) A. Greedy Monocarp
//https://codeforces.com/contest/2042/problem/A
#include <bits/stdc++.h>
using namespace std;

const int N = 58;
int ntests, n, k, a[N];

void solve()
{
    int sum = 0;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    
    sort(a + 1, a + 1 + n);
    reverse(a + 1, a + 1 + n);
    
    int res = 0;
    for(int i = 1; i <= n; i++)
    {
        if(sum + a[i] > k)
        {   
            res = k - sum;
            break;
        }
        sum += a[i];
    }
    if(sum < k && res == 0)
        res += k - sum;
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