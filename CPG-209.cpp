//Codeforces Round 993 (Div. 4) F. Easy Demon Problem
//https://codeforces.com/contest/2044/problem/F
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
int n, m, q, ntests, a[N], b[N], sum_x = 0, sum_y = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum_x += a[i];
    }
    for(int j = 1; j <= m; j++)
    {
        cin >> b[j];
        sum_y += b[j];
    }
    
    set<int> sx, sy;
    for(int i = 1; i <= n; i++)
        sx.insert(sum_x - a[i]);
    for(int j = 1; j <= m; j++)
        sy.insert(sum_y - b[j]);
    while(q--)
    {
        int x;
        cin >> x;
        bool check = false;
        for(int i = 1; i <= sqrt(abs(x)); i++)
        {
            if(x % i != 0)
                continue;
            
            if((sx.find(i) != sx.end() && sy.find(x / i) != sy.end()) || (sx.find(-i) != sx.end() && sy.find(x / -i) != sy.end()) || (sx.find(x / i) != sx.end() && sy.find(i) != sy.end()) || (sx.find(x / -i) != sx.end() && sy.find(-i) != sy.end()))
            {
                check = true;
                break;
            }
        }
        if(check)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    return 0;
}