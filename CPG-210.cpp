//Educational Codeforces Round 173 (Rated for Div. 2) C. Sums on Segments
//https://codeforces.com/contest/2043/problem/C

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
const int INF = 1e9 + 7;
int ntests, n, a[N], sum[N], maxSum[N], minSum[N];

int findMax(int l, int r)
{
    int maxCurrent = a[l], maxGlobal = a[l];
    for(int i = l + 1; i <= r; i++)
    {
        maxCurrent = max(a[i], maxCurrent + a[i]);
        maxGlobal = max(maxGlobal, maxCurrent);
    }

    return maxGlobal;
}

int findMin(int l, int r)
{
    int minCurrent = a[l], minGlobal = a[l];
    for(int i = l + 1; i <= r; i++)
    {
        minCurrent = min(a[i], minCurrent + a[i]);
        minGlobal = min(minGlobal, minCurrent);
    }

    return minGlobal;
}

void solve()    
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    
    set<int> res;
    res.insert(0);
    if(n == 1)  
        res.insert(a[1]);
    else
    {
        int pos = 0;
        for(int i = 1; i <= n; i++)
        {
            if(a[i] != 1 && a[i] != -1)
            {
                pos = i;
                break;
            }
        }

        if(pos == 1)
        {
            int cnt = 0;
            for(int i = 1; i <= n; i++)
            {
                cnt += a[i];
                res.insert(cnt);
            }
            int maxVal = findMax(2, n), minVal = findMin(2, n);
            for(int i = minVal; i <= maxVal; i++)
                res.insert(i);
        }
        else if(pos == n)
        {
            int cnt = 0;
            for(int i = n; i >= 1; i--)
            {
                cnt += a[i];
                res.insert(cnt);
            }
            int maxVal = findMax(1, n - 1), minVal = findMin(1, n - 1);
            for(int i = minVal; i <= maxVal; i++)
                res.insert(i);
        }
        else
        {
            int cnt = a[pos];
            res.insert(a[pos]);
            for(int i = pos - 1; i >= 1; i--)
            {
                cnt += a[i];
                res.insert(cnt);
            }
            cnt = a[pos];
            for(int i = pos + 1; i <= n; i++)
            {
                cnt += a[i];
                res.insert(cnt);
            }
            int misl = a[pos - 1], sl = a[pos - 1], masl = a[pos - 1];
            for(int i = pos - 2; i >= 1; i--)
            {
                sl += a[i];
                misl = min(misl, sl);
                masl = max(masl, sl);
            }
            int misr = a[pos + 1], sr = a[pos + 1], masr = a[pos + 1];
            for(int i = pos + 2; i <= n; i++)
            {
                sr += a[i];
                misr = min(misr, sr);
                masr = max(masr, sr);
            }
            for(int i = misl + a[pos] + misr; i <= masl + a[pos] + masr; i++)
                res.insert(i);
            int mavl = findMax(1, pos - 1), mivl = findMin(1, pos - 1);
            for(int i = mivl; i <= mavl; i++)
                res.insert(i);
            int mavr = findMax(pos + 1, n), mivr = findMin(pos + 1, n);
            for(int i = mivr; i <= mavr; i++)
                res.insert(i);
        }
    }

    cout << res.size() << '\n';
    for(auto it = res.begin(); it != res.end(); it++)
        cout << *it << ' ';
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