//Codeforces Global Round 28 D. Kevin and Competition Memories 
//https://codeforces.com/contest/2048/problem/D
#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 7;
int ntests, n, m, a[N], b[N], d[N];

void solve()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int j = 1; j <= m; j++)
        cin >> b[j];
    
    vector<int> c;
    for(int i = 2; i <= n; i++)
    {
        if(a[1] < a[i])
            c.push_back(a[i]);
    }
    c.push_back(a[1]);
    sort(c.begin(), c.end());
    sort(b + 1, b + 1 + m);
    //for(int i = 0; i < c.size(); i++)
     //   cout << c[i] << ' ';
   // cout << '\n';
    
    for(int i = 1; i <= m; i++)
    {
        auto it = lower_bound(c.begin(), c.end(), b[i]);
        if(it != c.end() && it != c.begin())
            d[i] = c.size() - (it - c.begin());
        else
            d[i] = 0;
    }
    //for(int i = 1; i <= m; i++)
    //    cout << d[i] << ' ';
    //cout << '\n';
    sort(d + 1, d + 1 + m);
    for(int k = 1; k <= m; k++)
    {
        long long res = 0;
        for(int i = k; i <= m; i += k)
        {
            if(d[i] != c.size())
                res += d[i];
            res++;
        }
        cout << res << ' '; 
    }
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